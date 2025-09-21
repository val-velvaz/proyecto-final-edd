#include "BigInt.hpp"

#include <stdexcept>
#include <ostream>
#include <istream>
#include <limits>

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

std::string BigInt::toString() const {
    return std::to_string(value);
}

std::ostream& operator << (std::ostream& os, const BigInt& b) {
    os << b.toString();
    return os;
}

std::istream& operator >> (std::istream& is, BigInt& b) {
    long long temp;
    is >> temp;

    if (is.fail()) { // si la extraccion fallo (no es un numero)
        is.clear(); // limpiar el estado de error
        is.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // descartar la linea
        throw std::runtime_error("Entrada invalida: se esperaba un numero entero");
    }

    b.value = static_cast<long long>(temp);
    return is;
}




