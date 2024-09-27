// Given an Matrix of N x N size, write a program to rotate it by 90 degrees
// Date: 25-2-21

#include <iostream>

using namespace std;
int main()
{
    int arr1[3][3] = {{1, 2, 4}, {7, 5, 6}, {10, 8, 9}};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr1[i][j] << " ";
        }
        cout << endl;
    }
    int j = 0;
repeat:
    for (int i = 2; i >= 0; i--)
    {

        cout << arr1[i][j] << " ";
    }
    cout << endl;
    j++;
    if (j <= 2)
    {
        goto repeat;
    }

    return 0;
}
