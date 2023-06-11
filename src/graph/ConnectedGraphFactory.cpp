#include "GraphFactory.hpp"

ConnectedGraphFactory::ConnectedGraphFactory(size_t number_of_vertexes)
    : AbstractGraphFactory(number_of_vertexes) {
}

Graph ConnectedGraphFactory::createGraph() {
    for (size_t i = 0; i < graph.getNumberOfVertexes(); i++) {
        graph.addEdge(i, (i + 1) % graph.getNumberOfVertexes(), 1);
    }

    while (getConnectionCoefficient() < 0.5) {
        size_t from = rand() % graph.getNumberOfVertexes();
        size_t to = rand() % graph.getNumberOfVertexes();
        if (from != to) {
            auto weight = getWeight();
            graph.addEdge(from, to, weight);
            graph.addEdge(to, from, weight);
        }
    }

    return graph;
}

double ConnectedGraphFactory::getConnectionCoefficient() {
    return (2 * this->graph.getNumberOfEdges()) /
           (this->graph.getNumberOfVertexes() * (this->graph.getNumberOfVertexes() - 1));
}