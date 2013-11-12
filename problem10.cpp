#include <iostream>

int main()
{
    int size = 2000000;
    bool* numbers = new bool[size];
    for (int i = 0; i < size; ++i)
	numbers[i] = true;

    long long sum = 0;
    for (int i = 2; i < size; ++i)
	if (numbers[i])
	{
	    sum += i;
	    for (int j = 2 * i; j < size; j += i)
		numbers[j] = false;
	}

    std::cout << "Sum: " << sum << std::endl;
}
