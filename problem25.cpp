#include <iostream>
#include "bigint.h"

int main()
{
    BigInt fib0 = BigInt(1);
    BigInt fib1 = BigInt(1);
    BigInt fibTmp;
    int numIteration = 2;

    while (fib1.getNumDigits() < 1000)
    {
	fibTmp = fib1;
	fib1 += fib0;
	fib0 = fibTmp;
	++numIteration;
    }

    std::cout << numIteration << ". term" << std::endl;

    return 0;
}
