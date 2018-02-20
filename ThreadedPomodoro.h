#pragma once

#include <atomic>
#include <thread>
#include "IPomodoro.h"
#include "timeformatter.h"

using CppLondonUni::IThreadedCountdown;

namespace CppLondonUni {
    class ThreadedPomodoro : public IThreadedCountdown {

    public:
        virtual void InvokeProcessLoop(uint32_t time, std::function<bool(uint32_t)>&& callback);

        // Interrupt() should result in InvokeProcessLoop returning ASAP
        virtual void Interrupt();

        // Same requirements as FormatCurrentTime() in the ISimpleCountdown
        virtual std::string FormatCurrentTime() const;

        ~ThreadedPomodoro();

    private:
        std::atomic_bool done;
        std::atomic_uint_fast32_t currentTime;
        std::thread runner;
        timeformatter t;

    };
}
