//
// Created by colin on 13/02/18.
//

#ifndef CPPLONDONUNI_POMODORO_TIMEFORMATTER_H
#define CPPLONDONUNI_POMODORO_TIMEFORMATTER_H

#include <interface/IPomodoro.h>
#include <iomanip>

using CppLondonUni::ITimeFormatter;

namespace CppLondonUni {
    class timeformatter : public ITimeFormatter {
    public:
        virtual std::string FormatTime(uint32_t mins, uint32_t secs) const {
            std::ostringstream o;
            o << std::setfill('0') << std::setw(2) << mins
              << ":"
              << std::setfill('0') << std::setw(2) << secs;
            return o.str();
        };
    };
}


#endif //CPPLONDONUNI_POMODORO_TIMEFORMATTER_H
