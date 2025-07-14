#include<iostream>
#include<cstring>
using namespace std;

int t[1001][1001];

int solve(int e, int f)
{
    if ( f == 1 || f == 0 || e == 1 ) return f;
    if ( t[e][f] != -1) return t[e][f];
    int mn = INT_MAX;

    for(int k = 1; k <= f; k++)
    {
        int temp = 1 + max( solve( e-1, k-1),
                            solve( e, f-k ));
        mn = min(mn, temp);                    
    }
    return t[e][f] = mn;
}

int main()
{
    memset(t, -1, sizeof(t));
    cout << solve(3, 15);
}