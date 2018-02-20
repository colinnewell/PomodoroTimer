#pragma once

#include <iomanip>
#include "IPomodoro.h"
#include "timeformatter.h"

namespace CppLondonUni {
    class SimplePomodoro : public ISimpleCountdown {
    public:

        //SimplePomodoro(const uint32_t startTime) : currentTime{startTime}, ISimpleCountdown{startTime} {}
        using ISimpleCountdown::ISimpleCountdown; // reuse base classes constructor

        virtual bool IsComplete() const;

        // CurrentCount should return the number of seconds remaining.
        virtual uint32_t CurrentCount() const;

        // Decrement should decrement the seconds remaining by 1.
        virtual void Decrement();

        // If Cancel is called, all subsequent calls to IsComplete should
        // return true.
        virtual void Cancel();

        // FormatCurrentTime should return a string of the current time remaining
        // in the same format as what FormatTime() returns.
        virtual std::string FormatCurrentTime() const;

    private:
        uint32_t currentTime{startTime};
        timeformatter t;

    };
}
