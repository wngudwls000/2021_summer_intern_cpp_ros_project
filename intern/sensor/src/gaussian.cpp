#include "sensor/gaussian.h"

Gaussian::Gaussian(double mean, double stddev) : distribution(mean, stddev){}

void Gaussian::SetGaussian(double mean, double stddev){
    distribution = std::normal_distribution<double>(mean, stddev);
}

double Gaussian::GetGaussianRandom(){
    return std::round(distribution(generator)*1000)/1000;
}
