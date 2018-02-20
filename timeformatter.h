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
        virtual std::string FormatTime(uint32_t mins, uint32_t secs) const;
    };
}


#endif //CPPLONDONUNI_POMODORO_TIMEFORMATTER_H
