// n queens problem using Backtracking
#include <iostream>
#define N 4
using namespace std;
bool issafe(int arr[N][N], int x, int y)
{
    int row, col;

    // check row on left side
    for (row = 0; row < x; row++)
    {
        if (arr[row][y] == 1)
            return false;
    }

    // check left diagnol
    row = x;
    col = y;
    while (row >= 0 && col >= 0)
    {
        if (arr[row][col] == 1)
            return false;
        row--;
        col--;
    }

    // check right diagnol
    row = x;
    col = y;
    while (row >= 0 && col < N)
    {
        if (arr[row][col] == 1)
            return false;
        row--;
        col++;
    }

    return true;
}
bool nqueen(int arr[N][N], int x)
{
    // all queens are already placed sucessfully
    if (x >= N)
        return true;

    for (int col = 0; col < N; col++)
    {
        if (issafe(arr, x, col))
        {
            arr[x][col] = 1;
            if (nqueen(arr, x + 1))
                return true;
            arr[x][col] = 0; // backtraking
        }
    }
    return false;
}
int main()
{
    int arr[N][N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            arr[i][j] = 0;
        }
    }

    if (nqueen(arr, 0))
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
    else cout<<"Solution does not exists."<<endl;
}