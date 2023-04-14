#include "network.hpp"

Network::Network() {
    layersSize = {0};
    nbLayers = 0;
}

Network::Network(std::vector<int> Size, std::vector<activationFunction> activationFunctions){
    layersSize = Size;
    nbLayers = Size.size() - 1;
    for (int i = 0; i<nbLayers; i++) {
        Layer newLayer(activationFunctions.at(i), Size.at(i), Size.at(i+1));
        layers.emplace_back(newLayer);
    }
}

Network::Network(std::vector<int> Size, activationFunction activationfunction) {
    layersSize = Size;
    nbLayers = Size.size() - 1;
    for (int i = 0; i<nbLayers; i++) {
        Layer newLayer(activationfunction, Size.at(i), Size.at(i+1));
        layers.emplace_back(newLayer);
    }
}

std::vector<double> Network::processOutputs(std::vector<double> inputs){
    std::vector<double> res = inputs;
    for (int i=0; i<nbLayers; i++) {
        res = layers.at(i).processOutputs(res);
    }
    return res;
}

int Network::getLayerSize(int index) {
    return layersSize.at(index);
}

int Network::getNumberLayers() {
    return nbLayers;
}


Layer Network::getLayer(int index) {
    return layers.at(index);
}

void Network::LoadNetwork(std::string path) {
    
}

void Network::SaveNetwork(std::string path) {

}
