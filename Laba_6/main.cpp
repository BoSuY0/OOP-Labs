#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <exception>
#include <sstream>

class InsufficientDataException : public std::exception {
    std::string msg;
public:
    explicit InsufficientDataException(const std::string& m) : msg(m) {}
    const char* what() const noexcept override { return msg.c_str(); }
};

double readAndAverage(const std::string& filename, int minCount) {
    std::ifstream file(filename);
    if (!file.is_open())
        throw std::runtime_error("Cannot open file: " + filename);
    std::vector<double> nums;
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        double v;
        if (!(iss >> v))
            throw std::runtime_error("Invalid data in file: " + line);
        nums.push_back(v);
    }
    if ((int)nums.size() < minCount)
        throw InsufficientDataException("Need " + std::to_string(minCount) + " values, got " + std::to_string(nums.size()));
    double sum = 0;
    for (double n : nums) sum += n;
    return sum / nums.size();
}

int main() {
    // Create test file
    {
        std::ofstream f("data.txt");
        f << "10\n20\n30\n40\n50\n";
    }
    try {
        std::cout << "Average: " << readAndAverage("data.txt", 3) << "\n";
    } catch (const InsufficientDataException& e) {
        std::cerr << "InsufficientData: " << e.what() << "\n";
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
    try {
        readAndAverage("nonexistent.txt", 1);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
    try {
        {
            std::ofstream f("small.txt");
            f << "5\n";
        }
        readAndAverage("small.txt", 5);
    } catch (const InsufficientDataException& e) {
        std::cerr << "InsufficientData: " << e.what() << "\n";
    }
    return 0;
}
