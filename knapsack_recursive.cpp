#include<iostream>
#include<cstring>
using namespace std;

int knapsack(int val[], int weight[], int W, int n)
{
    if ( n == 0 || W == 0)
        return 0;
    
    if ( weight[n-1] <= W)
        return max(val[n-1] + knapsack(val, weight, W-weight[n-1], n-1), knapsack(val, weight, W, n-1) );
    return knapsack(val, weight, W, n-1);
}

int main(){
    int values[] {1, 3, 4, 5};
    int weights[] {2, 4, 5, 7};
    int W_max = 9;
    int n = 4; 

    cout << knapsack(values, weights, W_max, n);
    return 0;
}   