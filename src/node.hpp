#ifndef NODE
#define NODE

#include <vector>
#include <random>
#include <stdexcept>
/**
 * @brief Class Node.
 * 
 * Class which represent the behaviour of a Node in an Artificial Neural Network.
 */
class Node {
    private:
        int nbInput; /*! number of input of the node */
        double bias; /*! Node bias */
        std::vector<double> weights;
    public:

        /**
         * @brief Construct a new Node object
         * 
         * Construct a new Node object by creating random weights and a random bias.
         * 
         * @param nbIn corresponds to the number of inputs of the created Node.
         */
        Node(int nbIn = 0);

        /**
         * @brief Egal operator for the node object.
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

};

#endif
