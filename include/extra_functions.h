#pragma once
#include <iostream> 
#include <chrono>
#include <thread> 

void delay_in_millis(int millis_delay);

uint64_t get_unix_time_ns();
uint64_t get_unix_time_us();
uint64_t get_unix_time_ms(); 