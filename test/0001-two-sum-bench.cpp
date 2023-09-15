#include <catch2/catch_test_macros.hpp>
#include "0001-two-sum.h"
#include <ctime>
#include <sys/resource.h>
#include <iostream>
#include <sstream>
#include <iomanip>

// Function to get current CPU time in seconds
double get_cpu_time() {
    struct rusage ruse{};
    getrusage(RUSAGE_SELF, &ruse);
    return ruse.ru_utime.tv_sec + ruse.ru_utime.tv_usec / 1000000.0;
}

// Function to get current memory usage in bytes
long get_memory_usage() {
    struct rusage ruse{};
    getrusage(RUSAGE_SELF, &ruse);
    return ruse.ru_maxrss;
}

// Function to convert bytes to human-readable string
std::string to_readable(long bytes) {
    const char *sizes[] = {"B", "KiB", "MiB", "GiB", "TiB"};
    int order = 0;
    double readable_size = bytes;
    while (readable_size >= 1024 && order < 4) {
        order++;
        readable_size /= 1024;
    }
    std::stringstream ss;
    ss << std::fixed << std::setprecision(2) << readable_size << " " << sizes[order];
    return ss.str();
}

TEST_CASE("Benchmark twoSum function", "[twoSum]") {
    std::vector<int> nums;
    int array_size = 10000000;
    nums.reserve(array_size);
    for (int i = 0; i < array_size; ++i) {
        nums.push_back(i);
    }
    int target = array_size - 1 + array_size - 2;

    double start_time = get_cpu_time();
    long start_mem = get_memory_usage();

    // Call the function to benchmark
    std::vector<int> result = twoSum(nums, target);

    double end_time = get_cpu_time();
    long end_mem = get_memory_usage();
    long mem_diff = end_mem - start_mem;

    // Validate the result
    REQUIRE(result == std::vector<int>{array_size - 2, array_size - 1});

    std::cout << "CPU Time: " << end_time - start_time << " seconds" << std::endl;
    std::cout << "Memory Usage: " << mem_diff << " bytes (" << to_readable(mem_diff) << ")" << std::endl;
}
