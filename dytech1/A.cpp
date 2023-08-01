#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll n, i, k;
    string s, t;
    cin >> n >> k >> s;
    map<ll, ll> mp;
    for (i = 0; i < n; i++)
    {
        mp[s[i] - 'a']++;
    }

    for (i = 0; i < k; i++)
    {
        ll j, c = n / k;
        for (j = 0; j < 26 && c; j++)
        {
            if (!mp[j])
            {
                break;
            }
            mp[j]--;
            c--;
        }
        t.push_back(j + 'a');
    }
    cout << t << "\n";
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
