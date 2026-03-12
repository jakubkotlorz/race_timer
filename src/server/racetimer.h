#include <chrono>
#include <iostream>
#include <memory>
#include <string>
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
        } else if (cmd == "start") {
            std::cout << "Starting!" << std::endl;
            start_time_ =  std::chrono::steady_clock::now();
        } else if (cmd == "stop") {
            std::chrono::duration<double> difftime =  std::chrono::steady_clock::now() - start_time_;
            std::cout << "Stopping! " << difftime << std::endl;
        } else {
            std::cout << "Unknown command: " + cmd << std::endl;
        }
    }

  private:
    void thread_func() { ; }

    std::unique_ptr<std::thread> timer_thread;
    TimerConfig config_;
    TimePoint start_time_;
};