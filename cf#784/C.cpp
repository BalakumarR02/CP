#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll n, i, a[200001];
    map<ll, vector<ll>> mp;

    cin >> n;
    ll x = 1;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]].push_back(i);
    }
    ll ans = -9, num = a[0], fl, fr;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        vector<ll> p = it->second;
        ll curmax = 0, allmax = 0, x = it->first, dl = p[0] + 1, l = p[0] + 1, r = p[0] + 1;
        for (i = 1; i < (ll)p.size(); i++)
        {
            curmax++;
            curmax -= (p[i] - p[i - 1] - 1);
            if (allmax < curmax)
            {
                allmax = curmax;
                l = dl;
                r = p[i] + 1;
            }
            if (curmax < 0)
            {
                curmax = 0;
                dl = p[i] + 1;
            }
        }
        if (ans < allmax)
        {
            ans = allmax;
            num = x;
            fl = l;
            fr = r;
        }
    }

    cout << num << " " << fl << " " << fr << "\n";
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
