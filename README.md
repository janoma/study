# study
Snippets of code resulting of studying specific data structures, algorithms and
general coding techniques.

## Requirements (sort of)
Not really mandatory, but I use the following tools, and perhaps more and I'm
forgetting. It's likely that I'm using the latest version of everything, though
my code is probably compatible with previous versions as well.
* [vim](http://www.vim.org/)
* [YouCompleteMe](https://github.com/Valloric/YouCompleteMe)
* [clang](http://clang.llvm.org/)
* [boost](http://www.boost.org/)

## List of snippets

### Disjoint sets
An implementation of `boost::disjoint_sets` with a generic class and a single
`std::vector` as container, with comments explaining how to use it. It is partly
personal study for an implementation I had to do for my job, and partly an
answer to [this
question](http://stackoverflow.com/questions/4134703/understanding-boostdisjoint-sets)
in Stack Overflow.

### Set
A couple of examples showing a problem in how `std::set` is implemented by GNU's
[libstdc++](http://gcc.gnu.org/libstdc++/). I'm not sure whether this merits a
bug report, since I read somewhere that there is a design choice behind it, but
it's certainly worth being aware of it.

The problem is related to iterators for two *different* sets of type
`std::set<T, C1>` and `std::set<T, C2>`, where the compare objects are
different.
