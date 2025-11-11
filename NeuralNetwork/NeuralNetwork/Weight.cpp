#include "Weight.h"
#include <cassert>


void Weight::setWeight(std::vector<float>&& vec_)
{
    _weight_vec = vec_;
}

void  Weight::displayWeight() const
{
    std::cout << "[ ";
    for (float v : _weight_vec)
    {
        std::cout << v << "  ";
    }

    std::cout << " ] " << std::endl;
}

float  Weight::getWeightValue(int x_) const
{
    assert(x_ < _weight_vec.size());

    return _weight_vec[x_];

}

std::vector<float> Weight::getWeights() const
{
    return _weight_vec;
}

void Weight::updateWeightValue(int x_,float v_)
{
   assert(x_ < _weight_vec.size());
   _weight_vec[x_] = v_;

}
