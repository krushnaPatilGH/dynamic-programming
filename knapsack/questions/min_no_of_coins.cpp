#include<iostream>
#include<vector>
using namespace std;

int unbounded(int arr[], int sum, int n)
{
    vector<vector<int>> t(n+1, vector<int>(sum+1, 0));

    for(int i = 0; i < sum+1; i++) t[0][i] = INT_MAX - 1;

    for(int j = 1; j < sum+1; j++) 
        if (j%arr[0] == 0)
            t[1][j] = j /arr[0];
        else
            t[1][j] = INT_MAX - 1;
    
    for(int i = 2; i < n+1; i++)
    {
        for(int j = 1;  j < sum+1; j++)
        {
            if (arr[i-1] <= j)
                t[i][j] =  min(t[i][j-arr[i-1]] +1,  t[i-1][j]);
            else
                t[i][j] = t[i-1][j];
        }
    }
    return t[n][sum];
}

int main()
{
    int denotions[] {1, 2, 3};
    
    for(int sum = 0; sum < 10; sum ++)
        cout << "combinations of coins for sum = " << sum << " is " << unbounded(denotions, sum, 3) << endl;
}