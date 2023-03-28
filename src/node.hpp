#ifndef NODE
#define NODE

#include <vector>
class Node {
    private:
        int nbInput;
        double bias;
        std::vector<double> weights;
    public:
        Node();
};

#endif
