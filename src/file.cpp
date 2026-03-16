#include "globals.h"
#include "file.h"


void load_file(std::vector<std::string>& buffer, const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << "\n";
        return;
    }

    buffer.clear();
    std::string line;
    while (std::getline(file, line)) {
        buffer.push_back(line);
    }
    lines_of_buffer = buffer.size();
    file.close();
}