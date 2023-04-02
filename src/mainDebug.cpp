#include "network.hpp"
#include "node.hpp"
#include "activationFunction.hpp"
#include "layer.hpp"
#include <vector>
#include <iostream>

int main() {
    Layer layer(Sigmoid, 2, 100);
    std::vector<double> inputs = {1,1};
    std::vector<double> outputs = layer.processOutputs(inputs);
    std::cout << outputs.at(2) << " : " << outputs.size() << std::endl;
}