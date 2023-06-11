#include <fstream>
#include "csvWriter.hpp"

CsvWriter::CsvWriter(std::string file_name) {
    this->file_name = file_name;
}

void CsvWriter::setFileName(std::string file_name) {
    this->file_name = file_name;
}

void CsvWriter::addRecord(AlgorithmStatisticRecord record) {
    this->records.push_back(record);
}

void CsvWriter::write() {
    std::ofstream file(this->file_name);
    file << "algorithm_name,number_of_vertexes,number_of_edges,execution_time" << std::endl;
    for (auto record : this->records) {
        file << record.algorithm_name << "," << record.number_of_vertexes << ","
             << record.number_of_edges << "," << record.execution_time << std::endl;
    }
    file.close();
}

void CsvWriter::clear() {
    this->records.clear();
}
