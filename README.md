# principles_and_practice_using_cpp

## Key points
1. chapter 5 generate_rand_nums() function, use C++11 random library. to find more detail, the following links can be helpful:
   1. Actually, this is the example that using in my code. [Generate random numbers using C++11 random library](https://stackoverflow.com/questions/19665818/generate-random-numbers-using-c11-random-library)
   2. [Cpp reference -- Pseudo-random number generation](https://en.cppreference.com/w/cpp/numeric/random)
   3. [Cpp reference -- srand](https://www.cplusplus.com/reference/cstdlib/srand/)
2. chapter 9 mentioned that you can also use `struct` for a data structure
   1. here's a link to discuss the diff between `class` and `struct`: [Function for C++ struct](https://stackoverflow.com/questions/13125944/function-for-c-struct)
3. you'd better use `scoped enumeration` instead of using `plain enumeration`, which means:
   1. `enum class` is better than `enum` declaration
4. code like below, `static` will let `dd` created only once:
```c++
const Date& default_date() {
    static Date dd{Year{2001}, Month::jan, 1};

    return dd;
}
```

## issues

- [CLion gets wrong CMAKE_OSX_SYSROOT value](https://youtrack.jetbrains.com/issue/CPP-20766)
- [ofstream doesn't flush](https://stackoverflow.com/questions/3113229/ofstream-doesnt-flush)