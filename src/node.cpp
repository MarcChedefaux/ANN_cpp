#include "node.hpp"

Node::Node(activation function, int nbIn) {
    nbInput = nbIn;
    activationfunction = function;
    bias =  2 * MAX_WEIGHT * (double) (rand() - RAND_MAX/2)/RAND_MAX;
    for (int i = 0; i<nbInput; i++) {
        double newWeight = 2 * MAX_WEIGHT * (double) (rand() - RAND_MAX/2)/RAND_MAX;
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
    return activationfunction.function(res);
}

void Node::initError(std::vector<double> inputs, double output, double desiredOutput) {
    double res = 0;
    for (int i = 0; i<nbInput; i++) {
        res += weights.at(i) * inputs.at(i);
    }
    res += bias;

    error = activationfunction.derivative(res) * (output - desiredOutput);
}

void Node::processError(std::vector<double> inputs, double sumOfWeightedError) {
    double res = 0;
    for (int i = 0; i<nbInput; i++) {
        res += weights.at(i) * inputs.at(i);
    }
    res += bias;

    error = activationfunction.derivative(res) * sumOfWeightedError;
}

void Node::applyGradient(std::vector<double> inputs) {
    for (int i = 0; i<nbInput; i++) {
        weights.at(i) = weights.at(i) - LEARNING_RATE * error *  inputs.at(i);
    }
}

double Node::getWeightedError(int index) {
    return weights.at(index) * error;
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

activation Node::getActivationFunction() {
    return activationfunction;
}

std::ostream& write(std::ostream& out, Node& obj) {
    //nbInput
    out.write((char*)&obj.nbInput, sizeof(obj.nbInput));
    //bias
    out.write(reinterpret_cast<const char*>(&obj.bias), sizeof(obj.bias));
    //activationfunction
    out.write((char*)&obj.activationfunction.index, sizeof(obj.activationfunction.index));
    //weights
    for (int i = 0; i<obj.nbInput; i++) {
        out.write(reinterpret_cast<const char*>(&obj.weights.at(i)), sizeof(obj.weights.at(i)));
    }

    return out;
}

std::istream& read(std::istream& in, Node& obj) {
    obj.weights.clear();
    obj.bias = 0;
    obj.nbInput = 0;
    obj.activationfunction = identity;

    in.read((char*)&obj.nbInput, sizeof(obj.nbInput));
    in.read(reinterpret_cast<char*>(&obj.bias), sizeof(obj.bias));
    int activationIndex;
    in.read((char*)&activationIndex, sizeof(activationIndex));
    obj.activationfunction = ArrayOfActivation.at(activationIndex);
    for (int i=0; i<obj.nbInput; i++) {
        double newWeight;
        in.read(reinterpret_cast<char*>(&newWeight), sizeof(newWeight));
        obj.weights.emplace_back(newWeight);
    }
    return in;
}