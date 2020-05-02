#include <iostream>
#include <set>
#include <functional>

struct Lol
{
    explicit Lol(std::string) { }
    bool operator<(Lol const&) const { return false; }
};

int main()
{
    std::set<Lol, std::less<Lol>> sl;
    std::set<Lol, std::greater<Lol>> sg;

    // This comparison shouldn't even compile at all
    std::cout << std::boolalpha << (sl.begin() == sg.begin()) << std::endl;
}

