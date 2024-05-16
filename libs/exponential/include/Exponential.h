#ifndef HW2_LIBS_EXPONENTIAL_INCLUDE_EXPONENTIAL_H_
#define HW2_LIBS_EXPONENTIAL_INCLUDE_EXPONENTIAL_H_

#include <string>

// Exponential class interface
class Exponential {
public:
    Exponential();
    explicit Exponential(long long int value);
    Exponential(long long int significand, long long int exponent);
    long long int significand() const;
    long long int exponent() const;
    operator double() const;
    std::string str() const;
    Exponential operator+(Exponential const& other) const;
    Exponential& operator+=(Exponential const& other);
    Exponential operator-(Exponential const& other) const;
    Exponential& operator-=(Exponential const& other);
    Exponential operator*(Exponential const& other) const;
    Exponential& operator*=(Exponential const& other);
    Exponential operator/(Exponential const& other) const;
    Exponential& operator/=(Exponential const& other);
    Exponential operator-() const;
    bool operator==(Exponential const& other) const;
    bool operator!=(Exponential const& other) const;
    friend std::ostream& operator<<(std::ostream& op, Exponential const& exponential);
};

std::ostream& operator<<(std::ostream& op, Exponential const& exponential);

#endif
