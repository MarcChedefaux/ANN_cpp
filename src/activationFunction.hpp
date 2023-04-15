#ifndef ACTIVATION
#define ACTIVATION

#include<cmath>
#include<vector>

/**
 * @brief Type of an activation function
 * 
 */
typedef double (*activationFunction)(double args);

typedef struct {
    activationFunction function;
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
 * @brief Binary step activation function
 * 
 * @param x 
 * @return double 
 */
double BinaryStep(double x);

/**
 * @brief Sigmoid activation function
 * 
 * @param x 
 * @return double 
 */
double Sigmoid(double x);

/**
 * @brief TanH activation function
 * 
 * @param x 
 * @return double 
 */
double TanHyperbolic(double x);

/**
 * @brief ReLU activation function
 * 
 * @param x 
 * @return double 
 */
double ReLu(double x);

/**
 * @brief Leaky ReLU activation function
 * 
 * @param x 
 * @return double 
 */
double LeakyReLu(double x);

/**
 * @brief Gaussian activation function
 * 
 * @param x 
 * @return double 
 */
double Gaussian(double x);

void setupActivation();

extern activation identity;
extern activation binarystep;
extern activation sigmoid;
extern activation tanhyperbolic;
extern activation relu;
extern activation leakyrelu;
extern activation gaussian;

extern std::vector <activation> ArrayOfActivation;

#endif