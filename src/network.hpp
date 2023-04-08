#ifndef NETWORK
#define NETWORK

#include "layer.hpp"
#include "activationFunction.hpp"

/**
 * @brief Class Network
 * 
 * which implements all the behaviour of a Network.
 */
class Network {
    private:
        std::vector<Layer> layers; /*! Layers of the network*/
        std::vector<int> layersSize; /*! Size of the differents layers */ 
    public:
        /**
         * @brief Construct a new Network object
         * 
         * @param Size : the differents sizes of the layers.
         * @param activationFunctions : the differents activations function used by the layers.
         */
        Network(std::vector<int> Size, std::vector<activationFunction> activationFunctions);

        /**
         * @brief Construct a new Network object
         * 
         * @param Size : the differents sizes of the layers.
         * @param activationfunction : the activation function used by all the layers.
         */
        Network(std::vector<int> Size, activationFunction activationfunction);

        /**
         * @brief Equal operator for the Network object
         * 
         * @return Network& 
         */
        Network& operator=(const Network&) = default;

        /**
         * @brief Process of the network layer by layer.
         * 
         * @param inputs : vector of inputs.
         * @return std::vector<double> : vector of outputs.
         */
        std::vector<double> processOutputs(std::vector<double> inputs);

        /**
         * @brief Get the Layer Size object
         * 
         * @param index 
         * @return int 
         */
        int getLayerSize(int index);

        /**
         * @brief Get the Layer object
         * 
         * @param index 
         * @return Layer 
         */
        Layer getLayer(int index);
};

#endif