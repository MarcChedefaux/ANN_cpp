#include "node.hpp"
#include "layer.hpp"
#include "activationFunction.hpp"
#include <vector>
#include <random>
#include <fstream>
#include <gtest/gtest.h>

namespace {
    class LayerTest : public ::testing::Test {
        protected:

            virtual void SetUp() {
                l1 = Layer(sigmoid, 10, 100);
                l2 = Layer(gaussian, 300, 10);
                l3 = Layer(identity, 100, 100);
            }

            virtual void TearDown() {
                
            }

            void testSaveLoad(Layer l) {
                std::ofstream file;
                file.open("./test/build/layerTest.bin", std::ios::out | std::ios::binary);
                write(file, l);
                file.close();

                Layer newl;
                std::ifstream infile;
                infile.open("./test/build/layerTest.bin", std::ios::in | std::ios::binary);
                read(infile, newl);
                infile.close();

                ASSERT_EQ(l.getNbInput(), newl.getNbInput());
                
                ASSERT_EQ(l.getNbNodes(), newl.getNbNodes());

                ASSERT_EQ(l.getActivationFunction().index, newl.getActivationFunction().index);
            }

            void testInputLength(Layer l) {
                for (int i = 0; i < l.getNbNodes(); i++) {
                    EXPECT_EQ(l.getNode(i).getNbInput(), l.getNbInput());
                }
            }

            void testOutputLength(Layer l){
                std::vector<double> inputs;
                for (int i = 0; i < l.getNbInput(); i++) {
                    double newIn = 200 * (double) (rand() - RAND_MAX/2)/RAND_MAX;
                    inputs.emplace_back(newIn);
                }
                std::vector<double> outputs = l.processOutputs(inputs);
                EXPECT_EQ(l.getNbNodes(), outputs.size());
            }


            Layer l1, l2, l3;
    };

    TEST_F(LayerTest, SaveAndLoad) {
        testSaveLoad(l1);
        testSaveLoad(l2);
        testSaveLoad(l3);
    }

    TEST_F(LayerTest, InputLength) {
        testInputLength(l1);
        testInputLength(l2);
        testInputLength(l3);
    }

    TEST_F(LayerTest, OutputLength) {
        testOutputLength(l1);
        testOutputLength(l2);
        testOutputLength(l3);
    }

}