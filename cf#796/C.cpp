#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define mod 1000000007;
#define mod1 998244353;

void solve()
{
    ll n, i;

    cin >> n;
    string s;
    map<ll, ll> mp;

    for (i = 0; i <= 2 * n; i++)
    {
        cin >> s;
        for (ll j = 0; j < (ll)s.length(); j++)
        {
            mp[s[j] - 'a'] ^= 1;
        }
    }
    for (i = 0; i < 26; i++)
    {
        if (mp[i])
        {
            cout << (char)('a' + i) << "\n";
            return;
        }
    }

    cout << "\n";
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
