#include<iostream>
#include<vector>
using namespace std;

int Insertions_to_LPS(string s1,  int n)
{
    string s2(s1.rbegin(), s1.rend());
    int  m = n;
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
    return n - t[n][m];
}

int main()
{   
    string s1 = "aebcbda";
    int n = 7;
    
    cout << Insertions_to_LPS(s1,  n) << endl;
}