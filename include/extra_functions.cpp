#include "extra_functions.h"


void delay_in_millis(int millis_delay) {
    auto start = std::chrono::steady_clock::now();
    auto end = start + std::chrono::milliseconds(millis_delay); // 1 second later
    std::this_thread::sleep_until(end);
}

uint64_t get_unix_time_ns() {
    return static_cast<uint64_t>(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count());
}

uint64_t get_unix_time_us() {
    return static_cast<uint64_t>(std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count());
}

uint64_t get_unix_time_ms() {
    return static_cast<uint64_t>(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count());
}
 
