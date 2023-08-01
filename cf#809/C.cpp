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
    vector<ll> v;
    for (i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        v.push_back(x);
    }
    map<ll, ll> mp, ze;
    mp[v[n - 1]] = n - 1;
    for (i = n - 2; i >= 0; i--)
    {
        if (v[i] <= v[i + 1])
        {
            if (mp.find(v[i]) == mp.end())
            {
                mp[v[i]] = i;
            }
        }
        else
            break;
    }
    ll ans = 0;
    for (ll j = 0; j <= i; j++)
    {
        if (mp.find(v[j]) != mp.end())
        {
            i = max(mp[v[j]], i);
        }
        if (ze.find(v[j]) == ze.end())
        {
            ze[v[j]] = 1;
            ans++;
        }
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
