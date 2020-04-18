#include "collatz.ih"

Cpair max(Cpair const &lhs, Cpair const &rhs)
{
    return lhs.count > rhs.count ? lhs : rhs;
}
