#include<iostream>
#include<vector>
using namespace std;

int mssd(int arr[], int n){
    
    int sum = 0;
    for(int i = 0; i < n; i++) sum += arr[i];
    vector<vector<int>> t(n+1, vector<int>(sum+1, 0));

    for(int i = 0; i < n+1 ; i++)  t[i][0] = true;
    for(int i = 1; i < n+1; i++)
    {
        for(int j = 1; j < sum+1; j++)
        {
            if(arr[i-1] <= j)
                t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
            else    t[i][j] = t[i-1][j];
        }
    }

    int mn = INT_MAX;
    for(int i = 1; i < (sum/2)+1; i++)
        if(t[n][i]) mn = min(mn, sum-2*i);
    
    return mn;
}

int main(){
    int arr[] {2,5,11,5};
    int n = 4;
    cout << mssd(arr, n);
}