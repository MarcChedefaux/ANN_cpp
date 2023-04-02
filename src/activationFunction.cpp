#include "activationFunction.hpp"

double Identity(double x) {
    return x;
}

double BinaryStep(double x){
    return (x>=0?1:0);
}


double Sigmoid(double x){
    return (double)(1/(1+exp(-x)));
}


double TanHyperbolic(double x){
    return tanh(x);
}


double ReLu(double x){
    return fmax(0,x);
}


double LeakyReLu(double x){
    return (x>=0?x:0.1*x);
}


double Gaussian(double x){
    return exp(-(x*x)); 
}