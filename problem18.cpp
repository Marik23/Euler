#include <vector>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <cstdio>

int calculateMaxPathSum(int level, int index, const std::vector<int>& elements, int maxIndex)
{
    int left = index + level;
    int right = index + level + 1;
    
    int sumLeft;
    if (left > maxIndex)
        return elements[index];
    else
        sumLeft = calculateMaxPathSum(level + 1, left, elements, maxIndex);
    
    int sumRight;
    if (right > maxIndex)
        return 0;
    else
        sumRight = calculateMaxPathSum(level + 1, right, elements, maxIndex);
    
    if (sumLeft > sumRight)
        return elements[index] + sumLeft;
    else
        return elements[index] + sumRight;
}

int main()
{
    std::vector<int> elements;
    
    // Read grid from file
    std::string line;
    std::ifstream file("data/numbers_problem18.txt");
    char* splitted;
    char* cstr;
    if (file.is_open())
    {
	while (getline(file, line))
	{
	    cstr = new char[line.length()+1];
	    std::strcpy(cstr, line.c_str());
	    splitted = strtok(cstr, " ");
	    
	    while (splitted != NULL)
	    {
            elements.push_back(atoi(splitted));
            splitted = strtok(NULL, " ");
	    }
	}
	file.close();
    }
    
    std::cout << "Max path sum: " << calculateMaxPathSum(1, 0, elements, elements.size() - 1) << std::endl;

    return 0;
}
