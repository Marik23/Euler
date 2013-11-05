#include <iostream>

int sum = 0;


int main()
{
	for(int i = 3; i < 1000; ++i)
	{
		if (i%3 == 0 || i%5 == 0)
			sum += i;
	}
	std::cout << "Sum = " << sum << std::endl;
}  
