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
    vector<ll> a;
    ll pos = 0, neg = 0, ze = 0;
    bool ok = true;
    for (i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        if (x > 0)
        {
            pos++;
            if (pos >= 3)
            {
                ok = false;
                continue;
            }
            a.push_back(x);
        }
        else if (x < 0)
        {
            neg++;
            if (neg >= 3)
            {
                ok = false;
                continue;
            }
            a.push_back(x);
        }
        else if (x == 0 && ze <= 2)
        {
            ze++;
            a.push_back(x);
        }
    }
    if (!ok)
    {
        cout << "NO\n";
        return;
    }
    ll m = a.size(), j, k;
    for (i = 0; i < m; i++)
    {
        for (j = i + 1; j < m; j++)
        {
            for (k = j + 1; k < m; k++)
            {
                ok = false;
                for (int l = 0; l < m; l++)
                {
                    if (a[i] + a[j] + a[k] == a[l])
                    {
                        ok = true;
                    }
                }
                if (!ok)
                {
                    cout << "NO\n";
                    return;
                }
            }
        }
    }
    cout << "YES\n";
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
