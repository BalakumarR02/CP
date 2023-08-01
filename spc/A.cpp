#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll n, i, p;

    cin >> n >> p;
    vector<ll> v, non;
    ll ini = 0;
    non.push_back(-(1e9 + 7));
    for (i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        v.push_back(x);
        if (x)
            non.push_back(i);
    }
    non.push_back((1e9 + 7));

    if (n == 1)
    {
        cout << 0 << "\n";
        return;
    }
    map<ll, ll> mp;
    for (i = 0; i < n; i++)
    {
        if (v[i])
        {
            mp[i] = 0;
        }
        else
        {

            auto itr = lower_bound(non.begin(), non.end(), i);
            mp[i] = abs(i - (*itr));
            itr--;
            mp[i] = min(mp[i], abs(i - (*itr)));
        }
    }
    ll fin = 0;
    for (i = 0; i < n; i++)
    {
        ll x = max(((p - mp[i]) * 2), 0LL);
        fin += x;
        if (i != 0 && i != n - 1)
        {
            fin += x;
        }
    }
    cout << fin << "\n";
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
