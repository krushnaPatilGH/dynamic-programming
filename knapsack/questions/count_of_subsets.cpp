#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int cos(int arr[], int n, int sum)
{
    vector<vector<int>> t(n+1, vector<int>(sum+1, 0));

    for(int i = 0; i < n+1 ; i++)  t[i][0] = true;

    for(int i = 1; i < n+1; i++)
    {
        for(int j = 1; j < sum+1; j++)
        {
            if(arr[i-1] <= j)
                t[i][j] = t[i-1][j-arr[i-1]] + t[i-1][j];
            else    t[i][j] = t[i-1][j];
        }
    }
    return t[n][sum];
}

int main(){
    int arr[] {2,3,5,6,8,10};
    int n = 6;
    int sum = 10;
    cout << cos(arr, n, sum);
}