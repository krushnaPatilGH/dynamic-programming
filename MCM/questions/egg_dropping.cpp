#include<iostream>
using namespace std;

int solve(int e, int f)
{
    if ( f == 1 || f == 0 || e == 1 ) return f;

    int mn = INT_MAX;

    for(int k = 1; k <= f; k++)
    {
        int temp = 1 + max( solve( e-1, k-1),
                            solve( e, f-k ));
        mn = min(mn, temp);                    
    }
    return mn;
}

int main()
{
    cout << solve(3, 15);
}