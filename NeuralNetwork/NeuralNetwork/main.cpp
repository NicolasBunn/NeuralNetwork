#include <iostream>
#include <vector>
#include <cassert>
#include "Weight.h"
#include "Matrix.h"
#include "NeuralNetwork.h"

int main(int argc, char* argv)
{
    std::vector<float> goal = { 0.1f,0.2f,0.0f,0.1f };
    std::vector<float> player_field = { 1.0f, 0.9f, 1.0f,0.8f };
    std::vector<float> fans = { 0.1f,0.5f,1.0f, 0.2f };
    std::vector<float> win = { 1.0f, 0.0f, 1.0f, 1.0f };

    std::vector<float> input = { goal[0], player_field[0], fans[0] };

    float alpha = 0.01f;
    float error = 0.0f;
    float delta = 0.0f;
    float weight_delta = 0.0f;

    Matrix matrix;

    Weight w_win;
    w_win.setWeight(std::vector<float>{0.5f, 0.3f, 0.1f});
    matrix.addWeights(w_win);

    for (int i = 0; i < 3; i++)
    {
        std::vector<float> pred = NeuralNetwork::neuralNetwork(input, matrix);
        error = (pred[0] - win[0]) * (pred[0] - win[0]);
        delta = pred[0] - win[0];
        std::vector<float>weight_delta = NeuralNetwork::weight_delta(input, delta);

        std::cout << "Iteration " << i << std::endl;
        std::cout << "Pred " << pred[0] << std::endl;
        std::cout << "Error " << error << std::endl;
        std::cout << "Delta " << delta << std::endl;
        std::cout << "Weight : ";
        for (int j = 0; j < matrix.getNumbWeights(); j++)
        {
            for (int k = 0; k < matrix.getWeight(j).size(); k++)
            {
                std::cout << matrix.getWeightValue(j,k) << " : ";

            }
        }
        std::cout << "\n";
        std::cout << "Weight delta : ";
        for (int j = 0; j < weight_delta.size(); j++)
        {
            std::cout << weight_delta[j] << " : ";
        }
        std::cout << "\n";

        for (int j = 0; j < matrix.getWeight(0).size(); j++)
        {
            float new_weight_value = matrix.getWeightValue(0, j) - alpha * weight_delta[j];
            matrix.setWeightValue(0, j, new_weight_value);
        }

    }

    //error = (r[0] - win[0]) * 2.0f;
    //delta = (r[0] - win_orwin_lose[0]);
    //weight_delta = goal[0] * delta;
    //w_win.updateWeightValue(0, w_win.getWeight(0) - (weight_delta * alpha));


    //std::cout << "result " << std::endl;
    //for (int i = 0; i < r.size(); i++)
    //{
    //    std::cout << r[i] << " ";
    //}

    return 0;
}

//Weight w_hurt;
//w_hurt.setWeight(std::vector<float>{0.2f, 0.2f, 0.3f});
    //matrix.addWeights(w_hurt);