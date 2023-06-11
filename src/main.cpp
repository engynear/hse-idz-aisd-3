#include <iostream>
#include <unordered_map>

#include "csvWriter.hpp"
#include "algorithm/algorithms.hpp"
#include "algorithm/algorithmsEnum.hpp"
#include "graph/graph.hpp"
#include "graph/GraphFactory.hpp"
#include "timeMeasurement.hpp"

#define NUMBER_OF_TESTS 10

AbstractAlgorithm* getAlgorithm(AlgorithmEnum algorithm, Graph graph,
                                          size_t start, size_t finish) {
    switch (algorithm) {
        case AlgorithmEnum::Dijkstra:
            return new DijkstraAlgorithm(graph, start, finish);
        case AlgorithmEnum::BellmanFord:
            return new BellmanFordAlgorithm(graph, start, finish);
        case AlgorithmEnum::FloydWarshall:
            return new FloydWarshallAlgorithm(graph, start, finish);
        case AlgorithmEnum::Johnson:
            return new JohnsonAlgorithm(graph, start, finish);
        default:
            return nullptr;
    }
}

int main() {
    size_t start_number_of_vertexes = 10, finish_number_of_vertexes = 1010, step = 50;

    CsvWriter csv_writer("output/FullGraph.csv");
    std::unordered_map<int, Graph> full_graphs;
    std::unordered_map<int, Graph> connected_graphs;
    std::unordered_map<int, Graph> tree_graphs;

    for (size_t i = 0; i < 4; ++i) {
        AlgorithmEnum algorithm = static_cast<AlgorithmEnum>(i);

        for (size_t number_of_vertexes = start_number_of_vertexes;
             number_of_vertexes <= finish_number_of_vertexes; number_of_vertexes += step) {
            if (full_graphs.find(number_of_vertexes) == full_graphs.end()) {
                full_graphs[number_of_vertexes] =
                    FullGraphFactory(number_of_vertexes).createGraph();
            }
            Graph graph = full_graphs[number_of_vertexes];
            std::cout << "Создан граф" << std::endl;
            AbstractAlgorithm* algorithm_ptr =
                getAlgorithm(algorithm, graph, 0, number_of_vertexes - 1);

            std::cout << "Алгоритм " << algorithm_ptr->getName() << " с " << number_of_vertexes
                      << " вершинами запущен" << std::endl;

            AlgorithmStatisticRecord record = {algorithm_ptr->getName(), number_of_vertexes,
                                               graph.getNumberOfEdges(),
                                               getExecutionTime(algorithm_ptr)};
            csv_writer.addRecord(record);
            std::cout << "Запись " << record << " добавлена" << std::endl;
            delete algorithm_ptr;
        }

        std::cout << "Алгоритм " << i << " завершен" << std::endl;
    }

    csv_writer.write();

    csv_writer = CsvWriter("output/ConnectedGraph.csv");

    for (size_t i = 0; i < 4; ++i) {
        AlgorithmEnum algorithm = static_cast<AlgorithmEnum>(i);

        for (size_t number_of_vertexes = start_number_of_vertexes;
             number_of_vertexes <= finish_number_of_vertexes; number_of_vertexes += step) {
            if (connected_graphs.find(number_of_vertexes) == connected_graphs.end()) {
                connected_graphs[number_of_vertexes] =
                    ConnectedGraphFactory(number_of_vertexes).createGraph();
            }
            Graph graph = connected_graphs[number_of_vertexes];
            AbstractAlgorithm* algorithm_ptr =
                getAlgorithm(algorithm, graph, 0, number_of_vertexes - 1);

            std::cout << "Алгоритм " << algorithm_ptr->getName() << " с " << number_of_vertexes
                      << " вершинами запущен" << std::endl;
            csv_writer.addRecord({algorithm_ptr->getName(), number_of_vertexes,
                                  graph.getNumberOfEdges(), getExecutionTime(algorithm_ptr)});
            delete algorithm_ptr;
        }

        std::cout << "Алгоритм " << i << " завершен" << std::endl;
    }

    csv_writer.write();

    csv_writer = CsvWriter("output/TreeGraph.csv");

    for (size_t i = 0; i < 4; ++i) {
        AlgorithmEnum algorithm = static_cast<AlgorithmEnum>(i);

        for (size_t number_of_vertexes = start_number_of_vertexes;
             number_of_vertexes <= finish_number_of_vertexes; number_of_vertexes += step) {
            if (tree_graphs.find(number_of_vertexes) == tree_graphs.end()) {
                tree_graphs[number_of_vertexes] =
                    TreeGraphFactory(number_of_vertexes).createGraph();
            }
            Graph graph = tree_graphs[number_of_vertexes];
            AbstractAlgorithm* algorithm_ptr =
                getAlgorithm(algorithm, graph, 0, number_of_vertexes - 1);

            std::cout << "Алгоритм " << algorithm_ptr->getName() << " с " << number_of_vertexes
                      << " вершинами запущен" << std::endl;
            csv_writer.addRecord({algorithm_ptr->getName(), number_of_vertexes,
                                  graph.getNumberOfEdges(), getExecutionTime(algorithm_ptr)});
            delete algorithm_ptr;
        }

        std::cout << "Алгоритм " << i << " завершен" << std::endl;
    }

    csv_writer.write();

    return 0;
}
