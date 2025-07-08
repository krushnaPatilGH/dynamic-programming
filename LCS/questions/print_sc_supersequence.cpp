#include<iostream>
#include<vector>
using namespace std;

string SCS_print(string s1, string s2, int n, int m)
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
        {
            s.push_back(s1[i-1]);
            i--;
        }
        else
        {   s.push_back(s2[j-1]); 
            j--;
        }
    }
    while(i>0)  s.push_back(s1[--i]);
    while(j>0)  s.push_back(s2[--j]);
    return string(s.rbegin(), s.rend());
}

int main()
{   
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";
    int n = 6, m = 7;
    
    cout << SCS_print(s1, s2, n, m) << endl;
}