#ifndef GRAPHFACTORY_HPP
#define GRAPHFACTORY_HPP

#include <iostream>
#include <vector>
#include "graph.hpp"

class AbstractGraphFactory {
public:
    AbstractGraphFactory(size_t number_of_vertexes);
    virtual Graph createGraph() = 0;

protected:
    Graph graph;

    int getWeight();
};

class FullGraphFactory : public AbstractGraphFactory {
public:
    FullGraphFactory(size_t number_of_vertexes);
    Graph createGraph() override;
};

class ConnectedGraphFactory : public AbstractGraphFactory {
public:
    ConnectedGraphFactory(size_t number_of_vertexes);
    Graph createGraph() override;

private:
    double getConnectionCoefficient();
};

class TreeGraphFactory : public AbstractGraphFactory {
public:
    TreeGraphFactory(size_t number_of_vertexes);
    Graph createGraph() override;
};

#endif  // GRAPHFACTORY_HPP
