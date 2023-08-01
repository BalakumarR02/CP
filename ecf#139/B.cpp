#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll n, i, j;
    string s;
    cin >> n >> s;
    map<string, ll> mp;
    for (i = 0; i < n - 1; i++)
    {
        string a = "";
        a.append(s, i, 2);
        if (mp[a] && mp[a] != (i))
        {
            cout << "YES\n";
            return;
        }
        else if (!mp[a])
            mp[a] = i + 1;
    }

    cout << "NO\n";
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
