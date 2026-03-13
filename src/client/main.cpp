#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

struct Driver {
    std::string tag;
    int skill;
};

std::vector<Driver> generate_drivers() {
    std::vector<Driver> drivers;
    drivers.push_back({ "HAM", 5 });
    drivers.push_back({ "MAS", 5 });
    drivers.push_back({ "RAI", 5 });
    drivers.push_back({ "KUB", 4 });
    drivers.push_back({ "ALO", 4 });
    drivers.push_back({ "HEI", 4 });
    drivers.push_back({ "KOV", 3 });
    drivers.push_back({ "VET", 3 });
    drivers.push_back({ "TRU", 3 });
    drivers.push_back({ "GLO", 3 });
    return drivers;
}

template <typename T>
std::vector<T> generate_timings(Driver drv, const T sectors[], const int length, const int laps, T time = 0.0) {
    std::vector<T> timings;
    for (int lap = 1; lap <= laps; lap++) {
        for (int i = 0; i < length; i++) {
            // timings.push_back(sectors[i] + calculate_diffs(0.01 * sectors[i], drv.skill));
            time += sectors[i];
            timings.push_back(time);
        }
    }
    return timings;
}

void print_timings_laps(const std::vector<float>& timings, const int sectors) {
    int lap_ctr = 1;
    int sec_ctr = sectors;
    for (auto& t : timings) {
        if (sec_ctr == sectors) {
            std::cout << "LAP " << std::setw(2) << lap_ctr << ": ";
        }
        std::cout << std::setw(8) << std::fixed << std::setprecision(3) << t;
        sec_ctr--;
        if (sec_ctr == 0) {
            lap_ctr++;
            sec_ctr = sectors;
            std::cout << std::endl;
        }
    }
}

int main() {
    std::vector<Driver> drivers = generate_drivers();

    constexpr int kSectorsNum = 10;
    constexpr float kSectors[kSectorsNum] = {
        7.0, 9.0, 11.0, 9.0, 10.0, 9.0, 12.0, 8.0, 8.0, 7.0
    };

    auto timings = generate_timings<float>(drivers[0], kSectors, kSectorsNum, 10, 0.0);
    print_timings_laps(timings, kSectorsNum);

    return 0;
}
