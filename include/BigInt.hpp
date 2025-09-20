#pragma once

#include <string>

class BigInt {
private:
    long long value;

public:

    BigInt(long long);

    BigInt operator + (const BigInt&) const;
    BigInt operator - (const BigInt&) const;
    BigInt operator * (const BigInt&) const;
    BigInt operator / (const BigInt&) const;

    std::string toString() const;

    friend std::ostream& operator << (std::ostream&, const BigInt&);
};