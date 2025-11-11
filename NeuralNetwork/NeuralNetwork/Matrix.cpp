#include "Matrix.h"
#include <cassert>

void Matrix::addWeights(Weight& weight_)
{
    _matrix.push_back(weight_);
}

std::vector<float> Matrix::getWeight(int x_) const
{
    assert(x_ < _matrix.size());
    return _matrix[x_].getWeights();
}

float Matrix::getWeightValue(int x_, int y_) const
{
    assert(x_ < _matrix.size());
    assert(y_ < _matrix[x_].getWeights().size());

    return _matrix[x_].getWeightValue(y_);

}

int Matrix::getNumbWeights()
{
    return _matrix.size();
}

void  Matrix::setWeightValue(float x_, float y_, float val_)
{
    assert(x_ < _matrix.size());
    assert(y_ < _matrix[x_].getWeights().size());

    _matrix[x_].updateWeightValue(y_, val_);
}

