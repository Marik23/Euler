#include <iostream>

int main()
{
    int sum = 1000;
    int limitI = sum / 3 - 1;
    int limitJ = sum / 2 - 1;
    int diff;
    for (int i = 1; i < limitI; ++i)
	for (int j = i + 1; j < limitJ; ++j)
	{
	    diff = sum - i - j;
	    if (i*i + j*j == diff*diff)
	    {
		std::cout << i << "^2 + " << j << "^2 = " << diff << "^2" << std::endl;
		std::cout << i*i << " + " << j*j << " = " << diff * diff << std::endl;
		std::cout << "a*b*c = " << i * j * diff << std::endl;
	    }
	}
}
