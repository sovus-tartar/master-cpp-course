#include <analyser.h>
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <cmath>

namespace analyser
{

static double GetAverage(const int n, const double * const arr)
{
    if (n <= 0 || arr == nullptr)
    {
        return 0;
    }

    double sum = 0.0;
    for (int i = 0; i < n; ++i)
    {
        sum += arr[i];
    }

    return sum / n;
}

static double GetMin(const int n, const double * const arr)
{
    if (n <= 0 || arr == nullptr)
    {
        return 0;
    }

    double minVal = arr[0];
    for (int i = 1; i < n; ++i)
    {
        if (arr[i] < minVal) minVal = arr[i];
    }

    return minVal;
}

static double GetMax(const int n, const double * const arr)
{
    if (n <= 0 || arr == nullptr)
    {
        return 0;
    }

    double maxVal = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] > maxVal) maxVal = arr[i];
    }
    return maxVal;
}

static double GetStandardDeviation(const int n, const double * const arr)
{
    if (n <= 0 || arr == nullptr)
    {
        return 0;
    }

    const double kMean = GetAverage(n, arr);
    double varianceSum = 0.0;
    for (int i = 0; i < n; ++i) {
        double diff = arr[i] - kMean;
        varianceSum += diff * diff;
    }
    return std::sqrt(varianceSum / n);
}

void AnalyseInput()
{
    int n{};
    std::cin >> n;
    if (std::cin.fail())
    {
        throw std::runtime_error("Can't read a number from stdin");
    }
    
    if (n <= 0)
    {
        throw std::invalid_argument("n <= 0");
    }
    
#ifdef USE_VLA
    double arr[n]; // Using vla clang extension
#else
    static constexpr int kMaxInput{1024};
    if (n >= kMaxInput)
    {
        throw std::invalid_argument("n >= " +  std::to_string(kMaxInput) + std::string(", which is maximum input number"));
    }
    double arr[kMaxInput]{}; // Not using vla clang extension
#endif


    for (int i = 0; i < n; ++i)
    {
        std::cin >> arr[i];
        if (std::cin.fail())
        {
            throw std::runtime_error("Can't read a number from stdin");
        }
    }

    std::cout << "Average:\t"               << GetAverage(n, arr)           << std::endl << \
                 "Min:\t"                   << GetMin(n, arr)               << std::endl << \
                 "Max:\t"                   << GetMax(n, arr)               << std::endl << \
                 "Standard deviation:\t"    << GetStandardDeviation(n, arr) << std::endl;
}

}