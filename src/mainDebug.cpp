#include "network.hpp"
#include "node.hpp"
#include "activationFunction.hpp"
#include <vector>
#include <iostream>

int main() {
    Node n(Identity, 2);
    std::cout << "reseau :" << n.getWeight(0) << " / " << n.getWeight(1) << "/ b :" << n.getBias() << std::endl;
    std::cout << "output (0,0) : " << n.processOutputs(std::vector<double> {0,0}) << std::endl;
    std::cout << "output (1,1) : " << n.processOutputs(std::vector<double> {1,1}) << std::endl;
    std::cout << "TESTER" << std::endl;
}