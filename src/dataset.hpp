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

/**
 * @brief Generate a dataset wich follow the representation ((1,0), (0,1))
 * 
 * @return dataset 
 */
dataset generateDataset1(int nbTrain, int nbTest);

#endif