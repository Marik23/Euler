#pragma once

#include <vector>
#include <iostream>

class BigInt
{
public:
    BigInt();
    BigInt(int initValue);
    ~BigInt();
    
    friend std::ostream& operator<<(std::ostream& os, const BigInt& number);
    BigInt& operator+=(const BigInt& rhs);
    BigInt& operator+=(const std::vector<char>& rhs);
    BigInt& operator*=(int rhs);

    int getDigitSum();
    int getNumDigits();

    std::vector<char> m_number;
};
