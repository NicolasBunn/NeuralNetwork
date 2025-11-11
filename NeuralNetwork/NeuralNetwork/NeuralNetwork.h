#pragma once

#include "Matrix.h"
#include <vector>

class NeuralNetwork
{
    public:

        static std::vector<float> weight_delta(std::vector<float> weights_, float scalar_);
        static float weight_sum(std::vector<float> a_, std::vector<float> b_);
        static std::vector<float> neuralNetwork(std::vector<float> input_, Matrix& matrix_);

};

