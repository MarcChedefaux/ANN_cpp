#include "dataset.hpp"

dataset generateDataset1(int nbTrain, int nbTest) {
    dataset ds;
    ds.name = "checkers";
    ds.nbInput = 2;
    ds.nbOutput = 2;

    data train;
    train.dataCount = nbTrain;
    train.classes = {"Bleu", "Orange"};
    train.inputs.clear();
    train.outputs.clear();
    for (int i = 0; i < nbTrain; i++) {
        std::vector<double> newPos;
        std::vector<double> out;
        switch (i%4)
        {
        case 0:{
            double x = 10 * (double) (rand())/RAND_MAX;
            double y = 10 * (double) (rand())/RAND_MAX;
            newPos = {x,y};
            out = {1,0};
            break;
        }
            
        case 1:{
            double x = -10 * (double) (rand())/RAND_MAX;
            double y = -10 * (double) (rand())/RAND_MAX;
            newPos = {x,y};
            out = {1,0};
            break;
        }
            
        case 2:{
            double x = -10 * (double) (rand())/RAND_MAX;
            double y = 10 * (double) (rand())/RAND_MAX;
            newPos = {x,y};
            out = {0,1};
            break;
        }
            
        case 3: {
            double x = 10 * (double) (rand())/RAND_MAX;
            double y = -10 * (double) (rand())/RAND_MAX;
            newPos = {x,y};
            out = {0,1};
            break;
        }
            
        default:
            break;
        }
        train.inputs.emplace_back(newPos);
        train.outputs.emplace_back(out);
    }

    data test;
    test.dataCount = nbTest;
    test.classes = {"Bleu", "Orange"};
    test.inputs.clear();
    test.outputs.clear();
    for (int i = 0; i < nbTest; i++) {
        std::vector<double> newPos;
        std::vector<double> out;
        switch (i%4)
        {
        case 0:{
            double x = 10 * (double) (rand())/RAND_MAX;
            double y = 10 * (double) (rand())/RAND_MAX;
            newPos = {x,y};
            out = {1,0};
            break;
        }
            
        case 1:{
            double x = -10 * (double) (rand())/RAND_MAX;
            double y = -10 * (double) (rand())/RAND_MAX;
            newPos = {x,y};
            out = {1,0};
            break;
        }
            
        case 2:{
            double x = -10 * (double) (rand())/RAND_MAX;
            double y = 10 * (double) (rand())/RAND_MAX;
            newPos = {x,y};
            out = {0,1};
            break;
        }
            
        case 3: {
            double x = 10 * (double) (rand())/RAND_MAX;
            double y = -10 * (double) (rand())/RAND_MAX;
            newPos = {x,y};
            out = {0,1};
            break;
        }
            
        default:
            break;
        }
        test.inputs.emplace_back(newPos);
        test.outputs.emplace_back(out);
    }

    ds.train = train;
    ds.test = test;

    return ds;
}