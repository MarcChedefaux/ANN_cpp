#ifndef NETWORK
#define NETWORK

#include "layer.hpp"
#include "activationFunction.hpp"
#include "parameter.hpp"
#include "dataset.hpp"
#include <fstream>
#include <iostream>
#include <algorithm>

/**
 * @brief Class Network
 * 
 * which implements all the behaviour of a Network.
 */
class Network {
    private:
        std::vector<Layer> layers; /*! Layers of the network*/
        int nbLayers; /*! Number of layers*/
        std::vector<int> layersSize; /*! Size of the differents layers */ 
    public:
        /**
         * @brief Construct a new empty Network object
         * 
         */
        Network();

        /**
         * @brief Construct a new Network object
         * 
         * @param Size : the differents sizes of the layers.
         * @param activationFunctions : the differents activations function used by the layers.
         */
        Network(std::vector<int> Size, std::vector<activation> activationFunctions);

        /**
         * @brief Construct a new Network object
         * 
         * @param Size : the differents sizes of the layers.
         * @param activationfunction : the activation function used by all the layers.
         */
        Network(std::vector<int> Size, activation activationfunction);

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
         * @brief Process the training of the model on the selected dataset
         * 
         * @param ds
         */
        void train(dataset ds);
        
        /**
         * @brief Evaluate the Network on the data.
         * 
         * @param d 
         * @return double 
         */
        double evaluate(data d);

        /**
         * @brief Get the Layer Size object
         * 
         * @param index 
         * @return int 
         */
        int getLayerSize(int index);

        /**
         * @brief Get the Number Layers object
         * 
         * @return int 
         */
        int getNumberLayers();

        /**
         * @brief Get the Layer object
         * 
         * @param index 
         * @return Layer 
         */
        Layer getLayer(int index);

        /**
         * @brief Overload of the write function for the Network object
         * 
         * @param out 
         * @param obj 
         * @return std::ostream& 
         */
        friend std::ostream& write(std::ostream& out, Network& obj);

        /**
         * @brief Overload of the read function for the Network object
         * 
         * @param in 
         * @param obj 
         * @return std::istream& 
         */
        friend std::istream& read(std::istream& in, Network& obj);

        /**
         * @brief Load a network from a binary file situated on the path
         * 
         * @param path : path to the network .bin file
         */
        void LoadNetwork(std::string path);

        /**
         * @brief Save the network to a binary file situated on the path
         * 
         * @param path : path to the newly created .bin file
         */
        void SaveNetwork(std::string path);
};

#endif