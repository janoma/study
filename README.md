Snippets of code resulting of studying specific data structures, algorithms and
general coding techniques.

## Requirements (sort of)
[GCC](https://gcc.gnu.org/) supporting `C++17`. Using
[Buck](https://buck.build/) to build, run and test.

## List of snippets

### Constructor
Clarifies which constructor is being called with different methods.

    buck run //constructors:constructors

### Set
A couple of examples showing a problem in how `std::set` is implemented by GNU's
[libstdc++](http://gcc.gnu.org/libstdc++/). I'm not sure whether this merits a
bug report, since I read somewhere that there is a design choice behind it, but
it's certainly worth being aware of it.

The problem is related to iterators for two *different* sets of type
`std::set<T, C1>` and `std::set<T, C2>`, where the compare objects are
different.

    buck run //set:set_compare
    buck run //set:set_iterator

### Variadic
Just trying to learn variadic templates. Some examples with parameter packs.

    buck test //variadic:
