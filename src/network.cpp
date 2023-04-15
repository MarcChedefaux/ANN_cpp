#include "network.hpp"

Network::Network() {
    layersSize = {0};
    nbLayers = 0;
}

Network::Network(std::vector<int> Size, std::vector<activation> activationFunctions){
    layersSize = Size;
    nbLayers = Size.size() - 1;
    for (int i = 0; i<nbLayers; i++) {
        Layer newLayer(activationFunctions.at(i), Size.at(i), Size.at(i+1));
        layers.emplace_back(newLayer);
    }
}

Network::Network(std::vector<int> Size, activation activationfunction) {
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

std::ostream& write(std::ostream& out, Network& obj){
    //nbLayers
    out.write((char*)&obj.nbLayers, sizeof(obj.nbLayers));
    //layersSize
    for (int i=0; i<obj.nbLayers+1; i++) {
        out.write((char*)&obj.layersSize.at(i), sizeof(obj.layersSize.at(i)));
    }
    //layers
    for (int i=0; i<obj.nbLayers; i++) {
        write(out, obj.layers.at(i));
    }

    return out;
}

std::istream& read(std::istream& in, Network& obj) {
    obj.layers.clear();
    obj.nbLayers = 0;
    obj.layersSize.clear();

    in.read((char*)&obj.nbLayers, sizeof(obj.nbLayers));
    for (int i=0; i<obj.nbLayers+1; i++) {
        int newSize;
        in.read((char*)&newSize, sizeof(newSize));
        obj.layersSize.emplace_back(newSize);
    }

    for (int i=0; i<obj.nbLayers; i++) {
        Layer newL;
        read(in, newL);
        obj.layers.emplace_back(newL);
    }

    return in;
}

void Network::LoadNetwork(std::string path) {
    std::ifstream file;
    file.open(path, std::ios::in | std::ios::binary);
    read(file, *this);
    file.close();

}

void Network::SaveNetwork(std::string path) {
    std::ofstream file;
    file.open(path, std::ios::trunc | std::ios::binary);
    write(file, *this);
    file.close();
}
