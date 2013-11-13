#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <cstdio>

int main()
{
    int limitX = 20;
    int limitY = 20;
    int adjacentSize = 4;
    int limitXDecr = limitX - adjacentSize + 1;
    int limitYDecr = limitY - adjacentSize + 1;
    int grid[limitX][limitY];

    // Read grid from file
    std::string line;
    std::ifstream file("data/grid_problem11.txt");
    char* splitted;
    char* cstr;
    int gridI = 0;
    int gridJ = 0;
    if (file.is_open())
    {
	while (getline(file, line))
	{
	    gridI = 0;
	    cstr = new char[line.length()+1];
	    std::strcpy(cstr, line.c_str());
	    splitted = strtok(cstr, " ");
	    
	    while (splitted != NULL)
	    {
		grid[gridI][gridJ] = atoi(splitted);
		splitted = strtok(NULL, " ");
		++gridI;
	    }
	    
	    ++gridJ;
	}
	file.close();
    }

    // Process grid
    int greatestProduct = 0;
    int currentProduct;
    for (int j = 0; j < limitY; ++j)
    {
	for (int i = 0; i < limitX; ++i)
	{
	    // horizontal
	    if (i < limitXDecr)
	    {
		currentProduct = 1;
		for (int k = 0; k < adjacentSize; ++k)
		    currentProduct *= grid[i+k][j];

		if (currentProduct > greatestProduct)
		    greatestProduct = currentProduct;
	    }
        
	    // vertical
	    if (j < limitYDecr)
	    {
		currentProduct = 1;
		for (int k = 0; k < adjacentSize; ++k)
		    currentProduct *= grid[i][j+k];

		if (currentProduct > greatestProduct)
		    greatestProduct = currentProduct;
	    }
        
	    // diagonal right
	    if (i < limitXDecr && j < limitYDecr)
	    {
		currentProduct = 1;
		for (int k = 0; k < adjacentSize; ++k)
		    currentProduct *= grid[i+k][j+k];

		if (currentProduct > greatestProduct)
		    greatestProduct = currentProduct;
	    }
        
	    // diagonal left
	    if (i >= adjacentSize - 1 && j >= adjacentSize - 1)
	    {
		currentProduct = 1;
		for (int k = 0; k < adjacentSize; ++k)
		    currentProduct *= grid[i-k][j+k];

		if (currentProduct > greatestProduct)
		    greatestProduct = currentProduct;
	    }
		
	}
    }

    std::cout << "Greatest product: " << greatestProduct << std::endl;

    return 0;
}
