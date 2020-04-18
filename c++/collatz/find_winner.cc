#include "collatz.ih"

Cpair find_winner(collatz_t begin, collatz_t end)
{
    Cpair winner = {0, 0};
    for (size_t ix = begin ; ix < end; ++ ix)
        winner = max(winner, Cpair{ix, collatz_count(ix)});
    return winner;
}
