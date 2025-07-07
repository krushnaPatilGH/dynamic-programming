#include<iostream>
#include<cstring>
using namespace std;

int t[1000][1000];

int lcs(string s1, string s2, int n, int m )
{
    if (n == 0 || m == 0)   return 0;
    if (t[n][m] != -1) return t[n][m];

    if (s1[n-1] == s2[m-1]) return t[n][m] = 1 + lcs(s1, s2, n-1, m-1 );
    return t[n][m]= max(lcs(s1, s2, n, m-1 ), lcs(s1, s2, n-1, m));
}

int main()
{   
    string s1 = "abcdefj";
    string s2 = "absdea";
    int n = 7, m = 6;
    memset(t, -1, sizeof(t));

    cout << lcs(s1, s2, n, m);
}