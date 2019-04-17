#include <iostream>

int main()
{

    int mat[2][3] = {0}; // inicializar com 0s
    // int mat2[2][2] = {{1,2},{3,4}};

    const int numRows = 10;
    const int numCols = 10;
    int product[numRows][numCols] = {0};

    for (int row = 0; row < numRows; ++row)
    {
        for (int col = 0; col < numCols; ++col)
        {
            product[row][col] = row * col;
        }
    }

    for (int row = 0; row < numRows; ++row)
    {
        for (int col = 0; col < numCols; ++col)
        {
            std::cout << product[row][col] << '\t';
        }
        std::cout << '\n';
    }

    return 0;
}