#include "algorithms.hpp"
#include <queue>
#include <limits>

AbstractAlgorithm::AbstractAlgorithm(Graph graph, size_t start, size_t finish)
    : graph(graph), start(start), finish(finish) {
}


// ----------------------------------------------------------------
// BellmanFord Algorithm
// ----------------------------------------------------------------
BellmanFordAlgorithm::BellmanFordAlgorithm(Graph graph, size_t start, size_t finish)
    : AbstractAlgorithm(graph, start, finish) {
}

std::vector<size_t> BellmanFordAlgorithm::findWay() {
    std::vector<int64_t> distances(graph.getNumberOfVertexes(), INT_MAX);
    std::vector<size_t> parents(graph.getNumberOfVertexes(), -1);

    distances[start] = 0;

    for (size_t i = 0; i < graph.getNumberOfVertexes() - 1; i++) {
        for (size_t j = 0; j < graph.getNumberOfVertexes(); j++) {
            for (size_t k = 0; k < graph.getNumberOfVertexes(); k++) {
                if (graph.isEdge(j, k)) {
                    if (distances[j] < INT_MAX) {
                        if (distances[k] > distances[j] + graph.getWeight(j, k)) {
                            distances[k] = distances[j] + graph.getWeight(j, k);
                            parents[k] = j;
                        }
                    }
                }
            }
        }
    }

    for (size_t i = 0; i < graph.getNumberOfVertexes(); i++) {
        for (size_t j = 0; j < graph.getNumberOfVertexes(); j++) {
            if (graph.isEdge(i, j)) {
                if (distances[i] < INT_MAX) {
                    if (distances[j] > distances[i] + graph.getWeight(i, j)) {
                        throw std::runtime_error("Graph contains negative cycle");
                    }
                }
            }
        }
    }

    std::vector<size_t> way;
    size_t current = finish;

    while (current != start) {
        way.push_back(current);
        current = parents[current];
    }

    way.push_back(start);
    std::reverse(way.begin(), way.end());

    return way;
}

std::string BellmanFordAlgorithm::getName() const {
    return "Алгоритм Беллмана-Форда";
}


// ----------------------------------------------------------------
// Dijkstra Algorithm
// ----------------------------------------------------------------

DijkstraAlgorithm::DijkstraAlgorithm(Graph graph, size_t start, size_t finish)
    : AbstractAlgorithm(graph, start, finish) {
}

std::vector<size_t> DijkstraAlgorithm::findWay() {
    std::vector<int64_t> distances(graph.getNumberOfVertexes(), INT_MAX);
    std::vector<size_t> parents(graph.getNumberOfVertexes(), -1);

    distances[start] = 0;

    std::priority_queue<std::pair<int64_t, size_t>, std::vector<std::pair<int64_t, size_t>>,
                        std::greater<std::pair<int64_t, size_t>>>
        queue;
    queue.push({0, start});

    while (!queue.empty()) {
        size_t current = queue.top().second;
        queue.pop();

        for (size_t i = 0; i < graph.getNumberOfVertexes(); i++) {
            if (graph.isEdge(current, i)) {
                if (distances[i] > distances[current] + graph.getWeight(current, i)) {
                    distances[i] = distances[current] + graph.getWeight(current, i);
                    parents[i] = current;
                    queue.push({distances[i], i});
                }
            }
        }
    }

    std::vector<size_t> way;
    size_t current = finish;

    while (current != start) {
        way.push_back(current);
        current = parents[current];
    }

    way.push_back(start);
    std::reverse(way.begin(), way.end());

    return way;
}

std::string DijkstraAlgorithm::getName() const {
    return "Алгоритм Дейкстры";
}

//----------------------------------------------------------------
// FloydWarshall Algorithm
//----------------------------------------------------------------
FloydWarshallAlgorithm::FloydWarshallAlgorithm(Graph graph, size_t start, size_t finish)
    : AbstractAlgorithm(graph, start, finish) {
}

std::vector<size_t> FloydWarshallAlgorithm::findWay() {
    std::vector<std::vector<int64_t>> distances(graph.getNumberOfVertexes(),
                                                std::vector<int64_t>(graph.getNumberOfVertexes(), INT_MAX));
    std::vector<std::vector<size_t>> parents(graph.getNumberOfVertexes(),
                                             std::vector<size_t>(graph.getNumberOfVertexes(), -1));

    for (size_t i = 0; i < graph.getNumberOfVertexes(); i++) {
        for (size_t j = 0; j < graph.getNumberOfVertexes(); j++) {
            if (graph.isEdge(i, j)) {
                distances[i][j] = graph.getWeight(i, j);
                parents[i][j] = i;
            }
        }
    }

    for (size_t k = 0; k < graph.getNumberOfVertexes(); k++) {
        for (size_t i = 0; i < graph.getNumberOfVertexes(); i++) {
            for (size_t j = 0; j < graph.getNumberOfVertexes(); j++) {
                if (distances[i][k] < INT_MAX && distances[k][j] < INT_MAX) {
                    if (distances[i][j] > distances[i][k] + distances[k][j]) {
                        distances[i][j] = distances[i][k] + distances[k][j];
                        parents[i][j] = parents[k][j];
                    }
                }
            }
        }
    }

    std::vector<size_t> way;
    size_t current = finish;

    while (current != start) {
        way.push_back(current);
        current = parents[start][current];
    }

    way.push_back(start);
    std::reverse(way.begin(), way.end());

    return way;
}

std::string FloydWarshallAlgorithm::getName() const {
    return "Алгоритм Флойда-Уоршелла";
}

//----------------------------------------------------------------
// Johnson Algorithm
//----------------------------------------------------------------
JohnsonAlgorithm::JohnsonAlgorithm(Graph graph, size_t start, size_t finish)
    : AbstractAlgorithm(graph, start, finish) {
}

std::vector<size_t> JohnsonAlgorithm::findWay() {
    std::vector<std::vector<int64_t>> distances(graph.getNumberOfVertexes(),
                                                std::vector<int64_t>(graph.getNumberOfVertexes(), INT_MAX));
    std::vector<std::vector<size_t>> parents(graph.getNumberOfVertexes(),
                                             std::vector<size_t>(graph.getNumberOfVertexes(), -1));

    for (size_t i = 0; i < graph.getNumberOfVertexes(); i++) {
        for (size_t j = 0; j < graph.getNumberOfVertexes(); j++) {
            if (graph.isEdge(i, j)) {
                distances[i][j] = graph.getWeight(i, j);
                parents[i][j] = i;
            }
        }
    }

    for (size_t k = 0; k < graph.getNumberOfVertexes(); k++) {
        for (size_t i = 0; i < graph.getNumberOfVertexes(); i++) {
            for (size_t j = 0; j < graph.getNumberOfVertexes(); j++) {
                if (distances[i][k] < INT_MAX && distances[k][j] < INT_MAX) {
                    if (distances[i][j] > distances[i][k] + distances[k][j]) {
                        distances[i][j] = distances[i][k] + distances[k][j];
                        parents[i][j] = parents[k][j];
                    }
                }
            }
        }
    }

    std::vector<size_t> way;
    size_t current = finish;

    while (current != start) {
        way.push_back(current);
        current = parents[start][current];
    }

    way.push_back(start);
    std::reverse(way.begin(), way.end());

    return way;
}

std::string JohnsonAlgorithm::getName() const {
    return "Алгоритм Джонсона";
}