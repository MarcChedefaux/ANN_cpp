#include "layer.hpp"

Layer::Layer() {

}

Layer::Layer(activationFunction function, int nbInput, int nbNodes) {
    this->nbInput = nbInput;
    this->nbNodes = nbNodes;
    activationfunction = function;
    for (int i = 0; i < nbNodes; i++) {
        Node newNode(function,nbInput);
        nodes.emplace_back(newNode);
    }
}

std::vector<double> Layer::processOutputs(std::vector<double> inputs) {
    std::vector<double> result;
    for (int i = 0; i < nbNodes; i++) {
        double oneNodeRes = nodes.at(i).processOutputs(inputs);
        result.emplace_back(oneNodeRes);
    }
    return result;
}

int Layer::getNbInput() {
    return nbInput;
}

int Layer::getNbNodes() {
    return nbNodes;
}

activationFunction Layer::getActivationFunction() {
    return activationfunction;
}

Node Layer::getNode(int index) {
    return nodes.at(index);
}