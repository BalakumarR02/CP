#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll n, i;

    cin >> n;
    vector<string> v;
    map<string, ll> mp;
    for (i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        v.push_back(s);
        mp[s]++;
    }
    string ans;
    for (i = 0; i < n; i++)
    {
        ll j;
        string s = v[i];
        for (j = 0; j < s.length(); j++)
        {
            if (mp[s.substr(0, j + 1)] && mp[s.substr(j + 1, s.length() - j - 1)])
            {
                ans.push_back('1');
                break;
            }
        }
        if (j == s.length())
            ans.push_back('0');
    }
    cout << ans << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;

    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

// sort(begin(v), end(v), [] (int a, int b) { return a > b; });           (Custom sort using lambda function)
