#include "network.hpp"
#include "node.hpp"
#include "activationFunction.hpp"
#include "layer.hpp"
#include <vector>
#include <iostream>
#include <fstream>

void printNode(Node n) {
    std::cout << "---Node---"<<std::endl;
    std::cout << "nbInput : " << n.getNbInput() << std::endl;
    std::cout << "activation function : " << n.getActivationFunction() << std::endl;
    std::cout << "bias :" << n.getBias() << std::endl;
    for (int i = 0; i<n.getNbInput(); i++) {
        std::cout << "weight " << i+1 << " : " << n.getWeight(i) << std::endl;
    }
    std::cout << "-------" << std::endl;
}

int main() {
    Node newNode;
    std::ifstream file;
    file.open("node.bin", std::ios::in | std::ios::binary);
    read(file, newNode);
    file.close();

    printNode(newNode);


    /*
    std::ofstream file;
    file.open("node.bin", std::ios::trunc | std::ios::binary);
    //write(file, newNode);
    file.close();
    */
}