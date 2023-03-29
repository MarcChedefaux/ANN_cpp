#include "node.hpp"

Node::Node(int nbIn) {
    nbInput = nbIn;
    bias = (double) rand() / RAND_MAX;
    for (int i = 0; i<nbInput; i++) {
        double newWeight = (double) rand() / RAND_MAX;
        weights.emplace_back(newWeight);
    }
}

double Node::processOutputs(std::vector<int> inputs) {
    if (inputs.size() != nbInput){
        throw std::invalid_argument("Input size incompatible");
    }
    double res = 0;
    for (int i = 0; i<nbInput; i++) {
        res += weights.at(i) * inputs.at(i);
    }
    res += bias;
    return res;
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