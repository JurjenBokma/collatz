#include "collatz.ih"

void spy_collatz(std::ostream &outs, collatz_t n)
{
    while (true)
    {
        outs << n << ' ';
        if (n == 1)
            break;
        n = collatz(n);
    }
}
