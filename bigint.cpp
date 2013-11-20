#include "bigint.h"
#include <cstdlib>

BigInt::BigInt()
{
    m_number.push_back(0);
}

BigInt::BigInt(int initValue)
{
    int remainder = initValue;
    do
    {
	m_number.push_back(remainder % 10);
	remainder /= 10;
    } while (remainder > 0);
    
}

BigInt::~BigInt()
{}

std::ostream& operator<<(std::ostream& os, const BigInt& number)
{
    for (std::vector<char>::const_iterator it = number.m_number.end() - 1; it >= number.m_number.begin(); --it)
	os << (int)*it;
    return os;
}

BigInt& BigInt::operator+=(const BigInt& rhs)
{
    operator+=(rhs.m_number);
    return *this;
}

BigInt& BigInt::operator+=(const std::vector<char>& rhs)
{
    int size = m_number.size();
    int carry = 0;
    int sum;
    
    std::vector<char>::const_iterator rhsIt;
    std::vector<char>::iterator lhsIt;
    for (rhsIt = rhs.begin(), lhsIt = m_number.begin(); rhsIt != rhs.end() && lhsIt != m_number.end(); ++rhsIt, ++lhsIt)
    {
	sum = (*rhsIt) + (*lhsIt) + carry;
	(*lhsIt) = sum % 10;
	carry = sum / 10;
    }

    if (lhsIt == m_number.end())
    {
	while (rhsIt != rhs.end())
	{
	    m_number.push_back(carry + *rhsIt);
	    carry = 0;
	    ++rhsIt;
	}
	if (carry > 0)
	    m_number.push_back(carry);
    }
    else
	(*lhsIt) += carry;

    return *this;
}

BigInt& BigInt::operator*=(int rhs)
{
    int remainder = rhs;
    int factor;
    int position = 0;
    int carry;
    int product;
    BigInt summand;
    do
    {
	factor = remainder % 10;
	std::vector<char> tmpSummand;
	for (int i = 0; i < position; ++i)
	    tmpSummand.push_back(0);

	carry = 0;
	std::vector<char>::const_iterator it;
	for (it = m_number.begin(); it != m_number.end(); ++it)
	{
	    product = factor * (*it);
	    product += carry;
	    tmpSummand.push_back(product % 10);

	    carry = product / 10;
	}
	if (it == m_number.end() && carry > 0)
	    tmpSummand.push_back(carry);
	
	summand += tmpSummand;
	
	++position;
	remainder /= 10;
    } while (remainder > 0);

    m_number.clear();
    m_number.push_back(0);
    operator+=(summand);

    return *this;
}

int BigInt::getDigitSum()
{
    int sum = 0;
    for (std::vector<char>::const_iterator it = m_number.begin(); it != m_number.end(); ++it)
	sum += *it;
    return sum;
}
