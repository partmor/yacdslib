# yacdslib - Yet Another C Data Structure Library

This project is just meant for satisfying my personal curiosity of learning to
program in C. 

Instead of just creating on-the-go a bunch of random poorly-tested C executables,
to push myself a bit harder I've decided to create a *proper* library, paying attention
to creating a reasonable API and writing automated unit tests.

And what a better way to do that than by implementing a bunch of beloved data structures
like linked lists, dynamic arrays, hash maps, and so on.

I don't guarantee a total absence of poor design decisions, lack of idiomatic taste or 
other reprehensible flaws; but who cares, it's about the journey.

## Building

From the root of the repo:

```
mkdir build && cd build # create dir for build outputs
cmake .. # generate configs (from within build/ dir)
make # build
make test # run unit tests
```

### Dependencies

+ CMake
+ [Check](https://github.com/libcheck/check) (unit-testing framework)