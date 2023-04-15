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
    std::cout << "activation function : " << n.getActivationFunction().index << std::endl;
    std::cout << "bias :" << n.getBias() << std::endl;
    for (int i = 0; i<n.getNbInput(); i++) {
        std::cout << "weight " << i+1 << " : " << n.getWeight(i) << std::endl;
    }
    std::cout << "-------" << std::endl;
}

void printLayer(Layer l) {
    std::cout << "---Layer---" << std::endl;
    std::cout << "nbInput : " << l.getNbInput() << std::endl;
    std::cout << "nbNodes : " << l.getNbNodes() << std::endl;
    std::cout << "activation function : " << l.getActivationFunction().index << std::endl;
    for (int i=0; i<l.getNbNodes(); i++) {
        std::cout << "Node " << i << std::endl;
        printNode(l.getNode(i));
    }
    std::cout << "--------" << std::endl;
}

int main() {
    //setupActivation();
    bool save = false;

    if (save) {
        Layer layer(sigmoid,2,10);
        printLayer(layer);
        std::cout << std::endl << std::endl;
        std::vector<double> input = {1,3};
        std::vector<double> output = layer.processOutputs(input);

        for (int i=0; i<output.size(); i++) {
            std::cout << output.at(i) << std::endl;
        }

        std::ofstream file;
        file.open("layer.bin", std::ios::trunc | std::ios::binary);
        write(file, layer);
        file.close();

    }
    else {
        Layer layer;
        std::ifstream file;
        file.open("layer.bin", std::ios::in | std::ios::binary);
        read(file, layer);
        file.close();


        printLayer(layer);
        std::cout << std::endl << std::endl;
        std::vector<double> input = {1,3};
        std::vector<double> output = layer.processOutputs(input);

        for (int i=0; i<output.size(); i++) {
            std::cout << output.at(i) << std::endl;
        }
    }
    
    
    //printLayer(layer);
    
    
    

    /*
    
    */
    
}