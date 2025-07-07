#include<iostream>
#include<vector>
using namespace std;

int lcs(string s1, string s2, int n, int m)
{
    if (n == 0 || m == 0)   return 0;

    if (s1[n-1] == s2[m-1]) return 1 + lcs(s1, s2, n-1, m-1);
    return max(lcs(s1, s2, n, m-1), lcs(s1, s2, n-1, m));
}

int main()
{
    string s1 = "aabcdef";
    string s2 = "absdoa";
    int n = 7, m = 6;
    vector<vector<int>> t(n+1, vector<int>(m+1, -1));
    cout << lcs(s1, s2, n, m);
}