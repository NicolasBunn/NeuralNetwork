#include <iostream>
#include <vector>
#include <cassert>
#include "Weight.h"
#include "Matrix.h"
#include "NeuralNetwork.h"

int main(int argc, char* argv)
{
    NeuralNetwork neural_network;

    std::vector<Layer> streetLight;
    streetLight.push_back(Layer{ std::vector<float>{1.0f, 0.0f, 1.0f} });
    streetLight.push_back(Layer{ std::vector<float>{0.0f, 1.0f, 1.0f} });
    streetLight.push_back(Layer{ std::vector<float>{0.0f, 0.0f, 1.0f} });
    streetLight.push_back(Layer{ std::vector<float>{1.0f, 1.0f, 1.0f} });
    streetLight.push_back(Layer{ std::vector<float>{0.0f, 1.0f, 1.0f} });
    streetLight.push_back(Layer{ std::vector<float>{1.0f, 0.0f, 1.0f} });

    neural_network.addInputData(streetLight);

    std::vector<Layer> walk_stop;
    walk_stop.push_back(Layer{ std::vector<float>{0.0f} });
    walk_stop.push_back(Layer{ std::vector<float>{1.0f} });
    walk_stop.push_back(Layer{ std::vector<float>{0.0f} });
    walk_stop.push_back(Layer{ std::vector<float>{1.0f} });
    walk_stop.push_back(Layer{ std::vector<float>{1.0f} });
    walk_stop.push_back(Layer{ std::vector<float>{0.0f} });

    neural_network.addOutputData(walk_stop);
    neural_network.initMiddleLayer(4);
    neural_network.initWeight();

    neural_network.executeNeuralNetwork(5);

    return 0;
}

