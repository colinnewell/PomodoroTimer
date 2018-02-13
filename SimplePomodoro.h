#pragma once

#include <iomanip>
#include "IPomodoro.h"
#include "timeformatter.h"

namespace CppLondonUni {
    class SimplePomodoro : public ISimpleCountdown {
    public:

        SimplePomodoro(const uint32_t startTime) : currentTime{startTime}, ISimpleCountdown{startTime} {}

        virtual bool IsComplete() const {
            return this->currentTime == 0;
        };

        // CurrentCount should return the number of seconds remaining.
        virtual uint32_t CurrentCount() const {
            return this->currentTime;
        };

        // Decrement should decrement the seconds remaining by 1.
        virtual void Decrement() {
            this->currentTime--;
        };

        // If Cancel is called, all subsequent calls to IsComplete should
        // return true.
        virtual void Cancel() {
            this->currentTime = 0;
        };

        // FormatCurrentTime should return a string of the current time remaining
        // in the same format as what FormatTime() returns.
        virtual std::string FormatCurrentTime() const {
            timeformatter t;
            int minutes = this->currentTime / 60;
            int seconds = this->currentTime % 60;
            return t.FormatTime(minutes, seconds);
        };

    private:
        uint32_t currentTime;

    };
}
