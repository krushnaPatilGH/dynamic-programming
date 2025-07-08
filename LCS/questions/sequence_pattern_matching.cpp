#include<iostream>
#include<vector>
using namespace std;

bool LCS(string p, string s, int n, int m)
{
    vector<vector<int>> t(n+1, vector<int>(m+1, 0));

    for(int i = 1; i < n+1; i++)
    {
        for(int j = 1; j < m+1; j++)
        {
            if (p[i-1] == s[j-1])
                t[i][j] = 1 + t[i-1][j-1];
            else
                t[i][j] = max(t[i-1][j], t[i][j-1]);
        }
    }
    return (n == t[n][m]);
}

int main()
{   
    string p = "AXY";
    string s = "ADXCPY";
    int n = 3, m = 6;
    
    cout <<  "The string " << s << " with pattern " << p << " is matching : " << (LCS(p, s, n, m)? "true" : "false");
}