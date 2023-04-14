#include "node.hpp"
#include "layer.hpp"
#include "network.hpp"
#include "activationFunction.hpp"
#include <vector>
#include <random>
#include <gtest/gtest.h>

namespace {
    class NetworkTest : public ::testing::Test {
        protected:

            virtual void SetUp() {
                std::vector<int> size1 = {10, 100, 200, 100, 10};
                std::vector<int> size2 = {10, 1000, 10000, 10000, 1000, 10};
                std::vector<activationFunction> af1 = {Sigmoid, ReLu, TanHyperbolic, Gaussian};

                n1 = Network(size1, af1);
                n2 = Network(size2, BinaryStep);
            }

            virtual void TearDown() {
                
            }

            void testSaveLoad(Network n) {
                n.SaveNetwork("./n1.bin");

                Network newN;
                newN.LoadNetwork("./n1.bin");

                EXPECT_EQ(newN.getNumberLayers(), n.getNumberLayers());

                for (int i=0; i<n.getNumberLayers()+1; i++) {
                    EXPECT_EQ(newN.getLayerSize(i), n.getLayerSize(i));
                }
            }

            void testNbLayers(Network n, int expected) {
                EXPECT_EQ(n.getNumberLayers(), expected);
            } 

            void testLayersSize(Network n) {
                for (int i = 0; i < n.getNumberLayers(); i++) {
                    EXPECT_EQ(n.getLayer(i).getNbInput(), n.getLayerSize(i));
                }

                for (int i = 0; i < n.getNumberLayers(); i++) {
                    EXPECT_EQ(n.getLayer(i).getNbNodes(), n.getLayerSize(i+1));
                }
            }

            void testProcessOutputsSize(Network n){
                std::vector<double> test = {1,2,3,4,5,6,7,8,9,10};
                std::vector<double> res = n.processOutputs(test);
                EXPECT_EQ(res.size(), 10);
            }


            Network n1, n2;
    };

    TEST_F(NetworkTest, SaveLoadModel) {
        testSaveLoad(n1);
        //testSaveLoad(n2);
    }

    TEST_F(NetworkTest, LayersNumber) {
        testNbLayers(n1, 4);
        testNbLayers(n2, 5);
    }

    TEST_F(NetworkTest, LayersSize) {
        testLayersSize(n1);
        testLayersSize(n2);
    }

    TEST_F(NetworkTest, OutputSize) {
        testProcessOutputsSize(n1);
        testProcessOutputsSize(n2);
    }

}