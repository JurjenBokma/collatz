#ifndef def_collatz_h
#define def_collatz_h

#include <cstddef>
#include <iosfwd>

typedef unsigned long long int collatz_t;

/// The Collatz function itself.
inline constexpr collatz_t collatz(collatz_t const n)
{
    return
        (n % 2 == 0) // See if n is divisble by 2.
        ?            // If so,
        n / 2        // return half the value;
        :            // otherwise,
        3 * n + 1    // multiply by 3 and add 1.
        ;
}    

/// The Collatz count function.
size_t collatz_count(collatz_t n);

/// Computes Collatz count while echoing intermediate values to screen.
void spy_collatz(std::ostream &outs, collatz_t n);

struct Cpair
{
    collatz_t number;
    size_t count;
};

/// Return the pair with the highest Collatz count.
Cpair max(Cpair const &lhs, Cpair const &rhs);

/// Find the number with the highest Collatz count.
Cpair find_winner(collatz_t begin, collatz_t end);

/// Alternative so Python doesn't have to deal with a Cpair.
collatz_t find_winner2(collatz_t begin, collatz_t end);

/// Output short report on range and winner.
void report(std::ostream &outs, collatz_t range_first, collatz_t range_last, Cpair const &winner);

#endif //def_collatz_h
