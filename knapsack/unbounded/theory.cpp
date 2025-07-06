#include<iostream>
#include<vector>
using namespace std;

int unbounded(int arr[], int sum, int n)
{
    vector<vector<int>> t(n+1, vector<int>(sum+1, 0));

    for(int i = 0; i < n+1; i++) t[i][0] = 1;

    for(int i = 1; i < n+1; i++)
    {
        for(int j = 1;  j < sum+1; j++)
        {
            if (arr[i-1] <= j)
                t[i][j] = t[i][j-arr[i-1]] + t[i-1][j];
            else
                t[i][j] = t[i-1][j];
        }
    }
    
    return t[n][sum];
}

int main()
{
    int arr[] {1,2,3,4};
    int sum = 5;
    
    cout << "number of ways to get sum " << sum << " : " << unbounded(arr, sum, 4);
}