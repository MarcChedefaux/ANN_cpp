#ifndef NODE
#define NODE

#include "activationFunction.hpp"
#include <vector>
#include <random>
#include <stdexcept>
#include <iostream>
/**
 * @brief Class Node.
 * 
 * Class which represent the behaviour of a Node in an Artificial Neural Network.
 */
class Node {
    private:
        int nbInput; /*! number of input of the node */
        double bias; /*! Node bias */
        activationFunction activationfunction; /*! Node activation function*/
        std::vector<double> weights;
    public:

        /**
         * @brief Construct a new Node object
         * 
         * Construct a new Node object by creating random weights and a random bias.
         * 
         * @param nbIn corresponds to the number of inputs of the created Node.
         */
        Node(activationFunction function, int nbIn);

        /**
         * @brief Empty constructor for Node object
         * 
         */
        Node();

        /**
         * @brief Equal operator for the node object.
         * 
         * @return the address Node of the left sided Node object.
         */
        Node& operator=(const Node&) = default;

        /**
         * @brief Method to process the outputs of the node
         *
         *  Method which realise the calculation of the ouput by doing the dot product of the weights by the inputs. Then it add the bias and finally it use the Activation Function on the resulting scalar.
         *  
         * @param inputs : the inputs of the node.
         * @return double : the state of the node after the calculation.
         */
        double processOutputs(std::vector<double> inputs);

        /**
         * @brief Get one of the weight.
         * 
         * @param index of the weight we want.
         * @return double : the weight.
         */
        double getWeight(int index);

        /**
         * @brief Get the Bias.
         * 
         * @return double : the bias.
         */
        double getBias();

        /**
         * @brief Get the number of input.
         * 
         * @return int : the number of input.
         */
        int getNbInput();

        /**
         * @brief Get the Activation Function of the Node
         * 
         * @return activationFunction : the Node Activation Function.
         */
        activationFunction getActivationFunction();

        /**
         * @brief Overload of the write function for the node object
         * 
         * @param out 
         * @param obj 
         * @return std::ostream& 
         */
        friend std::ostream& write(std::ostream& out, Node& obj);

        /**
         * @brief Overload of the read function for the node object
         * 
         * @param out 
         * @param obj 
         * @return std::istream& 
         */
        friend std::istream& read(std::istream& out, Node& obj);

};

#endif
