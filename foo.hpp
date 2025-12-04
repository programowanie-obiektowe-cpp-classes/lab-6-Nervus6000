#pragma once

#include "Human.hpp"

#include <algorithm>
#include <list>
#include <vector>

std::vector< char > foo(std::list< Human >& people)
{
    std::vector< char > retval(people.size());

    std::for_each(people.begin(), people.end(), [](Human& h) { h.birthday(); });

    auto out_it = retval.rbegin();

    std::for_each(people.begin(), people.end(), [&](Human& h) {
        if (h.isMonster()) {
            *out_it = 'n';
        }
        else {
            *out_it = 'y';
        }

        ++out_it;
    });
return retval;
}
