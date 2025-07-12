#include<iostream>
#include<unordered_map>
using namespace std;

unordered_map<string, int> mp;
int solve(string s, int i, int j, bool isTrue)
{
    if (i > j) return false;
    if (i == j){
        if (isTrue) return s[i] == 'T';
        else return s[i] == 'F';}

    string temp = to_string(i);
    temp.push_back(' ');
    temp.append(to_string(j));
    temp.push_back(' ');
    temp.append(to_string(isTrue));
    
    if (mp.find(temp) != mp.end())
        return mp[temp];
    int ans = 0;
    for(int k = i+1; k<j; k+=2)
    {
        int lt = solve(s, i, k-1, true);
        int rt = solve(s, k+1, j, true);
        int lf = solve(s, i, k-1, false);
        int rf = solve(s, k+1, j, false);
        switch (s[k])
        {
            case '&':
                if (isTrue)
                    ans+=lt*rt;
                else ans += lt * rf + lf * rt + lf * rf; 
                break;
            case '|':
                if (isTrue)
                        ans+= lt * rt + lt * rf + lf * rt;
                else ans +=  lf * rf; 
                break;
            case '^':
                if (isTrue)
                        ans+= lt * rf + lf * rt;
                else ans += lt * rt + lf * rf; 
            default:
                break;
        }
    }
    return mp[temp] = ans;
}

int main()
{
    mp.clear();
    string s = "T|F&T";
    cout << solve(s, 0, 4, true);
}