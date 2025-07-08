#include<iostream>
#include<vector>
using namespace std;

int LRS(string s, int n)
{
    vector<vector<int>> t(n+1, vector<int>(n+1, 0));


    for(int i = 1; i < n+1; i++)
    {
        for(int j = 1; j < n+1; j++)
        {
            if (s[i-1] == s[j-1] && i != j)
                t[i][j] = 1 + t[i-1][j-1];
            else
                t[i][j] = max(t[i-1][j], t[i][j-1]);
        }
    }
    return t[n][n];
}

int main()
{   
    string s1 = "AABEBECDD";
    int n = 9;
    
    cout << LRS(s1, n) << endl;
}