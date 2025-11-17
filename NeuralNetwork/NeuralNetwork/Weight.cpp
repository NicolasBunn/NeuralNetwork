#include "Weight.h"
#include <cassert>
#include <random>



void Weight::setWeightValue(float x_, float y_, float val_)
{
    assert(y_ < _weights.size());
    assert(x_ < _weights[y_].size());

    _weights[y_][x_] = val_;
}

void Weight::initAndRandom(size_t dim_x_, size_t dim_y_, float min_, float max_)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dist(min_, max_);

    for (size_t i = 0; i < dim_y_; i++)
    {
        std::vector<float> f;
        _weights.push_back(f);
        for (size_t j = 0; j < dim_x_; j++)
        {
            _weights[i].push_back(dist(gen));
        }
    }

}


void Weight::randomWeight(float x_, float y_, float min_, float max_)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dist(min_, max_);
    for (size_t i = 0; i < _weights.size(); i++)
    {
        for (size_t j = 0; j < _weights[i].size(); j++)
        {
            _weights[i][j] = dist(gen);
        }
    }
}

std::vector<float> Weight::getWeight(int x_) const
{
    assert(x_ < _weights.size());

    std::vector<float> w;
    for (float v : _weights[x_])
    {
        w.emplace_back(v);
    }

    return w;
}

float Weight::getWeightValue(int x_, int y_) const
{
    assert(y_ < _weights.size());
    assert(x_ < _weights[y_].size());

    return _weights[y_][x_];
}

int Weight::getNumbVerticalWeights() const
{
    return _weights.size();
}

int Weight::getNumbHorizontalWeights(int x_) const
{
    assert(x_ < _weights.size());
    return _weights[x_].size();
}

std::vector<float> Weight::getTransposeWeightMatrix(int x_)
{
    std::vector<float> w;
    for (size_t i = 0; i < _weights.size(); i++)
    {
        w.push_back(_weights[i][x_]);
    }
    return w;
}

void Weight::updateAllWeightsValue(float v_)
{
    for (size_t i = 0; i < _weights.size(); i++)
    {
        for (size_t j = 0; j < _weights[i].size(); j++)
        {
            _weights[i][j] += v_;
        }
    }
}

Weight Weight::Transpose()
{
    assert(_weights.size() > 0);

    Weight w;

    std::vector<std::vector<float>> t;
    for (size_t i = 0; i < _weights[0].size(); i++)
    {
        t.push_back({ _weights[i][0] });
        for (size_t j = 1; j < _weights.size(); j++)
        {
            t[i].push_back({ _weights[j][i] });
        }
    }

    w.setWeight(t);

    return w;
}

void  Weight::setWeight(std::vector<std::vector<float>>& w_)
{
    _weights = w_;
}

