#ifndef ACTIVATION
#define ACTIVATION

#include<cmath>

/**
 * @brief Type of an activation function
 * 
 */
typedef double (*activationFunction)(double args);

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

#endif