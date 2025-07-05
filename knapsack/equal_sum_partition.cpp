#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

bool esp(int arr[], int n){
    
    int sum = 0;
    for(int i = 0; i < n; i++) sum += arr[i];

    if(sum % 2 != 0) return 0;
    sum = sum / 2;

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
    if (t[n][sum]) return true;
    return false;
}

int main(){
    int arr[] {1,5,11,5};
    int n = 4;
    cout << esp(arr, n);
}