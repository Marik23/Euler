#include <iostream>
#include <map>

int calculateLetterSum(const std::map<int, int>& lookUp, int number)
{
    int letterSum = 0;
    int remainder = number;

    if (remainder > 999 && remainder < 21000)
    {
	letterSum += lookUp.find(remainder / 1000)->second;
	letterSum += lookUp.find(1000)->second;
	remainder %= 1000;
    }

    if (remainder > 99)
    {
	if (remainder % 100 > 0)
	    letterSum += 3; // "and"
	letterSum += lookUp.find(remainder / 100)->second;
	letterSum += lookUp.find(100)->second;
	remainder %= 100; 
    }


    if (remainder < 21)
	letterSum += lookUp.find(remainder)->second;
    else
    {
	letterSum += lookUp.find(remainder / 10 * 10)->second;
	letterSum += lookUp.find(remainder %  10)->second;
    }

    return letterSum;
}

int main()
{
    int letterSum = 0;
    std::map<int, int> lookUp;
    lookUp[0] = 0;
    lookUp[1] = 3;
    lookUp[2] = 3;
    lookUp[3] = 5;
    lookUp[4] = 4;
    lookUp[5] = 4;
    lookUp[6] = 3;
    lookUp[7] = 5;
    lookUp[8] = 5;
    lookUp[9] = 4;
    lookUp[10] = 3;
    lookUp[11] = 6;
    lookUp[12] = 6;
    lookUp[13] = 8;
    lookUp[14] = 8;
    lookUp[15] = 7;
    lookUp[16] = 7;
    lookUp[17] = 9;
    lookUp[18] = 8;
    lookUp[19] = 8;
    lookUp[20] = 6;
    lookUp[30] = 6;
    lookUp[40] = 5;
    lookUp[50] = 5;
    lookUp[60] = 5;
    lookUp[70] = 7;
    lookUp[80] = 6;
    lookUp[90] = 6;
    lookUp[100] = 7;
    lookUp[1000] = 8;

    std::cout << "Sum of letters for 342: " << calculateLetterSum(lookUp, 342) << std::endl;
    std::cout << "Sum of letters for 115: " << calculateLetterSum(lookUp, 115) << std::endl;

    for (int i = 0; i < 1001; ++i)
	letterSum += calculateLetterSum(lookUp, i);

    std::cout << "Sum of letters for 1 - 1000: " << letterSum << std::endl;

    return 0;
}
