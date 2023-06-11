#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <iostream>

class Graph {
public:
    Graph();
    Graph(size_t number_of_vertexes);
    void addEdge(size_t from, size_t to, int64_t weight);
    size_t getNumberOfVertexes() const;
    size_t getNumberOfEdges() const;
    int64_t getWeight(size_t from, size_t to) const;
    bool isEdge(size_t from, size_t to) const;
    bool operator==(const Graph& other) const;

private:
    size_t number_of_vertexes;
    size_t number_of_edges;

    std::vector<std::vector<int>> matrix;
};

#endif  // GRAPH_HPP
