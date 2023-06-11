#include <random>
#include "GraphFactory.hpp"

AbstractGraphFactory::AbstractGraphFactory(size_t number_of_vertexes) : graph(number_of_vertexes) {
    srand(time(nullptr));
}

int AbstractGraphFactory::getWeight() {
    return rand() % 100 + 1;
}