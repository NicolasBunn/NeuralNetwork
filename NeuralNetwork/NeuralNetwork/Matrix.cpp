#include "Matrix.h"
#include <cassert>
#include <random>


//void Matrix::addWeights(Weight& weight_)
//{
//    _matrix.push_back(weight_);
//}
//
//void Matrix::addWeights(Weight&& weight_)
//{
//    _matrix.emplace_back(weight_);
//}
//
//
//std::vector<float> Matrix::getWeight(int x_) const
//{
//    assert(x_ < _matrix.size());
//    return _matrix[x_].getWeights();
//}
//
//float Matrix::getWeightValue(int x_, int y_) const
//{
//    assert(x_ < _matrix.size());
//    assert(y_ < _matrix[x_].getWeights().size());
//
//    return _matrix[x_].getWeightValue(y_);
//
//}
//
//std::vector<float> Matrix::getWeightTranspose(int x_) const
//{
//    std::vector<float> r;
//    for (size_t i = 0; i < _matrix.size(); i++)
//    {
//        r.push_back(_matrix[i].getWeightValue(x_));
//    }
//    return r;
//}
//
//int Matrix::getNumbWeights()
//{
//    return _matrix.size();
//}
//
//void  Matrix::setWeightValue(float x_, float y_, float val_)
//{
//    assert(x_ < _matrix.size());
//    assert(y_ < _matrix[x_].getWeights().size());
//
//    _matrix[x_].setWeightValue(y_, val_);
//}
//
//void  Matrix::initRandom(float x_, float y_, float min_, float max_)
//{
//    std::random_device rd;
//    std::mt19937 gen(rd());
//    std::uniform_real_distribution<double> dist(min_, max_);
//
//    for (int i = 0; i < x_; i++)
//    {
//        _matrix.push_back(Weight{});
//        for (int j = 0; j < y_; j++)
//        {
//            _matrix[i].addWeightValue(dist(gen));
//        }
//    }
//
//    int v = 0;
//}


