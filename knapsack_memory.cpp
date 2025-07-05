#include<iostream>
#include<cstring>
using namespace std;

int t[5][10];

int knapsack(int val[], int weight[], int W, int n)
{
    // basecase
    if ( n == 0 || W == 0)      //if no more weight to add or list exhausted
        return  0;
    if (t[n][W] != -1)          //if value already computed
        return t[n][W];


    if ( weight[n-1] <= W)      //if curr element's weight is <= remaining weight
        return t[n][W] = max(val[n-1] + knapsack(val, weight, W-weight[n-1], n-1), knapsack(val, weight, W, n-1) );
    return t[n][W] = knapsack(val, weight, W, n-1); //cannot add the current element move to next 
}

int main(){
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

    // call the f()
    cout << "max value with combinations of weights = " << knapsack(values, weights, W_max, n) << endl;
    return 0;
}   