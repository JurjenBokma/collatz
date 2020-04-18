#include "collatz.ih"

collatz_t find_winner2(collatz_t begin, collatz_t end)
{
    collatz_t topscorer = 0;
    size_t highscore = 0;
    for (collatz_t ix = begin ; ix < end; ++ix)
    {
        collatz_t const score = collatz_count(ix);
        if (score > highscore)
        {
            highscore = score;            
            topscorer = ix;
        }
    }
    return topscorer;
}
