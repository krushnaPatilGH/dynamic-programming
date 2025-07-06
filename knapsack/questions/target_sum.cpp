#include<iostream>
#include<vector>
using namespace std;

int TS(int arr[], int n, int diff){
    
    int sum = 0;
    for(int i = 0; i < n; i++) sum += arr[i];

    sum = (diff + sum)/2;

    vector<vector<int>> t(n+1, vector<int>(sum+1, 0));

    for(int i = 0; i < n+1 ; i++)  t[i][0] = 1;

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
    int arr[] {1,1,1,1,1};
    int n = 5;
    int d = 3;
    cout << TS(arr, n, d);
}