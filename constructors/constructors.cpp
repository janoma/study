#include <cassert>
#include <iostream>
#include <initializer_list>
#include <iterator>
#include <string>
#include <utility>

class Point
{
public:
    Point()
        : x(0), y(0)
    {
        std::cout << "Using default constructor " << *this << std::endl;
    }

    explicit
    Point(int _x, int _y)
        : x(_x), y(_y)
    {
        std::cout << "Using explicit constructor " << *this << std::endl;
    }

    Point(std::initializer_list<int> coords)
    {
        assert(coords.size() == 2);
        x = *std::begin(coords);
        y = *std::rbegin(coords);
        std::cout << "Using initializer_list constructor " << *this << std::endl;
    }

    Point(Point && other)
        : x(std::move(other.x)), y(std::move(other.y))
    {
        std::cout << "Using move constructor " << *this << std::endl;
    }

    Point(Point const& other)
        : x(other.x), y(other.y)
    {
        std::cout << "Using copy constructor " << *this << std::endl;
    }

    Point&
    operator=(Point const& other)
    {
        x = other.x;
        y = other.y;
        std::cout << "Using copy assignment " << *this << std::endl;
        return *this;
    }

    Point&
    operator=(Point && other)
    {
        x = std::move(other.x);
        y = std::move(other.y);
        std::cout << "Using move assignment " << *this << std::endl;
        return *this;
    }

    friend std::ostream&
    operator<<(std::ostream& out, Point const& p)
    {
        return out << "(" << p.x << "," << p.y << ")";
    }

private:
    int x;
    int y;
};

int main()
{
    Point p0;
    Point p1(3, 7);
    Point p2 = p1;
    p2 = p1;
    Point p3(p2);
    Point p4(std::move(p3));
    p2 = std::move(p4);
    p2 = Point(10, 11);
    p2 = {20, 21};
}
