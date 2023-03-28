#ifndef NETWORK
#define NETWORK

#include "layer.hpp"

class Network {
    private:
        std::vector<Layer> layers;
    public:
        Network();
};

#endif