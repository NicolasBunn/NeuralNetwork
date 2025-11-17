#pragma once
#include <iostream>
#include <vector>

class Weight
{

public:

    void setWeightValue(float x_, float y_, float val_);
    void initAndRandom(size_t dim_x_, size_t dim_y_, float min_ = -1.0f, float max_ = 1.0f);
    void randomWeight(float x_, float y_, float min_ = -1.0f, float max_ = 1.0f);
    void setWeight(std::vector<std::vector<float>>& w_);

    std::vector<float> getWeight(int x_) const;
    float              getWeightValue(int x_, int y_) const;
    int                getNumbVerticalWeights() const;
    int                getNumbHorizontalWeights(int x_ = 0) const;


    std::vector<float> getTransposeWeightMatrix(int x_);

    void updateAllWeightsValue(float v_);
    Weight Transpose();

    


private:

    std::vector<std::vector<float>> _weights;
};

