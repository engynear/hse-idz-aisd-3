#include "GraphFactory.hpp"
#include <random>
#include <algorithm>

TreeGraphFactory::TreeGraphFactory(size_t number_of_vertexes)
    : AbstractGraphFactory(number_of_vertexes) {
}

Graph TreeGraphFactory::createGraph() {
    // Generate graph without cycles
    // Create a vector with all possible edges
    std::vector<std::pair<size_t, size_t>> edges;
    for (size_t i = 0; i < graph.getNumberOfVertexes(); ++i) {
        for (size_t j = i + 1; j < graph.getNumberOfVertexes(); ++j) {
            edges.emplace_back(i, j);
        }
    }

    // Randomly shuffle the edges
    std::random_device rd;
    std::mt19937 generator(rd());
    std::shuffle(edges.begin(), edges.end(), generator);

    // Add edges to the graph, avoiding cycles
    for (const auto& edge : edges) {
        size_t from = edge.first;
        size_t to = edge.second;

        // Check if adding the edge will create a cycle
        if (!graph.isEdge(to, from)) {
            graph.addEdge(from, to, 1);
        }
    }

    return graph;
}