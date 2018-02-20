#include <iostream>
#include "ThreadedPomodoro.h"

using CppLondonUni::ThreadedPomodoro;
using namespace std::chrono_literals;

static std::chrono::high_resolution_clock clk;

void ThreadedPomodoro::InvokeProcessLoop(uint32_t time, std::function<bool(uint32_t)>&& callback) {
    // std::thread
    // std::chrono
    // std::function
    currentTime = time;
    if(runner.joinable()) {
        done = true;
        runner.join();
    }
    done = false;
    runner = std::thread{[&, callback = std::move(callback)]() mutable {
        while(currentTime > 0 && !done) {
            auto start = clk.now();
            done = callback(currentTime--);
            auto elapsed = clk.now()-start;
            std::this_thread::sleep_for(1s - elapsed);
        }
        // also handy for when we reset
        callback(0); // of by 1 ;)
    }};
};

// Interrupt() should result in InvokeProcessLoop returning ASAP
void ThreadedPomodoro::Interrupt() {
    done = true;
};

// Same requirements as FormatCurrentTime() in the ISimpleCountdown
std::string ThreadedPomodoro::FormatCurrentTime() const {
    auto current = this->currentTime.load();
    auto minutes = current / 60;
    auto seconds = current % 60;
    return t.FormatTime(minutes, seconds);
};

ThreadedPomodoro::~ThreadedPomodoro() {
    done = true;
    if(runner.joinable())
        runner.join();
}
