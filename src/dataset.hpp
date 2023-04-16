#ifndef DATASET
#define DATASET

#include <vector>
#include <string>

typedef struct {
    std::vector<std::vector<double>> inputs;
    std::vector<std::vector<double>> outputs;
    std::vector<std::string> classes;
    int dataCount;
}data;

typedef struct {
    std::string name;
    int nbInput;
    int nbOutput;
    data train;
    data test;
} dataset;

#endif