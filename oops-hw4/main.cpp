

#include<iostream>
using namespace std;

// example matrix size
const int row (8);
const int col (8);

//Function to fill the neighbours
void FillNeig(int matrix[][col], int r, int c, int tofill)
{
    if(matrix[r][c] != 0) //base case
      return;
    
    matrix[r][c] = tofill; //change the color of matrix at index [x][y].
    
    FillNeig(matrix, r+1, c, tofill); // down i.e row+1
    FillNeig(matrix, r-1, c, tofill); // up i.e row-1
    FillNeig(matrix, r, c+1, tofill); // right i.e col+1
    FillNeig(matrix, r, c-1, tofill); // left i.e col-1
}


void printmatrix( int matrix[][col], int row, int col)
{
    cout << "Matrix is " << endl;
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

//main function
int main()
{
    int matrix[][col] = {{0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 1, 1, 1, 1, 1, 0, 0},
                         {0, 1, 0, 0, 0, 1, 0, 0},
                         {0, 1, 0, 0, 0, 1, 0, 0},
                         {0, 1, 1, 1, 1, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0},
    };
    
    int r = 3, c = 3, tofill = 2; //Example input where the color needs to be filled
    FillNeig(matrix, r, c, tofill);
    printmatrix(matrix, row, col);
}
