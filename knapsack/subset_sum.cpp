#include<iostream>
#include<vector>
using namespace std;

bool SS(int arr[], int n, int sum)
{
    vector<vector<bool>> t(n+1,vector<bool>(sum+1, false));

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
    return t[n][sum];
}

int main(){

    int arr[] {2,3,7,8,10};
    int sum = 12;
    int n = 5;
    
    cout << "the answer is : " << SS(arr, n, sum);
}