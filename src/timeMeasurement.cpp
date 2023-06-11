#include "timeMeasurement.hpp"

double getExecutionTime(AbstractAlgorithm* algorithm) {
    auto start_time = std::chrono::high_resolution_clock::now();
    algorithm->findWay();
    auto finish_time = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::nanoseconds>(finish_time - start_time).count();
}
