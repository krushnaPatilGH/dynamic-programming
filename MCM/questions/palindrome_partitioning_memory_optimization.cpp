#include<iostream>
#include<cstring>
using namespace std;

int t[1001][1001];

bool is_pali(string s, int i, int j)
{
    while(i<j)
    {
        if(s[i] != s[j] ) return false;
        i++; j--;
    }
    return true;
}

int MCM_palidrome(string s, int i, int j)
{
    if (i >= j || is_pali(s,i,j-1)) return 0;
    int mn = INT_MAX;
    int temp, left, right;
    for(int k = i; k < j; k++)
    {
        if(t[i][k] != -1) left = t[i][k]; else left = MCM_palidrome(s, i, k);
        if(t[k+1][j] != -1) right = t[k+1][j]; else right = MCM_palidrome(s, k+1, j);
        temp = 1 + left + right;
        mn = min(temp, mn);
    }
    return t[i][j] = mn;
}

int main()
{
    memset(t, -1, sizeof(t));
    cout << MCM_palidrome("anitinj", 0, 7);
}