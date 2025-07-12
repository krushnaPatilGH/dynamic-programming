#include<iostream>
using namespace std;

bool solve(string a, string b)
{
    if(a.compare(b) == 0) return true;
    if(a.length() <= 1) return false;

    int n = a.length();
    for(int i = 1; i<n; i++)
    {
        if((solve(a.substr(0,i), b.substr(n-i, i)) && solve(a.substr(i, n-i), b.substr(0,n-i))) ||
        (solve(a.substr(0,i), b.substr(0, i)) && solve(a.substr(i, n-i), b.substr(i,n-i))) )
            return true;
    }
    return false;
}

int main()
{
    string s1 = "great", s2 = "geatr";
    cout << solve(s1,s2);
}