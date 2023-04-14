#include "node.hpp"
#include "activationFunction.hpp"
#include <vector>
#include <gtest/gtest.h>
#include <fstream>

namespace {
    class NodeTest : public ::testing::Test {
        protected:

            virtual void SetUp() {
                nI1 = Node(Identity,10);
                nI2 = Node(Identity,100);
                nB1 = Node(BinaryStep,10);
                nB2 = Node(BinaryStep,100);
                nS1 = Node(Sigmoid,10);
                nS2 = Node(Sigmoid,100);
                nT1 = Node(TanHyperbolic,10);
                nT2 = Node(TanHyperbolic,100);
                nR1 = Node(ReLu,10);
                nR2 = Node(ReLu,100);
                nL1 = Node(LeakyReLu,10);
                nL2 = Node(LeakyReLu,100);
                nG1 = Node(Gaussian,10);
                nG2 = Node(Gaussian,100);
            }

            virtual void TearDown() {

            }

            void TestCopyConstructor(Node n) {
                Node newN = Node(n);

                ASSERT_EQ(newN.getNbInput(), n.getNbInput());
                
                ASSERT_EQ(newN.getBias(), n.getBias());

                ASSERT_EQ(newN.getActivationFunction(), n.getActivationFunction());

                for (int i=0; i < n.getNbInput(); i++) {
                    if (i <= newN.getNbInput()) {
                        EXPECT_EQ(n.getWeight(i), newN.getWeight(i));
                    }
                }
            }

            void testSaveLoad(Node n) {
                std::ofstream file;
                file.open("./test/build/nodeTest.bin", std::ios::trunc | std::ios::binary);
                write(file, n);
                file.close();

                Node newN;
                std::ifstream infile;
                infile.open("./test/build/nodeTest.bin", std::ios::in | std::ios::binary);
                read(infile, newN);
                infile.close();

                ASSERT_EQ(newN.getNbInput(), n.getNbInput());
                
                ASSERT_EQ(newN.getBias(), n.getBias());

                ASSERT_EQ(newN.getActivationFunction(), n.getActivationFunction());

                for (int i=0; i < n.getNbInput(); i++) {
                    if (i <= newN.getNbInput()) {
                        EXPECT_EQ(n.getWeight(i), newN.getWeight(i));
                    }
                }
            }

            void TestProcessOutputs0(Node n) {
                std::vector<double> in;
                for (int i = 0; i<n.getNbInput(); i++) in.emplace_back(0);

                double sum = n.getBias(); 

                activationFunction f = n.getActivationFunction();
                EXPECT_FLOAT_EQ(f(sum), n.processOutputs(in));
            }

            void TestProcessOutputsHalf(Node n) {
                std::vector<double> in;
                for (int i = 0; i<n.getNbInput(); i++) in.emplace_back(0.5);

                double sum = n.getBias(); 
                for (int i = 0; i<n.getNbInput(); i++) sum += 0.5 * n.getWeight(i);

                activationFunction f = n.getActivationFunction();
                EXPECT_FLOAT_EQ(f(sum), n.processOutputs(in));
            }

            void TestProcessOutputs1(Node n) {
                std::vector<double> in;
                for (int i = 0; i<n.getNbInput(); i++) in.emplace_back(1);

                double sum = n.getBias(); 
                for (int i = 0; i<n.getNbInput(); i++) sum += n.getWeight(i);
                
                activationFunction f = n.getActivationFunction();
                EXPECT_FLOAT_EQ(f(sum), n.processOutputs(in));
            }

            Node nI1, nI2, nB1, nB2, nS1, nS2, nT1, nT2, nR1, nR2, nL1, nL2, nG1, nG2;
    };

    TEST_F(NodeTest, InputNumber) {
        EXPECT_EQ(nI1.getNbInput(), 10);
        EXPECT_EQ(nI2.getNbInput(), 100);
        EXPECT_EQ(nB1.getNbInput(), 10);
        EXPECT_EQ(nB2.getNbInput(), 100);
        EXPECT_EQ(nS1.getNbInput(), 10);
        EXPECT_EQ(nS2.getNbInput(), 100);
        EXPECT_EQ(nT1.getNbInput(), 10);
        EXPECT_EQ(nT2.getNbInput(), 100);
        EXPECT_EQ(nR1.getNbInput(), 10);
        EXPECT_EQ(nR2.getNbInput(), 100);
        EXPECT_EQ(nL1.getNbInput(), 10);
        EXPECT_EQ(nL2.getNbInput(), 100);
        EXPECT_EQ(nG1.getNbInput(), 10);
        EXPECT_EQ(nG2.getNbInput(), 100);
    }

