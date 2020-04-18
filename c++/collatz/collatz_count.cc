#include "collatz.ih"

size_t collatz_count(collatz_t n)
{
    size_t count = 0;
    while (n != 1)
    {
        n = collatz(n);
        ++count;
    }
    return count;
}
