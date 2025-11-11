#pragma once
#include <iostream>
#include <vector>

class Weight
{

public:

    void setWeight(std::vector<float>&& vec_);
    void displayWeight() const;
    float getWeightValue(int x_) const;
    std::vector<float> getWeights() const;
    void updateWeightValue(int x_, float v_);

private:

    std::vector<float> _weight_vec;
};

