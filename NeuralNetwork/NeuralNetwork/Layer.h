#pragma once

#include <iostream>
#include <vector>

class Layer
{
    public:
        Layer();
        Layer(std::vector<float>&& weight_);

        void setWeight(std::vector<float>&& weight_);
        void displayWeight() const;
        float getWeightValue(int x_) const;
        int getNbWeight() const;
        std::vector<float> getWeights() const;
        void setWeightValue(int x_, float v_);
        void addNewWeight(float v_);

    private:
        std::vector<float> _weights;



};

