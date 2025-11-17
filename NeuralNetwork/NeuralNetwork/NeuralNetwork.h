#pragma once

#include "Layer.h"
#include "Weight.h"
#include <vector>

class NeuralNetwork
{
    public:

        void relu(Layer& layer_);
        float relu2Deriv(Layer& layer_);


        static float relu(float x_);
        static float relu2Deriv(float v_);
        static float randomNumber(float min_ = -1.0f, float max_ = 1.0f);
        static Layer dot(Layer& layer_entry_, Weight& weight_);

        static std::vector<float> weight_delta(std::vector<float> weights_, float scalar_);

        void setAlpha(float a_);
        void initMiddleLayer(int numb_, bool random_ = true);

        void addInputData(std::vector<Layer>& input_data_);
        void addOutputData(std::vector<Layer>& output_data_);

        void initWeight();

        void executeNeuralNetwork(int numb_iteration_);
        float sum(const Layer& layer_1_, const Layer& layer_2_);
        float diff(const Layer& layer_1_, const Layer& layer_2_);
        float mul(const Weight& weight_, float v_);
        float mul(const Layer& layer_, float v_);



private:

    float _alpha = 0.1f;
    float _error = 0.0f;
    float _delta = 0.0f;
    float _weight_delta = 0.0f;

    Layer _middle_layer;

    std::vector<Layer> _input_data;
    std::vector<Layer> _ouput_data;

    Weight _w_0_1;
    Weight _w_1_2;



};

