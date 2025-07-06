#include<iostream>
#include<vector>
using namespace std;

int unbounded_wt_values(int arr[], int arr2[], int sum, int n)
{
    vector<vector<int>> t(n+1, vector<int>(sum+1, 0));

    for(int i = 1; i < n+1; i++)
    {
        for(int j = 1;  j < sum+1; j++)
        {
            if (arr[i-1] <= j)
                t[i][j] = max( arr2[i-1] + t[i][j-arr[i-1]] , t[i-1][j]);
            else
                t[i][j] = t[i-1][j];
        }
    }
    
    return t[n][sum];
}

int main()
{
    int Length[] {1, 2, 3, 4,  5,  6,  7,  8};
    int Price[]  {1, 5, 8, 9, 10, 17, 17, 20};
    int sum = 8;
    
    cout << "max price gainable for length " << sum << " : " << unbounded_wt_values(Length, Price, sum, 8);
}