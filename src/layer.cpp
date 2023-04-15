#include "layer.hpp"

Layer::Layer() {

}

Layer::Layer(activation function, int nbInput, int nbNodes) {
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

activation Layer::getActivationFunction() {
    return activationfunction;
}

Node Layer::getNode(int index) {
    return nodes.at(index);
}

std::ostream& write(std::ostream& out, Layer& obj){
    //NbInput
    out.write((char*)&obj.nbInput, sizeof(obj.nbInput));
    //NbNodes
    out.write((char*)&obj.nbNodes, sizeof(obj.nbNodes));
    //activationfunction
    out.write((char*)&obj.activationfunction.index, sizeof(obj.activationfunction.index));
    //Nodes
    for (int i = 0; i < obj.nbNodes; i++) {
        write(out, obj.nodes.at(i));
    }
    return out;
}

std::istream& read(std::istream& in, Layer& obj) {
    obj.nodes.clear();
    obj.nbInput = 0;
    obj.nbNodes = 0;
    obj.activationfunction = identity;

    in.read((char*)&obj.nbInput, sizeof(obj.nbInput));
    in.read((char*)&obj.nbNodes, sizeof(obj.nbNodes));
    int activationIndex;
    in.read((char*)&activationIndex, sizeof(activationIndex));
    obj.activationfunction = ArrayOfActivation.at(activationIndex);
    for (int i=0; i<obj.nbNodes; i++) {
        Node newN;
        read(in, newN);
        obj.nodes.emplace_back(newN);
    }
    return in;
}
