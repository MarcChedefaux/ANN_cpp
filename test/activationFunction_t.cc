#include "activationFunction.hpp"
#include <gtest/gtest.h>

double points[] = {-10, -5, 0, 5, 10};
double resultsI[] = {-10, -5, 0, 5, 10};
double resultsB[] = {0, 0, 1, 1, 1};
double resultsS[] = {4.5397868e-05, 0.006692851, 0.5, 0.9933071, 0.9999546};
double resultsT[] = {-0.9999999958776927, -0.9999092042625951, 0, 0.9999092042625951, 0.9999999958776927};
double resultsR[] = {0, 0, 0, 5, 10};
double resultsL[] = {-1, -0.5, 0, 5, 10};
double resultsG[] = {3.7835059e-44, 1.3887944e-11, 1, 1.3887944e-11, 3.7835059e-44};

TEST(ActivationFunctions, IdentityF) {
    for (int i = 0; i < 5; i++) {
        EXPECT_FLOAT_EQ(Identity(points[i]), resultsI[i]);
    }
}

TEST(ActivationFunctions, BinaryStepF) {
    for (int i = 0; i < 5; i++) {
        EXPECT_FLOAT_EQ(BinaryStep(points[i]), resultsB[i]);
    }
}

TEST(ActivationFunctions, SigmoidF) {
    for (int i = 0; i < 5; i++) {
        EXPECT_FLOAT_EQ(Sigmoid(points[i]), resultsS[i]);
    }
}

TEST(ActivationFunctions, TanHF) {
    for (int i = 0; i < 5; i++) {
        EXPECT_FLOAT_EQ(TanHyperbolic(points[i]), resultsT[i]);
    }
}

TEST(ActivationFunctions, ReLUF) {
    for (int i = 0; i < 5; i++) {
        EXPECT_FLOAT_EQ(ReLu(points[i]), resultsR[i]);
    }
}

TEST(ActivationFunctions, LeakyReLuF) {
    for (int i = 0; i < 5; i++) {
        EXPECT_FLOAT_EQ(LeakyReLu(points[i]), resultsL[i]);
    }
}

TEST(ActivationFunctions, GaussianF) {
    for (int i = 0; i < 5; i++) {
        EXPECT_FLOAT_EQ(Gaussian(points[i]), resultsG[i]);
    }
}