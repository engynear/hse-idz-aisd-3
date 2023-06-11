#ifndef CSVWRITER_HPP
#define CSVWRITER_HPP

#include <vector>
#include <string>

struct AlgorithmStatisticRecord {
    std::string algorithm_name;
    size_t number_of_vertexes;
    size_t number_of_edges;
    double execution_time;

    // Output operator for AlgorithmStatisticRecord.
    friend std::ostream& operator<<(std::ostream& os, const AlgorithmStatisticRecord& record) {
        os << "{ algorithm_name=" << record.algorithm_name
           << ", number_of_vertexes=" << record.number_of_vertexes
           << ", number_of_edges=" << record.number_of_edges
           << ", execution_time=" << record.execution_time << " }";
        return os;
    }
};

class CsvWriter {
public:
    CsvWriter(std::string file_name);
    void setFileName(std::string file_name);
    void addRecord(AlgorithmStatisticRecord record);
    void write();
    void clear();

private:
    std::string file_name;
    std::vector<AlgorithmStatisticRecord> records;
};

#endif  // ALGORITHMSTATISTICCSVWRITER_HPP
