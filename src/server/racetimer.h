#include <chrono>
#include <iostream>
#include <memory>
#include <thread>

using Clock = std::chrono::steady_clock;
using TimePoint = std::chrono::time_point<Clock>;


struct TimerConfig {
    std::chrono::high_resolution_clock clock;
};

class RaceTimer {
  public:

    RaceTimer(TimerConfig& conf) : config_(conf) {
        // timer_ = config_;
    }

    void run() {
        timer_thread = std::make_unique<std::thread>(&RaceTimer::thread_func, this);
        timer_thread->join();
    }

    void run_cmd(std::string& cmd) {
        std::cout << "Command is: " << cmd << std::endl;
        if (cmd == "p") {
            std::cout << "--> " << std::endl;
        }
    }

  private:
    void thread_func() { ; }

    std::unique_ptr<std::thread> timer_thread;
    TimerConfig config_;
    const TimePoint start_time_;
};