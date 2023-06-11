#ifndef WAYFINDINGALGORITHMS_HPP
#define WAYFINDINGALGORITHMS_HPP

#include <vector>
#include <algorithm>
#include <string>
#include "../graph/graph.hpp"

#define INT_MAX 1e9

class AbstractAlgorithm {
public:
    AbstractAlgorithm(Graph graph, size_t start, size_t finish);

    virtual std::vector<size_t> findWay() = 0;

    virtual std::string getName() const = 0;

protected:
    Graph graph;
    size_t start;
    size_t finish;
};

class BellmanFordAlgorithm : public AbstractAlgorithm {
public:
    BellmanFordAlgorithm(Graph graph, size_t start, size_t finish);
    std::vector<size_t> findWay() override;
    std::string getName() const override;
};

class DijkstraAlgorithm : public AbstractAlgorithm {
public:
    DijkstraAlgorithm(Graph graph, size_t start, size_t finish);
    std::vector<size_t> findWay() override;
    std::string getName() const override;
};


class FloydWarshallAlgorithm : public AbstractAlgorithm {
public:
    FloydWarshallAlgorithm(Graph graph, size_t start, size_t finish);
    std::vector<size_t> findWay() override;
    std::string getName() const override;
};

class JohnsonAlgorithm : public AbstractAlgorithm {
public:
    JohnsonAlgorithm(Graph graph, size_t start, size_t finish);
    std::vector<size_t> findWay() override;
    std::string getName() const override;
};

#endif  // WAYFINDINGALGORITHMS_HPP
