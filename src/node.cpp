#include "node.hpp"

Node::Node(activationFunction function, int nbIn) {
    nbInput = nbIn;
    activationfunction = function;
    bias =  200 * (double) (rand() - RAND_MAX/2)/RAND_MAX;
    for (int i = 0; i<nbInput; i++) {
        double newWeight = 200 * (double) (rand() - RAND_MAX/2)/RAND_MAX;
        weights.emplace_back(newWeight);
    }
}

Node::Node() {
    nbInput = 0;
}

double Node::processOutputs(std::vector<double> inputs) {
    if (inputs.size() != nbInput){
        throw std::invalid_argument("Input size incompatible");
    }
    double res = 0;
    for (int i = 0; i<nbInput; i++) {
        res += weights.at(i) * inputs.at(i);
    }
    res += bias;
    return activationfunction(res);
}

double Node::getWeight(int index) {
    if (index < 0 || index > nbInput) {
        throw std::invalid_argument("index out of weight vector");
    }
    return weights.at(index);
}

double Node::getBias() {
    return bias;
}

int Node::getNbInput() {
    return nbInput;
}