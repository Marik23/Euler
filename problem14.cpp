#include <iostream>

void calculateCollatzSequence(long long number, int& sequenceLength)
{
    ++sequenceLength;

    if (number == 1)
	return;

    if (number % 2 == 0)
	calculateCollatzSequence(number/2, sequenceLength);
    else
	calculateCollatzSequence(3*number + 1, sequenceLength);

} 

int main()
{
    int longestSequence = 0;
    long long numberWithLongestSequence = 2;
    int currentSequence;

    for (int i = 2; i < 1000000; ++i)
    {
	currentSequence = 0;
	calculateCollatzSequence(i, currentSequence);

	if (currentSequence > longestSequence)
	{
	    longestSequence = currentSequence;
	    numberWithLongestSequence = i;
	}
    }

    std::cout << "Number with longest sequence: " << numberWithLongestSequence << std::endl;
    std::cout << "Longest Collatz sequence: " << longestSequence << std::endl;

    return 0;
}
