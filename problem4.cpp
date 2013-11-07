#include <iostream>
#include <sstream>
#include <string>

bool isPalindrome(int number)
{
	bool isPalindrome = true;
	std::string numberStr;
	std::ostringstream numberStream;
	numberStream << number;
	numberStr = numberStream.str();	
	int i = 0;
	int j = numberStr.size() - 1;	
	while (i < j)
	{	
		if (numberStr[i] != numberStr[j])
		{
			isPalindrome = false;	
			break;
		}
		++i;
		--j;	
	}
	if (isPalindrome)
		std::cout << number << std::endl;
	return isPalindrome;
}

int main()
{
	int product;
	int largestPalindrome = 0;	
	for (int i = 100; i < 999; ++i)
		for (int j = i; j < 999; ++j)
		{
			product = i * j;
			if (product > largestPalindrome)			
				if (isPalindrome(product))
					largestPalindrome = product;
		}		
	std::cout << "Largest palindrome: " << largestPalindrome << std::endl; 
}
