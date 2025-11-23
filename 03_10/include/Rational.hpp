#pragma once
#include <numeric>
#include <ostream>
#include <istream>
#include <compare>

class Rational
{
public:
    Rational(int num = 0, int den = 1) : m_num(num), m_den(den) { reduce(); }

    explicit operator double() const { return 1.0 * m_num / m_den; }

    // арифметические операторы
    auto& operator+=(Rational const& other)
    {
        auto lcm = std::lcm(m_den, other.m_den);
        m_num = m_num * (lcm / m_den) + other.m_num * (lcm / other.m_den);
        m_den = lcm;
        reduce();
        return *this;
    }

    auto& operator-=(Rational const& other) { return *this += Rational(-other.m_num, other.m_den); }
    auto& operator*=(Rational const& other) { m_num *= other.m_num; m_den *= other.m_den; reduce(); return *this; }
    auto& operator/=(Rational const& other) { return *this *= Rational(other.m_den, other.m_num); }

    // инкременты/декременты
    auto const operator++(int) { auto tmp = *this; *this += 1; return tmp; }
    auto const operator--(int) { auto tmp = *this; *this -= 1; return tmp; }
    auto& operator++() { *this += 1; return *this; }
    auto& operator--() { *this -= 1; return *this; }

    // арифметика через дружественные функции
    friend auto operator+(Rational lhs, Rational const& rhs) { return lhs += rhs; }
    friend auto operator-(Rational lhs, Rational const& rhs) { return lhs -= rhs; }
    friend auto operator*(Rational lhs, Rational const& rhs) { return lhs *= rhs; }
    friend auto operator/(Rational lhs, Rational const& rhs) { return lhs /= rhs; }

    // оператор равенства
    friend bool operator==(Rational const& lhs, Rational const& rhs)
    {
        return lhs.m_num == rhs.m_num && lhs.m_den == rhs.m_den;
    }

    // оператор трехстороннего сравнения
    friend auto operator<=>(Rational const& lhs, Rational const& rhs)
    {
        return lhs.m_num * rhs.m_den <=> rhs.m_num * lhs.m_den;
    }

    // ввод/вывод
    friend std::istream& operator>>(std::istream& is, Rational& r)
    {
        int num, den;
        char sep;
        is >> num >> sep >> den;
        if (sep == '/') r = Rational(num, den);
        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, Rational const& r)
    {
        return os << r.m_num << '/' << r.m_den;
    }

private:
    void reduce()
    {
        if (m_den < 0) { m_num = -m_num; m_den = -m_den; }
        int g = std::gcd(m_num, m_den);
        m_num /= g;
        m_den /= g;
    }

    int m_num = 0;
    int m_den = 1;
};