#include "activationFunction.hpp"

activation identity = {Identity, IdentityPrime, 0};
activation binarystep = {BinaryStep, BinaryStepPrime, 1};
activation sigmoid = {Sigmoid, SigmoidPrime, 2};
activation tanhyperbolic = {TanHyperbolic, TanHyperbolicPrime, 3};
activation relu = {ReLu, ReLuPrime, 4};
activation leakyrelu = {LeakyReLu, LeakyReLuPrime, 5};
activation gaussian = {Gaussian, GaussianPrime, 6};

std::vector<activation> ArrayOfActivation = {identity, binarystep, sigmoid, tanhyperbolic, relu, leakyrelu, gaussian};

double Identity(double x) {
    return x;
}

double IdentityPrime(double x) {
    return 1;
}

double BinaryStep(double x){
    return (x>=0?1:0);
}

double BinaryStepPrime(double x) {
    return 0;
}


double Sigmoid(double x){
    return (double)(1/(1+exp(-x)));
}

double SigmoidPrime(double x) {
    double s = Sigmoid(x);
    return s * (1-s);
}


double TanHyperbolic(double x){
    return tanh(x);
}

double TanHyperbolicPrime(double x){
    double g = TanHyperbolic(x);
    return 1 - g*g;
}

double ReLu(double x){
    return fmax(0,x);
}

double ReLuPrime(double x){
    return (x>=0?1:0);
}

double LeakyReLu(double x){
    return (x>=0?x:0.1*x);
}

double LeakyReLuPrime(double x) {
    return (x>=0?1:0.01);
}

double Gaussian(double x){
    return exp(-(x*x)); 
}

double GaussianPrime(double x) {
    return -2 * x * Gaussian(x);
}