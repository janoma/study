#include <iostream>
#include <set>
#include <functional>

struct Lol
{
    explicit Lol(std::string) { }
    bool operator<(Lol const&) const { return false; }
};

typedef std::set<Lol, std::less<Lol> > setLess;
typedef std::set<Lol, std::greater<Lol> > setGreater;

int main()
{
    setLess sl;
    setGreater sg;
    // This comparison should not even compile
    std::cout << (sl.begin() == sg.begin()) << std::endl;
}

