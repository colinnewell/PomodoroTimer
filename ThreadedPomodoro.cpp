#include "ThreadedPomodoro.h"
#include "timeformatter.h"

using CppLondonUni::ThreadedPomodoro;

std::chrono::high_resolution_clock clk;

void ThreadedPomodoro::InvokeProcessLoop(uint32_t time, std::function<bool(uint32_t)>&& callback) {
    // std::thread
    // std::chrono
    // std::function
    currentTime = time;
    if(runner.joinable()) {
        runner.join();
    }
    done = false;
    runner = std::thread([&, callback = std::move(callback)]() mutable {
        done = callback(currentTime);
    });
};

// Interrupt() should result in InvokeProcessLoop returning ASAP
void ThreadedPomodoro::Interrupt() {
    done = true;
};

// Same requirements as FormatCurrentTime() in the ISimpleCountdown
std::string ThreadedPomodoro::FormatCurrentTime() const {
    timeformatter t;
    auto current = this->currentTime.load();
    int minutes = current / 60;
    int seconds = current % 60;
    return t.FormatTime(minutes, seconds);
};

ThreadedPomodoro::~ThreadedPomodoro() {
    done = true;
    if(runner.joinable())
        runner.join();
}
