#include "NeuralNetwork.h"
#include <cassert>
#include <random>

void NeuralNetwork::executeNeuralNetwork(int numb_iteration_)
{
    float layer_2_error = 0.0f;
    float layer_1_delta = 0.0f;
    float layer_2_delta = 0.0f;
    Layer layer_0, layer_1, layer_2;
    for (int it = 0; it < numb_iteration_; it++)
    {
        for (size_t i = 0; i < _input_data.size(); i++)
        {
            layer_0 = _input_data[i];
            layer_1 = dot(layer_0, _w_0_1);
            relu(layer_1);
            layer_2 = dot(layer_1, _w_1_2);

            layer_2_error += diff(layer_2, _ouput_data[i]) * diff(layer_2, _ouput_data[i]);
            layer_2_delta = diff(layer_2, _ouput_data[i]);
            layer_1_delta = mul(_w_1_2.Transpose(), layer_1_delta) * relu2Deriv(layer_1);

            _w_1_2.updateAllWeightsValue(-_alpha * mul(layer_1, layer_2_delta));
            _w_0_1.updateAllWeightsValue(-_alpha * mul(layer_0, layer_1_delta));

        }
    }
}

void NeuralNetwork::relu(Layer& layer_)
{
    for (size_t i = 0; i < layer_.getNbWeight(); i++)
    {
        layer_.setWeightValue(i, layer_.getWeightValue(i)> 0 * layer_.getWeightValue(i));

    }
}

float NeuralNetwork::relu2Deriv(Layer& layer_)
{
    for (size_t i = 0; i < layer_.getNbWeight(); i++)
    {
        if (layer_.getWeightValue(i) <= 0)
        {
            return 0.0f;
        }
    }

    return 1.0f;
}


void NeuralNetwork::setAlpha(float a_)
{
    _alpha = a_;
}

void NeuralNetwork::addInputData(std::vector<Layer>& input_data_)
{
    _input_data = input_data_;
}

void NeuralNetwork::addOutputData(std::vector<Layer>& output_data_)
{
    _ouput_data = output_data_;
}

void  NeuralNetwork::initWeight()
{
    assert(_input_data.size() > 0);
    assert(_ouput_data.size() > 0);

    int layer_input_size = _input_data[0].getWeights().size();
    int layer_middle_size = _middle_layer.getWeights().size();
    int layer_output_size = _ouput_data[0].getWeights().size();

    _w_0_1.initAndRandom(layer_middle_size, layer_input_size);
    _w_1_2.initAndRandom(layer_output_size, layer_middle_size);

    float v = 0.0f;
}

void NeuralNetwork::initMiddleLayer(int numb_, bool random_)
{
    for (int i = 0; i < numb_; i++)
    {
        if (random_)
        {
            _middle_layer.addNewWeight(randomNumber());
        }
        else
        {
            _middle_layer.addNewWeight(0.0f);
        }

    }
}

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

Layer NeuralNetwork::dot(Layer& layer_entry_, Weight& weight_)
{
    int layer_weight = layer_entry_.getNbWeight();
    int weight_vertical = weight_.getNumbVerticalWeights();

    assert(layer_entry_.getNbWeight() == weight_.getNumbVerticalWeights());

    Layer layer;

    for (size_t i = 0; i < weight_.getNumbHorizontalWeights(); i++)
    {
        float v = 0.0f;
        for (size_t j = 0; j < weight_.getNumbVerticalWeights(); j++)
        {
            v += weight_.getWeightValue(i, j) * layer_entry_.getWeightValue(j);
        }
        layer.addNewWeight(v);
    }

    return layer;
}



float NeuralNetwork::randomNumber(float min_, float max_)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dist(min_, max_);
    return dist(gen);
}


float NeuralNetwork::relu(float x_)
{
    return (x_ > 0) * x_;
}

float NeuralNetwork::relu2Deriv(float v_)
{
    return v_ > 0;
}

float NeuralNetwork::sum(const Layer& layer_1_, const Layer& layer_2_)
{
    assert(layer_1_.getNbWeight() == layer_2_.getNbWeight());

    float r = 0.0f;
    for (size_t i = 0; i < layer_1_.getNbWeight(); i++)
    {
        r += layer_1_.getWeightValue(i) + layer_2_.getWeightValue(i);
    }

    return r;

}

float NeuralNetwork::diff(const Layer& layer_1_, const Layer& layer_2_)
{
    assert(layer_1_.getNbWeight() == layer_2_.getNbWeight());

    float r = 0.0f;
    for (size_t i = 0; i < layer_1_.getNbWeight(); i++)
    {
        r += layer_1_.getWeightValue(i) - layer_2_.getWeightValue(i);
    }

    return r;
    
}

float NeuralNetwork::mul(const Weight& weight_, float v_)
{
    float r = 0.0f;
    for (size_t i = 0; i < weight_.getNumbVerticalWeights(); i++)
    {
        for (size_t j = 0; j < weight_.getNumbHorizontalWeights(i); j++)
        {
            r *= weight_.getWeightValue(j,i) * v_;
        }
    }

    return r;
}

float NeuralNetwork::mul(const Layer& layer_, float v_)
{
    float r = 0.0f;

    for (size_t i = 0; i < layer_.getNbWeight(); i++)
    {
        r += v_ * layer_.getWeightValue(i);
    }

    return r;
}



