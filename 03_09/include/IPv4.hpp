#pragma once
#include <array>
#include <cstdint>
#include <iostream>
#include <sstream>
#include <iomanip>

class IPv4
{
public:
    IPv4() : octets_{0,0,0,0} {}
    IPv4(uint8_t a, uint8_t b, uint8_t c, uint8_t d) : octets_{a,b,c,d} {}

    // Префиксный инкремент ++ip
    IPv4& operator++()
    {
        for (int i = 3; i >= 0; --i)
        {
            if (++octets_[i] != 0)
                break;
        }
        return *this;
    }

    // Постфиксный инкремент ip++
    IPv4 operator++(int)
    {
        IPv4 temp = *this;
        ++(*this);
        return temp;
    }

    // Префиксный декремент --ip
    IPv4& operator--()
    {
        for (int i = 3; i >= 0; --i)
        {
            if (octets_[i]-- != 0)
                break;
        }
        return *this;
    }

    // Постфиксный декремент ip--
    IPv4 operator--(int)
    {
        IPv4 temp = *this;
        --(*this);
        return temp;
    }

    // Доступ к компонентам (для тестов)
    uint8_t operator[](size_t index) const { return octets_[index]; }

    // Дружественные операторы сравнения
    friend bool operator==(const IPv4& lhs, const IPv4& rhs)
    {
        return lhs.octets_ == rhs.octets_;
    }

    friend bool operator!=(const IPv4& lhs, const IPv4& rhs)
    {
        return !(lhs == rhs);
    }

    friend bool operator<(const IPv4& lhs, const IPv4& rhs)
    {
        return lhs.octets_ < rhs.octets_;
    }

    friend bool operator<=(const IPv4& lhs, const IPv4& rhs)
    {
        return lhs.octets_ <= rhs.octets_;
    }

    friend bool operator>(const IPv4& lhs, const IPv4& rhs)
    {
        return lhs.octets_ > rhs.octets_;
    }

    friend bool operator>=(const IPv4& lhs, const IPv4& rhs)
    {
        return lhs.octets_ >= rhs.octets_;
    }

    // Ввод/вывод через stringstream
    friend std::istream& operator>>(std::istream& is, IPv4& ip)
    {
        int a,b,c,d;
        char dot1, dot2, dot3;
        is >> a >> dot1 >> b >> dot2 >> c >> dot3 >> d;
        if (is && dot1 == '.' && dot2 == '.' && dot3 == '.')
        {
            ip.octets_[0] = static_cast<uint8_t>(a);
            ip.octets_[1] = static_cast<uint8_t>(b);
            ip.octets_[2] = static_cast<uint8_t>(c);
            ip.octets_[3] = static_cast<uint8_t>(d);
        }
        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, const IPv4& ip)
    {
        os << static_cast<int>(ip.octets_[0]) << '.'
           << static_cast<int>(ip.octets_[1]) << '.'
           << static_cast<int>(ip.octets_[2]) << '.'
           << static_cast<int>(ip.octets_[3]);
        return os;
    }

private:
    std::array<uint8_t,4> octets_;
};