    TEST_F(NodeTest, CopyConstructor) {
        TestCopyConstructor(nI1);
        TestCopyConstructor(nI2);
        TestCopyConstructor(nB1);
        TestCopyConstructor(nB2);
        TestCopyConstructor(nS1);
        TestCopyConstructor(nS2);
        TestCopyConstructor(nT1);
        TestCopyConstructor(nT2);
        TestCopyConstructor(nR1);
        TestCopyConstructor(nR2);
        TestCopyConstructor(nL1);
        TestCopyConstructor(nL2);
        TestCopyConstructor(nG1);
        TestCopyConstructor(nG2);
    }

    TEST_F(NodeTest, SaveAndLoad) {
        testSaveLoad(nI1);
        testSaveLoad(nI2);
        testSaveLoad(nB1);
        testSaveLoad(nB2);
        testSaveLoad(nS1);
        testSaveLoad(nS2);
        testSaveLoad(nT1);
        testSaveLoad(nT2);
        testSaveLoad(nR1);
        testSaveLoad(nR2);
        testSaveLoad(nL1);
        testSaveLoad(nL2);
        testSaveLoad(nG1);
        testSaveLoad(nG2);
    }

    TEST_F(NodeTest, IdentityProcessOutputs0) {
        TestProcessOutputs0(nI1);
        TestProcessOutputs0(nI2);
    }

    TEST_F(NodeTest, IdentityProcessOutputsHalf) {
        TestProcessOutputsHalf(nI1);
        TestProcessOutputsHalf(nI2);
    }

    TEST_F(NodeTest, IdentityProcessOutputs1) {
        TestProcessOutputs1(nI1);
        TestProcessOutputs1(nI2);
    }

    
    TEST_F(NodeTest, BinaryStepProcessOutputs0) {
        TestProcessOutputs0(nB1);
        TestProcessOutputs0(nB2);
    }

    TEST_F(NodeTest, BinaryStepProcessOutputsHalf) {
        TestProcessOutputsHalf(nB1);
        TestProcessOutputsHalf(nB2);
    }

    TEST_F(NodeTest, BinaryStepProcessOutputs1) {
        TestProcessOutputs1(nB1);
        TestProcessOutputs1(nB2);
    }
    
    
    TEST_F(NodeTest, SigmoidProcessOutputs0) {
        TestProcessOutputs0(nS1);
        TestProcessOutputs0(nS2);
    }

    TEST_F(NodeTest, SigmoidProcessOutputsHalf) {
        TestProcessOutputsHalf(nS1);
        TestProcessOutputsHalf(nS2);
    }

    TEST_F(NodeTest, SigmoidProcessOutputs1) {
        TestProcessOutputs1(nS1);
        TestProcessOutputs1(nS2);
    }
    
    
    TEST_F(NodeTest, TanHProcessOutputs0) {
        TestProcessOutputs0(nT1);
        TestProcessOutputs0(nT2);
    }

    TEST_F(NodeTest, TanHProcessOutputsHalf) {
        TestProcessOutputsHalf(nT1);
        TestProcessOutputsHalf(nT2);
    }

    TEST_F(NodeTest, TanHProcessOutputs1) {
        TestProcessOutputs1(nT1);
        TestProcessOutputs1(nT2);
    }
        
    
    TEST_F(NodeTest, ReLuProcessOutputs0) {
        TestProcessOutputs0(nR1);
        TestProcessOutputs0(nR2);
    }

    TEST_F(NodeTest, ReLuProcessOutputsHalf) {
        TestProcessOutputsHalf(nR1);
        TestProcessOutputsHalf(nR2);
    }

    TEST_F(NodeTest, ReLuProcessOutputs1) {
        TestProcessOutputs1(nR1);
        TestProcessOutputs1(nR2);
    }
    

    TEST_F(NodeTest, LeakyReLuProcessOutputs0) {
        TestProcessOutputs0(nL1);
        TestProcessOutputs0(nL2);
    }

    TEST_F(NodeTest, LeakyReLuProcessOutputsHalf) {
        TestProcessOutputsHalf(nL1);
        TestProcessOutputsHalf(nL2);
    }

    TEST_F(NodeTest, LeakyReLuProcessOutputs1) {
        TestProcessOutputs1(nL1);
        TestProcessOutputs1(nL2);
    }


    TEST_F(NodeTest, GaussianProcessOutputs0) {
        TestProcessOutputs0(nG1);
        TestProcessOutputs0(nG2);
    }

    TEST_F(NodeTest, GaussianProcessOutputsHalf) {
        TestProcessOutputsHalf(nG1);
        TestProcessOutputsHalf(nG2);
    }

    TEST_F(NodeTest, GaussianProcessOutputs1) {
        TestProcessOutputs1(nG1);
        TestProcessOutputs1(nG2);
    }


}