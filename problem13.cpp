#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <sstream>

int main()
{
    int numberSize = 50;
    std::string line;
    std::vector<std::string> numbers;
    std::ifstream file("data/numbers_problem13.txt");

    if (file.is_open())
    {
	while (getline(file, line))
	    numbers.push_back(line);
	
	file.close();
    }

    std::string sum;
    int carry = 0;
    int digitSum;
    std::string digit;
    for (int i = numberSize - 1; i >= 0; --i)
    {
	digitSum = carry % 10;
	carry /= 10;
	for (std::vector<std::string>::iterator it = numbers.begin(); it != numbers.end(); ++it)
	    digitSum += (*it)[i] - '0';

	carry += (digitSum / 10);
	std::stringstream ss;
	ss << (digitSum % 10);
	sum.insert(0, ss.str());
    }
    
    std::cout << "Sum: " << carry << sum << std::endl;

    return 0;
}
