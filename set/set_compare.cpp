#include <iostream>
#include <set>

struct T
{
    int var1;
    int var2;

    explicit
    T (int v1, int v2)
    : var1(v1), var2(v2)
    {
    }
};

struct Comp1
{
    bool
    operator()(T const& lhs, T const& rhs) const
    {
        return lhs.var1 < rhs.var1;
    }
};

struct Comp2
{
    bool
    operator()(T const& lhs, T const& rhs) const
    {
        return lhs.var2 < rhs.var2;
    }
};

int main()
{
    typedef std::set<T, Comp1> Set1;
    typedef std::set<T, Comp2> Set2;

    Set1 s1;
    Set2 s2;

    s1.insert(T(7, 12));
    s2.insert(T(10, 25));

    // This assignment should be invalid. Set1::iterator is of a different
    // nature as Set2::iterator
    Set1::iterator it1 = s2.begin();

    // After this invalid assignment, the behavior is undefined.
    // In particular, a loop like
    //     while(it1 != s1.end()) { ++it1; }
    // could be infinite.
    // Here we to stop it with a counter,
    // though in some systems it will fail with a segmentation fault after the
    // second iteration.
    int count = 0;
    while (it1 != s1.end() && count++ < 10)
    {
        std::cout << '(' << it1->var1 << ',' << it1->var2 << ')' << std::endl;
        ++it1;
    }
}
