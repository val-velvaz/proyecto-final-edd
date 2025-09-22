#pragma once

#include <string>
#include <iostream>

class BigInt {
private:
    // long long value; 
    bool negative;
    int* digits;
    size_t size;
    size_t capacity;

    static const int BASE = 1000000000;

    void expand(size_t new_capacity);
    void normalize();

    static BigInt add_abs(const BigInt& a, const BigInt& b);

public:
    BigInt(long long v = 0);
    // BigInt(long long);
    BigInt(const BigInt&);
    ~BigInt();

    BigInt& operator = (const BigInt&);

    BigInt operator + (const BigInt&) const;
    BigInt operator - (const BigInt&) const;
    BigInt operator * (const BigInt&) const;
    BigInt operator / (const BigInt&) const;

    BigInt& operator += (const BigInt&);
    BigInt& operator -= (const BigInt&);
    BigInt& operator *= (const BigInt&);
    BigInt& operator /= (const BigInt&);

    /*
    Los operadores pre devuelven referencia para permitir encadenamiento,
    mientras que los post devuelven copia porque el valor original
    debe conservarse
    */
    
    BigInt& operator ++ ();
    BigInt& operator -- ();
    BigInt operator ++ (int);
    BigInt operator -- (int);

    bool operator == (const BigInt&) const;
    bool operator != (const BigInt&) const;
    bool operator >= (const BigInt&) const;
    bool operator <= (const BigInt&) const;
    bool operator > (const BigInt&) const;
    bool operator < (const BigInt&) const;

    std::string toString() const;

    friend std::ostream& operator << (std::ostream&, const BigInt&);
    friend std::istream& operator >> (std::istream&, BigInt&);

    static int compare(const BigInt& a, const BigInt& b);
};