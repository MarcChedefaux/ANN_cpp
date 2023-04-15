#ifndef LAYER
#define LAYER

#include <vector>
#include "node.hpp"
#include "activationFunction.hpp"

/**
 * @brief Class Layer
 * 
 * which implements all the behaviour of a layer
 * 
 */
class Layer {
    private:
        int nbInput; /*! Number of inputs in this layer*/
        int nbNodes; /*! Number of nodes in this layer*/
        std::vector<Node> nodes; /*! Array of all nodes*/
        activation activationfunction; /*! Activation function used by the nodes of this layer*/
    public :
        /**
         * @brief Construct a new empty Layer object
         * 
         */
        Layer();

        /**
         * @brief Construct a new Layer object
         * 
         * @param function : activation function used by the nodes of this layer
         * @param nbInput : number of inputs in this layer
         * @param nbNodes : number of nodes in this layer
         */
        Layer(activation function, int nbInput, int nbNodes);

        /**
         * @brief Equal operator for the Layer object
         * 
         * @return Layer& 
         */
        Layer& operator=(const Layer&) = default;

        /**
         * @brief process the outputs of this layer
         * 
         * @param inputs : vector of inputs
         * @return std::vector<double>  : vector of outputs
         */
        std::vector<double> processOutputs(std::vector<double> inputs);

        /**
         * @brief Get the NbInput object
         * 
         * @return int 
         */
        int getNbInput();

        /**
         * @brief Get the NbNodes object
         * 
         * @return int 
         */
        int getNbNodes();

        /**
         * @brief Get the Node object at the position index.
         * 
         * @param index : the position of the node we want to access.
         * @return Node 
         */
        Node getNode(int index);

        /**
         * @brief Get the Activation Function object
         * 
         * @return activation
         */
        activation getActivationFunction();

        /**
         * @brief Overload of the write function for the Layer object
         * 
         * @param out 
         * @param obj 
         * @return std::ostream& 
         */
        friend std::ostream& write(std::ostream& out, Layer& obj);

        /**
         * @brief Overload of the read function for the Layer object
         * 
         * @param in 
         * @param obj 
         * @return std::istream& 
         */
        friend std::istream& read(std::istream& in, Layer& obj);

};

#endif