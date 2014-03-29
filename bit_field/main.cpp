/*!
 * \brief Uses a bit in an integer field to store a bool flag.
 *
 * \author Alejandro Mallea <janoma@gmail.com>
 *
 * \copyright The MIT License
 */

#include <cstdint>
#include <iostream>
#include <limits>

#include <boost/assert.hpp>

class MyClass
{
public:
    explicit
    MyClass(int n)
    : mSomeInt(n), mID(0)
    {
        BOOST_ASSERT(flag1() == false);
    }

    int someInt() const
    {
        return mSomeInt;
    }

    void setSomeInt(int val)
    {
        mSomeInt = val;
    }

    bool flag1() const
    {
        return mID & FIELD1_BIT;
    }

    void setFlag1(bool val)
    {
        if (val)
        {
            mID |= FIELD1_BIT;
        }
        else
        {
            mID &= ~FIELD1_BIT;
        }
    }

    bool flag2() const
    {
        return mID & FIELD2_BIT;
    }

    void setFlag2(bool val)
    {
        if (val)
        {
            mID |= FIELD2_BIT;
        }
        else
        {
            mID &= ~FIELD2_BIT;
        }
    }

    uint32_t
    ID() const
    {
        return mID >> FIELDBITS;
    }

    void
    setID(uint32_t id)
    {
        BOOST_ASSERT(id < std::numeric_limits<uint32_t>::max() >> FIELDBITS);

        mID &= ~REST_OF_BITS;
        mID |= (id << FIELDBITS);
    }

private:
    int mSomeInt;
    uint32_t mID;

    uint32_t const FIELDBITS = 2;
    unsigned char const FIELD1_BIT = 1;
    unsigned char const FIELD2_BIT = 2;
    unsigned char const REST_OF_BITS = 4 | 8 | 16 | 32 | 64 | 128;
};

inline std::ostream&
operator<<(std::ostream& out, MyClass const& a)
{
    out << "someInt: " << a.someInt() << "\tflag1: " << (a.flag1() ? "true" : "false") << "\tflag2: " << (a.flag2() ? "true" : "false") << "\tID: " << a.ID() << std::endl;
    return out;
}

int main()
{
    MyClass a(3);
    std::cout << a;
    a.setFlag1(true);
    std::cout << a;
    a.setFlag1(false);
    std::cout << a;
    a.setFlag2(true);
    a.setID(7);
    std::cout << a;
    a.setFlag1(true);
    a.setFlag2(false);
    std::cout << a;
    // This is the max value that we can give to mID
    std::cout << "Setting ID to " << (std::numeric_limits<uint32_t>::max() >> 2) - 1 << " ..." << std::endl;
    a.setID((std::numeric_limits<uint32_t>::max() >> 2) - 1);
    std::cout << a;
    // This should give an error
    a.setID(std::numeric_limits<uint32_t>::max() >> 2);
}
