#pragma once

#include <thread>
#include "IPomodoro.h"
#include "timeformatter.h"

using CppLondonUni::IThreadedCountdown;

namespace CppLondonUni {
    class ThreadedPomodoro : public IThreadedCountdown {

        virtual void InvokeProcessLoop(uint32_t time, std::function<bool(uint32_t)>&& callback) {
            // std::thread
            // std::chrono
            // std::function
            currentTime = time;
            if(runner.joinable()) {
                runner.join();
            }
            runner =
        };

        // Interrupt() should result in InvokeProcessLoop returning ASAP
        virtual void Interrupt() {

        };

        // Same requirements as FormatCurrentTime() in the ISimpleCountdown
        virtual std::string FormatCurrentTime() const {
            timeformatter t;
            int minutes = this->currentTime / 60;
            int seconds = this->currentTime % 60;
            return t.FormatTime(minutes, seconds);
        };

        ~ThreadedPomodoro() {
            if(runner.joinable())
                runner.join();
        }

    private:
        uint32_t currentTime;
        std::thread runner;

    };
}
