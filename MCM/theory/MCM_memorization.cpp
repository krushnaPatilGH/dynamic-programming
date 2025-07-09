#include<iostream>
#include<cstring>
using namespace std;
int t[1001][1001];
int solve(int arr[], int i, int j)
{
    if (i>=j) return 0;
    if (t[i][j] != -1) return t[i][j];
    int mn = INT_MAX;
    for(int k = i ; k < j; k++)
    {
        int temp = solve(arr, i, k) + solve(arr, k+1, j) + arr[i-1] * arr[k] * arr[j];
        mn = min(mn, temp);
    }    
    return t[i][j] = mn;
}

int main()
{
    memset(t, -1, sizeof(t));
    int arr[] {40, 20, 30, 10, 30};
    cout << solve(arr, 1, 4);
}