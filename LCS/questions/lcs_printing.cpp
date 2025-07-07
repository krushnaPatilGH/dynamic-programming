#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

string LCS_print(string s1, string s2, int n, int m)
{
    vector<vector<int>> t(n+1, vector<int>(m+1, 0));
    for(int i = 1; i < n+1; i++)
    {
        for(int j = 1; j < m+1; j++)
        {
            if (s1[i-1] == s2[j-1])
            {
                t[i][j] = 1 + t[i-1][j-1];
            }
            else
                t[i][j] = 0;
        }
    }

    int i = n, j = m;
    string s = "";
    while(i > 0 && j > 0)
    {
        if (s1[i-1] == s2[j-1])
        {
            s.push_back(s1[i-1]);
            i--;
            j--;
        }
        else if (t[i-1][j] > t[i][j-1])
            i--;
        else
            j--;
    }
    reverse(s.begin(), s.end());
    return s;
}

int main()
{   
    string s1 = "abcdefa";
    string s2 = "abcaea";
    int n = 7, m = 6;
    

    cout << LCS_print(s1, s2, n, m) << endl;
}