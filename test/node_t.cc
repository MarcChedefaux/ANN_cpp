#include "node.hpp"
#include "activationFunction.hpp"
#include <vector>
#include <gtest/gtest.h>

namespace {
    class NodeTest : public ::testing::Test {
        protected:

            virtual void SetUp() {
                n1 = Node(Identity,10);
                n2 = Node(Identity,100);
            }

            virtual void TearDown() {

            }

            void TestCopyConstructor(Node n) {
                Node newN = Node(n);

                ASSERT_EQ(newN.getNbInput(), n.getNbInput());
                
                ASSERT_EQ(newN.getBias(), n.getBias());

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

                EXPECT_FLOAT_EQ(sum, n.processOutputs(in));
            }

            void TestProcessOutputsHalf(Node n) {
                std::vector<double> in;
                for (int i = 0; i<n.getNbInput(); i++) in.emplace_back(0.5);

                double sum = n.getBias(); 
                for (int i = 0; i<n.getNbInput(); i++) sum += 0.5 * n.getWeight(i);

                EXPECT_FLOAT_EQ(sum, n.processOutputs(in));
            }

            void TestProcessOutputs1(Node n) {
                std::vector<double> in;
                for (int i = 0; i<n.getNbInput(); i++) in.emplace_back(1);

                double sum = n.getBias(); 
                for (int i = 0; i<n.getNbInput(); i++) sum += n.getWeight(i);

                EXPECT_FLOAT_EQ(sum, n.processOutputs(in));
            }

            Node n1, n2;
    };

    TEST_F(NodeTest, InputNumber) {
        EXPECT_EQ(n1.getNbInput(), 10);
        EXPECT_EQ(n2.getNbInput(), 100);
    }

    TEST_F(NodeTest, CopyConstructor) {
        TestCopyConstructor(n1);
        TestCopyConstructor(n2);
    }

    TEST_F(NodeTest, ProcessOutputs0) {
        TestProcessOutputs0(n1);
        TestProcessOutputs0(n2);
    }

    TEST_F(NodeTest, ProcessOutputsHalf) {
        TestProcessOutputsHalf(n1);
        TestProcessOutputsHalf(n2);
    }

    TEST_F(NodeTest, ProcessOutputs1) {
        TestProcessOutputs1(n1);
        TestProcessOutputs1(n2);
    }

}