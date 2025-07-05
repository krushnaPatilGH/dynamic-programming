#include<iostream>
#include<cstring>
using namespace std;

int main(){
    int t[5][10];
    memset(t, -1, sizeof(t)); 
    int values[] {4, 2, 4, 5};
    int weights[] {2, 4, 5, 7};
    int W_max = 9;
    int n = 4; 

    //initialize first row n column
    for(int i = 0; i < 5; i++ )
        t[i][0] = 1; 
    for(int i = 0; i < 10; i++)
        t[0][i] = 0; 


    //knapsack
    for(int i = 1; i < n+1; i++)
    {
        for(int j = 1; j < W_max+1; j++)
        {
            if (weights[i-1] <= j) 
                t[i][j] = max(t[i-1][j-weights[i-1]], t[i-1][j]);
            else t[i][j] = t[i-1][j];
        }
    }

    // print the value considering 4 elements and sum is 9 
    cout << "max value with combinations of weights = " << t[4][9] << endl;
    return 0;
}   