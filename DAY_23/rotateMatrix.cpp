#include <bits/stdc++.h>
using namespace std;

//brute
void RotateMatrix(vector<vector<int>> &matrix)
{   
    // column
    int n = matrix[0].size();
    // creates another 2d vector for answer
    vector<vector<int>> ans(matrix.size(),vector<int>(matrix[0].size(), 0));

    for(int i = 0; i < matrix.size(); i++)
    {
        for(int j = 0; j < matrix[0].size(); j++)
        {
            ans[j][(n-1) - i] = matrix[i][j];
        }
    }

    for(int i = 0; i < ans.size(); i++)
    {
        for(int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

// optimal approach
void RotateMatrix_Op(vector<vector<int>>& matrix)
{   
    // transpose the matrix
    for(int i = 0; i < matrix.size() - 1; i++)
    {
        for(int j = i + 1; j < matrix.size(); j++)
        {
            swap(matrix[i][j],matrix[j][i]);
        }
    }

    // reversing the matrix
    for(int i = 0; i < matrix.size(); i++)
    {
        // two pointer approach so tc n/2
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main()
{
    vector<vector<int>> arr = {

        {1,2,3},
        {4,5,6},
        {7,8,9}


    };

    RotateMatrix_Op(arr);

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