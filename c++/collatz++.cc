#include <iostream>

// Define collatz_t in case we want another type later on.
#include "collatz/collatz.hh"

using namespace std;

int main(int argc, char **argv)
{
    size_t const range_last = 1 + (
        argc > 2 ? stoull(argv[2]): // last param if there are two
        argc > 1 ? stoull(argv[1]): // first param if there is only one
        1000 );
    size_t const range_first =
        argc > 2 ? stoull(argv[1]) // first param if there are two
        : 1;

    Cpair winner = find_winner(range_first, range_last);
    report(cout, range_first, range_last - 1, winner);
    cout << '\n';
}
