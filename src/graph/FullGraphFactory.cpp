#include <random>
#include "GraphFactory.hpp"

FullGraphFactory::FullGraphFactory(size_t number_of_vertexes)
    : AbstractGraphFactory(number_of_vertexes) {
}

Graph FullGraphFactory::createGraph() {
    for (size_t i = 0; i < graph.getNumberOfVertexes(); i++) {
        for (size_t j = i + 1; j < graph.getNumberOfVertexes(); j++) {
            auto weight = getWeight();
            graph.addEdge(i, j, weight);
            graph.addEdge(j, i, weight);
        }
    }
    return graph;
}