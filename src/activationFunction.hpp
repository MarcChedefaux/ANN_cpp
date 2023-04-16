#ifndef ACTIVATION
#define ACTIVATION

#include<cmath>
#include<vector>

/**
 * @brief Type of an activation function
 * 
 */
typedef double (*activationFunction)(double args);

/**
 * @brief Type of the activation with its index to find it back from serialization.
 * 
 */
typedef struct {
    activationFunction function;
    activationFunction derivative;
    int index;
} activation;


/**
 * @brief Identity activation function
 * 
 * @param x 
 * @return double 
 */
double Identity(double x);

/**
 * @brief Identity derivative
 * 
 * @param x 
 * @return double 
 */
double IdentityPrime(double x);

/**
 * @brief Binary step activation function
 * 
 * @param x 
 * @return double 
 */
double BinaryStep(double x);

/**
 * @brief Binary Step derivative
 * 
 * @param x 
 * @return double 
 */
double BinaryStepPrime(double x);

/**
 * @brief Sigmoid activation function
 * 
 * @param x 
 * @return double 
 */
double Sigmoid(double x);

/**
 * @brief Sigmoid derivative
 * 
 * @param x 
 * @return double 
 */
double SigmoidPrime(double x);

/**
 * @brief TanH activation function
 * 
 * @param x 
 * @return double 
 */
double TanHyperbolic(double x);

/**
 * @brief TanH derivative
 * 
 * @param x 
 * @return double 
 */
double TanHyperbolicPrime(double x);

/**
 * @brief ReLU activation function
 * 
 * @param x 
 * @return double 
 */
double ReLu(double x);

/**
 * @brief ReLu derivative
 * 
 * @param x 
 * @return double 
 */
double ReLuPrime(double x);

/**
 * @brief Leaky ReLU activation function
 * 
 * @param x 
 * @return double 
 */
double LeakyReLu(double x);

/**
 * @brief LeakyReLu derivative
 * 
 * @param x 
 * @return double 
 */
double LeakyReLuPrime(double x);

/**
 * @brief Gaussian activation function
 * 
 * @param x 
 * @return double 
 */
double Gaussian(double x);

/**
 * @brief Gaussian derivative
 * 
 * @param x 
 * @return double 
 */
double GaussianPrime(double x);

extern activation identity;
extern activation binarystep;
extern activation sigmoid;
extern activation tanhyperbolic;
extern activation relu;
extern activation leakyrelu;
extern activation gaussian;

extern std::vector <activation> ArrayOfActivation;

#endif