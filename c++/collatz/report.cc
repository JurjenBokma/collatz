#include "collatz.ih"

void report(std::ostream &outs, collatz_t range_first, collatz_t range_last, Cpair const &winner)
{
    outs << "Max Collatz count in "
        "[" << range_first << ", " << range_last << "] "
        "reaches " << winner.count
              << " when sequence starts at "
              << winner.number << ":\n";
    spy_collatz(outs, winner.number);
}
