#include "SimplePomodoro.h"

namespace CppLondonUni {

    bool SimplePomodoro::IsComplete() const {
        return currentTime == 0;
    };

    uint32_t SimplePomodoro::CurrentCount() const {
        return currentTime;
    };

    void SimplePomodoro::Decrement() {
        --currentTime;
    };

    void SimplePomodoro::Cancel() {
        currentTime = 0;
    };

    std::string SimplePomodoro::FormatCurrentTime() const {
        auto minutes = currentTime / 60;
        auto seconds = currentTime % 60;
        return t.FormatTime(minutes, seconds);
    };
}
