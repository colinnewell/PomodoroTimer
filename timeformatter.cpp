//
// Created by colin on 13/02/18.
//

#include "timeformatter.h"

namespace CppLondonUni
{
    std::string timeformatter::FormatTime(uint32_t mins, uint32_t secs) const {
        std::ostringstream o;
        o << std::setfill('0') << std::setw(2) << mins
          << ":"
          << std::setfill('0') << std::setw(2) << secs;
        return o.str();
    };
}