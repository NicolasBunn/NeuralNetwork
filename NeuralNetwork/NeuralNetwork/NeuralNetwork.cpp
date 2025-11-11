#include "NeuralNetwork.h"
#include <cassert>

std::vector<float> NeuralNetwork::weight_delta(std::vector<float> weights_, float scalar_)
{
    std::vector<float> out;
    out.reserve(weights_.size());

    for (int i = 0; i < weights_.size(); i++)
    {
        out.push_back(scalar_ * weights_[i]);
    }

    return out;
}

float NeuralNetwork::weight_sum(std::vector<float> a_, std::vector<float> b_)
{
    assert(a_.size() == b_.size());

    float output = 0.0f;

    for (int i = 0; i < a_.size(); i++)
    {
        output += a_[i] * b_[i];
    }

    return output;
}

std::vector<float> NeuralNetwork::neuralNetwork(std::vector<float> input_, Matrix& matrix_)
{
    std::vector<float> r;

    for (int i = 0; i < matrix_.getNumbWeights(); i++)
    {
        r.push_back(weight_sum(input_, matrix_.getWeight(i)));
    }

    return r;
}