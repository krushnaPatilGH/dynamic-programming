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
    if (t[i][j] != -1) return t[i][j];
    int mn = INT_MAX;
    for(int k = i; k < j; k++)
    {
        int temp = 1 + MCM_palidrome(s, i, k) + MCM_palidrome(s, k+1, j);
        mn = min(temp, mn);
    }
    return t[i][j] = mn;
}

int main()
{
    memset(t, -1, sizeof(t));
    cout << MCM_palidrome("nitin", 0, 5);
}