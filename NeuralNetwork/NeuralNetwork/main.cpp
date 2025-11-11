#include <iostream>
#include <vector>
#include <cassert>

float weight_sum(std::vector<float> a_, std::vector<float> b_)
{
    assert(a_.size() == b_.size());

    float output = 0.0f;

    for (int i = 0; i < a_.size(); i++)
    {
        output += a_[i] * b_[i];
    }

    return output;
}

std::vector<float> neuralNetwork(std::vector<float> input_, std::vector<float> weight_, int numb_output)
{
    std::vector<float> v;
    return v;
}

std::vector<float> neuralNetwork(std::vector<float> input_, std::vector<float> weight_)
{
    std::vector<float> vec;
    vec.emplace_back(weight_sum(input_, weight_));
    return vec;
}

std::vector<float> neuralNetwork(float input_, float weight_)
{
    std::vector<float> vec;
    vec.emplace_back(input_ * weight_);
    return vec;
}

int main(int argc, char* argv)
{
    std::vector<float> goal = { 0.1f,0.2f,0.0f,0.1f };
    std::vector<float> player_field = { 1.0f, 0.9f, 1.0f };
    std::vector<float> fans = { 0.1f,0.5f,1.0f };

    std::vector<float> weights = { 0.8f, 0.5f, 0.1f };
    std::vector<float> entry = { goal[0], player_field[0], fans[0] };

    std::vector<float> r = neuralNetwork(entry, weights);

    //float r = neuralNetwork(entry, weights);
    //std::cout << "r = " << r << std::endl;

    return 0;
}