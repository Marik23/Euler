#include <iostream>

int main()
{
	int fib1 = 1;
	int fib2 = 2;
	int tmp;	
	int sum = 0;	
	
	while (fib2 < 4000000)
	{
		tmp = fib2;	
		if (fib2%2 == 0)		
			sum += fib2;
			
		fib2 += fib1;
		fib1 = tmp;
	}
	std::cout << "Sum: " << sum << std::endl;
}
