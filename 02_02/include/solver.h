#pragma once
#include <array>
#include <cmath>

namespace SquareEquation
{

static constexpr double kEpsilon{1e-12};

bool IsEqual(double a, double b);

class Solves
{
private:
    static constexpr int kMaxSolves{2};
    int nSolves{0};
    std::array<double, kMaxSolves> xArr{};

public:
    Solves()                     : nSolves(0), xArr({NAN, NAN}) {};
    Solves(const double x)             : nSolves(1), xArr{x, NAN}     {};
    Solves(const double x1, const double x2) : nSolves(2), xArr({x1, x2})   {};

    void Print() const;
};

class Equation
{
private:
    double a{NAN};
    double b{NAN};
    double c{NAN};

public:
    Equation(const double a, const double b, const double c);
    Solves Solve() const;
};

} // SquareEquation
