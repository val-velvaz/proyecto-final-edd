#include "BigInt.hpp"

#include <stdexcept>

BigInt::BigInt(long long v)
    : value(v) {}

BigInt& BigInt::operator = (const BigInt& other) {
    if (this != &other) {
        this->value = other.value;
    } return *this;
}


BigInt BigInt::operator + (const BigInt& other) const {
    return BigInt(this->value + other.value);
}

BigInt BigInt::operator - (const BigInt& other) const {
    return BigInt(this->value - other.value);
}

BigInt BigInt::operator / (const BigInt& other) const {
    if (other.value == 0) {
        throw std::runtime_error("Division entre cero no permitida");
    } return BigInt(this->value / other.value);
}

BigInt BigInt::operator * (const BigInt& other) const {
    return BigInt(this->value * other.value);
}

BigInt& BigInt::operator += (const BigInt& other)  {
    this->value += other.value;
    return *this;
}

BigInt& BigInt::operator -= (const BigInt& other) {
    this->value -= other.value;
    return *this;
} 

BigInt& BigInt::operator *= (const BigInt& other) {
    this->value *= other.value;
    return *this;
}

BigInt& BigInt::operator /= (const BigInt& other) {
    this->value /= other.value;
    return *this;
}

bool BigInt::operator == (const BigInt& other) const {
    return this->value == other.value;
}

bool BigInt::operator != (const BigInt& other) const {
    return !(*this == other);
}

bool BigInt::operator < (const BigInt& other) const {
    return this->value < other.value;
}

bool BigInt::operator > (const BigInt& other) const {
    return other < *this;
}

bool BigInt::operator <= (const BigInt& other) const {
    return !(*this > other);
}

bool BigInt::operator >= (const BigInt& other) const {
    return !(*this < other);
    return this->value < other.value;
}




