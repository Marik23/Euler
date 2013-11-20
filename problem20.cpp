#include <iostream>
#include "bigint.h"

int main()
{
    int fac = 100;
    
    //for (int i = 1; i <= fac; ++i)

    BigInt number = BigInt(1);
    
    for (int i = 1; i <= fac; ++i)
	number *= i;

    //BigInt number2 = BigInt(675);
    //std::cout << number2 << std::endl;
    //number += number2;
    std::cout << number.getDigitSum() << std::endl;
	

    return 0;
}
