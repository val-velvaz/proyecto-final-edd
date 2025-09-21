#pragma once

#include <string>

class BigInt {
private:
    long long value; 


public:
    BigInt(long long v = 0);
    BigInt(long long);

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