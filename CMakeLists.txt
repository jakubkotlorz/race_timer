cmake_minimum_required(VERSION 3.28)

project(RaceTimer)

add_executable(race_timer_server
    src/server/racetimer.cpp
    src/server/main.cpp
)

add_executable(race_timer_client
    src/client/main.cpp
)

target_compile_features(race_timer_server PRIVATE cxx_std_20)
target_compile_features(race_timer_server PRIVATE cxx_std_20)