#include <iostream>
#include <vector>
#include <omp.h>

// Function to perform dot product of a row and a vector
int dotProduct(const std::vector<int>& row, const std::vector<int>& b) {
    int result = 0;
    #pragma omp parallel for reduction(+:result)
    for (size_t i = 0; i < row.size(); ++i) {
        result += row[i] * b[i];
    }
    return result;
}

int main() {
    std::vector<std::vector<int>> a = {{1, 2, 3, 13},
                                        {4, 5, 6, 14},
                                        {7, 8, 9, 15},
                                        {10, 11, 12, 16}};

    std::vector<int> b = {10, 20, 30, 40};

    std::cout << "Matrix a =\n";
    for (const auto& row : a) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "Matrix b =";
    for (int val : b) {
        std::cout << " " << val;
    }
    std::cout << std::endl;

    // Container to hold the results of multiplication
    std::vector<int> results(a.size());

    // Parallel computation of dot products
    #pragma omp parallel for
    for (size_t i = 0; i < a.size(); ++i) {
        results[i] = dotProduct(a[i], b);
    }

    std::cout << "Product of a and b =";
    for (int val : results) {
        std::cout << " " << val;
    }
    std::cout << std::endl;

    return 0;
}

