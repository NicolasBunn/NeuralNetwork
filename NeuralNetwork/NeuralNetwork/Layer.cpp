#include "Layer.h"
#include <cassert>

Layer::Layer()
{

}

Layer::Layer(std::vector<float>&& vec_)
{
    _weights = vec_;
}

void Layer::setWeight(std::vector<float>&& vec_)
{
    _weights = vec_;
}

void  Layer::displayWeight() const
{
    std::cout << "[ ";
    for (float v : _weights)
    {
        std::cout << v << "  ";
    }

    std::cout << " ] " << std::endl;
}

float  Layer::getWeightValue(int x_) const
{
    assert(x_ < _weights.size());

    return _weights[x_];

}

std::vector<float> Layer::getWeights() const
{
    return _weights;
}

int Layer::getNbWeight() const
{
    return _weights.size();
}

void Layer::setWeightValue(int x_, float v_)
{
    assert(x_ < _weights.size());
    _weights[x_] = v_;

}

void Layer::addNewWeight(float v_)
{
    _weights.push_back(v_);
}