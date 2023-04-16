#ifndef NODE
#define NODE

#include "activationFunction.hpp"
#include "parameter.hpp"
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
        activation activationfunction; /*! Node activation function*/
        double error = 0; /*! Error used for the backpropagation*/
        std::vector<double> weights;
    public:

        /**
         * @brief Construct a new Node object
         * 
         * Construct a new Node object by creating random weights and a random bias.
         * 
         * @param nbIn corresponds to the number of inputs of the created Node.
         */
        Node(activation function, int nbIn);

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
         * @brief Method to process the error if the node is situated on the output layer
         * 
         * @param input
         * @param output 
         * @param desiredOutput 
         */
        void initError(std::vector<double> inputs, double output, double desiredOutput);

        /**
         * @brief Method to process the error using the backpropagation method
         * 
         * @param input
         * @param sumOfWeightedError 
         */
        void processError(std::vector<double> inputs, double sumOfWeightedError);

        /**
         * @brief Get the weighted error that we'll use for the backpropagation
         * 
         * @param index 
         * @return double 
         */
        double getWeightedError(int index);

        /**
         * @brief Apply Gradients calculated by the backpropagation
         * 
         * @param inputs : the inputs of the node.
         */
        void applyGradient(std::vector<double> inputs);

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
         * @return activation : the Node Activation Function.
         */
        activation getActivationFunction();

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
         * @param in 
         * @param obj 
         * @return std::istream& 
         */
        friend std::istream& read(std::istream& in, Node& obj);

};

#endif
