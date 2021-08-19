#include <iostream>
#include <random>
#include <cmath>


class Gaussian{
public:
    Gaussian(double mean, double stddev);
    void SetGaussian(double mean, double stddev);
    double GetGaussianRandom();

private:

    std::default_random_engine generator;            // generator 생성

    std::normal_distribution<double> distribution; // (mean, standard deviation)
};
