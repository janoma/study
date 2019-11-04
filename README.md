# Study
Snippets of code resulting of studying specific data structures, algorithms and
general coding techniques.

## Requirements (sort of)
Generally speaking, I rely on GCC, and I usually add something from [boost](http://www.boost.org/) here and there. For sanity checks and comparisons, I also use [clang](http://clang.llvm.org/).

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

### Bit field
An attempt to save as much memory as possible by storing a `bool` as a bit in
some other numeric field, and making ad-hoc *getters* and *setters* so the
change is transparent to the outside. The experiment was actually made with two
`bool`s so the modifications to the code could be appreciated.

### Cache
A little experiment to show the effects of processor cache. Credit to [Igor
Ostrovsky](http://igoro.com/archive/gallery-of-processor-cache-effects/) for his
article on Processor Cache Effects.
