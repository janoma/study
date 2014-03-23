/*!
 * \brief Uses boost disjoint_sets with a custom class.
 *
 * \author Alejandro Mallea <janoma@gmail.com>
 *
 * \copyright The MIT License
 */

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <vector>

#include <boost/pending/disjoint_sets.hpp>
#include <boost/pending/property.hpp>

class Element
{
public:
    explicit
    Element(int n) : mSomeInt(n) { }

    int someInt() const { return mSomeInt; }

    // The following class members are specific for the disjoint_sets
    // implementation
    size_t dsID;
    size_t dsRank;
    size_t dsParent;

private:
    int mSomeInt;
};

inline bool
operator==(Element const& lhs, Element const& rhs)
{
    return lhs.someInt() == rhs.someInt();
}

inline bool
operator!=(Element const& lhs, Element const& rhs)
{
    return ! operator==(lhs, rhs);
}

class Parent
{
public:
    Parent(std::vector<Element>& e) : mElements(e) { }
    std::vector<Element>& mElements;
};

class Rank
{
public:
    Rank(std::vector<Element>& e) : mElements(e) { }
    std::vector<Element>& mElements;
};

template <>
struct boost::property_traits<Rank*>
{
    typedef size_t value_type;
};

inline Element const&
get(Parent* pa, Element const& k)
{
    return pa->mElements.at(k.dsParent);
}

inline void
put(Parent* pa, Element k, Element const& val)
{
    pa->mElements.at(k.dsID).dsParent = val.dsID;
}

inline size_t const&
get(Rank*, Element const& k)
{
    return k.dsRank;
}

inline void
put(Rank* pa, Element k, size_t const& val)
{
    pa->mElements.at(k.dsID).dsRank = val;
}

void
printElements(std::vector<Element>& elements)
{
    std::cout << "Elements:            ";
    for (size_t i = 0; i < elements.size(); ++i)
    {
        std::cout << std::setw(4) << elements[i].someInt();
    }
    std::cout << std::endl;
    std::cout << "Set representatives: ";
    for (size_t i = 0; i < elements.size(); ++i)
    {
        std::cout << std::setw(4) << elements[i].dsParent;
    }
    std::cout << std::endl;
    std::cout << "ID                 : ";
    for (size_t i = 0; i < elements.size(); ++i)
    {
        std::cout << std::setw(4) << elements[i].dsID;
    }
    std::cout << std::endl;
}

inline bool
compareByParent(Element const& lhs, Element const& rhs)
{
    return lhs.dsParent < rhs.dsParent;
}

inline bool
compareBySomeInt(Element const& lhs, Element const& rhs)
{
    return lhs.someInt() < rhs.someInt();
}

int main()
{
    std::vector<Element> elements;
    elements.reserve(30);
    for (size_t i = 0; i < elements.capacity(); ++i)
    {
        elements.push_back(Element(rand() % 90));
    }

    for (size_t i = 0; i < elements.size(); ++i)
    {
        elements[i].dsID = i;
    }

    Rank rank(elements);
    Parent parent(elements);

    boost::disjoint_sets<Rank*, Parent*> sets(&rank, &parent);

    for (size_t i = 0; i < elements.size(); ++i)
    {
        sets.make_set(elements.at(i));
    }

    for (size_t i = 0; i < elements.size(); ++i)
    {
        // Union between this element and one randomly chosen from the rest
        size_t j = rand() % elements.size();
        sets.union_set(elements[i], elements[j]);
    }

    std::cout << "Found " << sets.count_sets(elements.begin(), elements.end()) << " sets:" << std::endl;
    printElements(elements);

    sets.compress_sets(elements.begin(), elements.end());

    std::cout << std::endl << "After path compression:" << std::endl;
    printElements(elements);

    std::sort(elements.begin(), elements.end(), compareByParent);

    std::cout << std::endl << "After path compression and sorting by parent:" << std::endl;
    printElements(elements);

    std::cout << std::endl << "Now we can iterate through all elements of each set separately using the indices:" << std::endl;
    {
        size_t first = 0;
        while (first < elements.size())
        {
            size_t currentParent = elements.at(first).dsParent;
            size_t last = first;
            while (last < elements.size() && elements.at(last).dsParent == currentParent)
            {
                ++last;
            }
            std::cout << "\tRange: [" << first << "," << last << "). Sorted elements: ";
            for (size_t i = first; i < last; ++i)
            {
                std::cout << elements.at(i).someInt() << " ";
            }
            std::cout << std::endl;
            first = last;
        }
    }

    std::cout << std::endl << "Alternative, using iterators:" << std::endl;
    {
        std::vector<Element>::iterator first = elements.begin();
        while (first != elements.end())
        {
            std::vector<Element>::iterator last = std::upper_bound(first, elements.end(), *first, compareByParent);
            std::sort(first, last, compareBySomeInt);
            std::cout << "\tSorted set: ";
            for (std::vector<Element>::iterator it = first; it != last; ++it)
            {
                std::cout << it->someInt() << " ";
            }
            std::cout << std::endl;
            first = last;
        }
    }
}
