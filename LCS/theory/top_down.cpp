#include<iostream>
#include<vector>
using namespace std;

int LCS(string s1, string s2, int n, int m)
{
    vector<vector<int>> t(n+1, vector<int>(m+1, 0));

    for(int i = 1; i < n+1; i++)
    {
        for(int j = 1; j < m+1; j++)
        {
            if (s1[i-1] == s2[j-1])
                t[i][j] = 1 + t[i-1][j-1];
            else
                t[i][j] = max(t[i-1][j], t[i][j-1]);
        }
    }
    return t[n][m];
}

int main()
{   
    string s1 = "abcdefa";
    string s2 = "absdea";
    int n = 7, m = 6;
    
    cout << LCS(s1, s2, n, m) << endl;
}