#include "graph.hpp"

Graph::Graph() {
    this->number_of_vertexes = 0;
    this->number_of_edges = 0;
    this->matrix =
        std::vector<std::vector<int>>(number_of_vertexes, std::vector<int>(number_of_vertexes, -1));
}

Graph::Graph(size_t number_of_vertexes) {
    this->number_of_vertexes = number_of_vertexes;
    this->number_of_edges = 0;
    this->matrix =
        std::vector<std::vector<int>>(number_of_vertexes, std::vector<int>(number_of_vertexes, -1));
}

void Graph::addEdge(size_t from, size_t to, int64_t weight) {
    if (isEdge(from, to)) {
        return;
    }

    this->number_of_edges++;
    this->matrix[from][to] = weight;
}

int64_t Graph::getWeight(size_t from, size_t to) const {
    return matrix[from][to];
}

bool Graph::isEdge(size_t from, size_t to) const {
    return matrix[from][to] != -1;
}

bool Graph::operator==(const Graph& other) const {
    if (this->number_of_vertexes != other.number_of_vertexes) {
        return false;
    }

    if (this->number_of_edges != other.number_of_edges) {
        return false;
    }

    for (size_t i = 0; i < this->number_of_vertexes; i++) {
        for (size_t j = 0; j < this->number_of_vertexes; j++) {
            if (this->matrix[i][j] != other.matrix[i][j]) {
                return false;
            }
        }
    }

    return true;
}

size_t Graph::getNumberOfVertexes() const {
    return this->number_of_vertexes;
}

size_t Graph::getNumberOfEdges() const {
    return this->number_of_edges;
}