#include "BigInt.hpp"

#include <stdexcept>
#include <ostream>
#include <istream>
#include <limits>
#include <sstream>
#include <iomanip>
#include <cstdint>

void BigInt::normalize() {
    while (size > 1 && digits[size -1] == 0) {
        --size;
    }
    if (size == 1 && digits[0] == 0) {
        negative = false;
    }
}

BigInt::BigInt(long long v)
    : negative(false), digits(nullptr), size(0), capacity(0) {
        if (v < 0) {
            negative = true;
            v = -v;
        }

        if (v == 0) {
            capacity = 1;
            size = 1;
            digits = new int[1]{0};
        } else {
            capacity = 4;
            digits = new int[capacity];
            size = 0;
            
            while (v > 0) {
                if (size == capacity) expand(capacity * 2);
                digits[size++] = v % BASE;
                v /= BASE;
            }
        }
    }

BigInt::BigInt(const BigInt& other)
    : negative(other.negative), size(other.size), capacity(other.capacity) {
        digits = new int[capacity];
        for (size_t i = 0; i < size; ++i) {
            digits[i] = other.digits[i];
        }
    }

BigInt::~BigInt() {
    delete[] digits;
}

void BigInt::expand(size_t new_capacity) {
    int* new_digits = new int[new_capacity];
    for (size_t i = 0; i < size; ++i) new_digits[i] = digits[i];
    delete[] digits;
    digits = new_digits;
    capacity = new_capacity;
}

BigInt BigInt::add_abs(const BigInt&a, const BigInt& b) {
    BigInt result(0);
    size_t maxSize = (a.size > b.size) ? a.size : b.size;

    result.capacity = maxSize + 1;
    delete[] result.digits;
    result.digits = new int[result.capacity];
    result.size = 0;

    int64_t carry = 0;
    for (size_t i = 0; i < maxSize; ++i) {
        int64_t ai = (i < a.size) ? a.digits[i] : 0;
        int64_t bi = (i < b.size) ? b.digits[i] : 0;
        int16_t sum = ai + bi + carry;
        result.digits[result.size++] = int(sum % BASE);
        carry = sum /BASE;
    } if (carry > 0) {
        result.digits[result.size++] = int(carry);
    }
    result.negative = false;
    result.normalize();
    return result;
}

BigInt& BigInt::operator = (const BigInt& other) {
    /* if (this != &other) {
        this->value = other.value;
    } return *this;
    */
    if (this == &other) return *this;
    delete[] digits;
    capacity = other.capacity;
    size = other.size;
    negative = other.negative;
    digits = new int[capacity];
    for (size_t i = 0; i < size; ++i) {
        digits[i] = other.digits[i];
    } return *this;
}


BigInt BigInt::operator + (const BigInt& other) const {
    if (this->negative == other.negative) {
        BigInt r = add_abs(*this, other);
        r.negative = this->negative;
        return r;
    } else {
        throw std::runtime_error("Suma con signos distintos no esta implementada aun");
    }
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

BigInt& BigInt::operator ++ () {
    ++value;
    return *this;
}

BigInt& BigInt::operator -- () {
    --value;
    return *this;
}

BigInt BigInt::operator ++ (int) {
    BigInt temp = *this;
    ++value;
    return temp;
}

BigInt BigInt::operator -- (int) {
    BigInt temp = *this;
    --value;
    return temp;
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
    if (this->size == 0) return "0";

    std::ostringstream oss;
    if (this->negative) oss << "-";

    oss << this->digits[size -1];

    for (int i = (int)size - 2; i >= 0; --i) {
        oss << std::setw(9) << std::setfill('0') << this->digits[i];
    }
    return oss.str();
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

int BigInt::compare(const BigInt& a, const BigInt& b) {
    if (a.value > b.value) return 1;
    if (a.value < b. value) return -1;
    // else
    return 0;
}




