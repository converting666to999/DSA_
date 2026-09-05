#include <bits/stdc++.h>
using namespace std;

void SetMatrixZero_Better(vector<vector<int>> &matrix)
{
    vector<int> row(matrix.size(), 0); 
    vector<int> col(matrix[0].size(), 0); 


    for(int i = 0; i < matrix.size(); i++)
    {
        for(int j = 0; j < matrix[0].size(); j++)
        {
            if(matrix[i][j] == 0)
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for(int i = 0; i < matrix.size(); i++)
    {
        for(int j = 0; j < matrix[0].size(); j++)
        {
            if(row[i] == 1 || col[j] == 1)
            {
                matrix[i][j] = 0;
            }
        }
    }
}

void Optimal(vector<vector<int>> &matrix)
{   
    int col0 = matrix[0][0];

    for(int i = 0; i < matrix.size(); i++)
    {
        for(int j = 0; j < matrix[0].size(); j++)
        {
            if(matrix[i][j] == 0)
            {
                // mark the ith row
                matrix[i][0] = 0;

                // mark the jth col
                 if( j != 0){
                     matrix[0][j] = 0;
                 }
                 else 
                    col0 = 0;
            }
        }
    }
    
    for(int i = 1; i < matrix.size(); i++)
    {
        for(int j = 1; j < matrix[0].size(); j++)
        {
            //check for marked index and row
            if(matrix[i][0] == 0 ||  matrix[0][j] == 0)
            {
                matrix[i][j] = 0;
            }
        }
    }               

    if(matrix[0][0] == 0)
    {
        for(int j = 0; j < matrix[0].size(); j++)
        {
            matrix[0][j] = 0;
        }
    }
    if(col0 == 0)
    {
        for(int i = 0; i < matrix.size(); i++)
        {
            matrix[i][0] = 0;
        }
    }
}

int main()
{

    vector<vector<int>> arr = {
        {0,1,2,0},
        {3,4,5,2},
        {1,3,1,5}
    }; 

    // fn call
    Optimal(arr); 

    for(int i = 0; i < arr.size(); i++)
    {
        for(int j = 0; j < arr[0].size(); j++)
        {
            cout << arr[i][j] << " "; 
        }
        cout << endl;
    }
    return 0;
}
