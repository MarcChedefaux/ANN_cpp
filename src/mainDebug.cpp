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
        //std::cout << "Node " << i << std::endl;
        //printNode(l.getNode(i));
    }
    std::cout << "--------" << std::endl;
}

void printNetwork(Network n) {
    std::cout << "---Network---" << std::endl;
    std::cout << "nbLayer : " << n.getNumberLayers() << std::endl;
    std::cout << "Layers size : ";
    for (int i=0; i<n.getNumberLayers()+1; i++) {
        std::cout << n.getLayerSize(i) << " / ";
    } 
    std::cout << std::endl;
    for (int i=0; i<n.getNumberLayers(); i++){
        std::cout << "Layer " << i << std::endl;
        printLayer(n.getLayer(i));
    }
}

int main() {
    bool save = false;

    if (save) {
        std::vector<int> size = {2,4,5,9,10};
        std::vector<activation> act = {identity, gaussian, binarystep, sigmoid};
        Network net(size, act);

        printNetwork(net);
        std::cout << std::endl << std::endl;
        std::vector<double> input = {1,3};
        std::vector<double> output = net.processOutputs(input);

        for (int i=0; i<output.size(); i++) {
            std::cout << output.at(i) << std::endl;
        }

        net.SaveNetwork("net.bin");

    }
    else {
        Network net;
        net.LoadNetwork("net.bin");


        printNetwork(net);
        std::cout << std::endl << std::endl;
        std::vector<double> input = {1,3};
        std::vector<double> output = net.processOutputs(input);

        for (int i=0; i<output.size(); i++) {
            std::cout << output.at(i) << std::endl;
        }
    }
    
}