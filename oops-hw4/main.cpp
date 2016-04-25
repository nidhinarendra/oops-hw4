

#include<iostream>
using namespace std;
#define Globals

// example matrix size declared globally
const int row (8);
const int col (8);

//Function to validate the matrix
void Validate(int matrix[][col], int r, int c)
{
    if (r==0 || r == row - 1 || c==0 || c== col - 1)
    {
    cerr << "There is no boundary. Hence, cannot be filled" << endl;
    exit(0);
    }
    
     if (matrix[r][c] == 1 || matrix[r][c] == -1)
    {
        return;
    }
    matrix[r][c] = -1;
    
    Validate(matrix, r-1, c);
    Validate(matrix, r-1, c);
    Validate(matrix, r, c+1);
    Validate(matrix, r, c-1);
    
}

//Function to fill the neighbours
void FillNeig(int matrix[][col], int r, int c)
{
    
    if(matrix[r][c] != -1) //base case
      return;
    
    matrix[r][c] = 1; //change the color of matrix at index [x][y].
    
    FillNeig(matrix, r+1, c); // down i.e row+1
    FillNeig(matrix, r-1, c); // up i.e row-1
    FillNeig(matrix, r, c+1); // right i.e col+1
    FillNeig(matrix, r, c-1); // left i.e col-1
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
                         {0, 1, 0, 0, 0, 0, 0, 0},
                         {1, 0, 1, 0, 0, 0, 0, 0},
                         {0, 1, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0},
    };
    
    int r = 2, c = 1; //Example input where the color needs to be filled
    Validate(matrix, r, c);
    FillNeig(matrix, r, c);
    printmatrix(matrix, row, col);
}
