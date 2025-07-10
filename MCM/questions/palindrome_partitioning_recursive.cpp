#include<iostream>
using namespace std;

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
    for(int k = i; k < j; k++)
    {
        int temp = 1 + MCM_palidrome(s, i, k) + MCM_palidrome(s, k+1, j);
        mn = min(temp, mn);
    }
    return mn;
}

int main()
{
    cout << MCM_palidrome("nitin", 0, 5);
}