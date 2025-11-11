#pragma once

#include "Weight.h"

class Matrix
{
public:

    void               addWeights(Weight& weight_);
    void              setWeightValue(float x_, float y_, float val_);

    std::vector<float> getWeight(int x_) const;
    float              getWeightValue(int x_, int y_) const;
    int                getNumbWeights();

private:
    std::vector<Weight> _matrix;
};

