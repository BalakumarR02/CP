#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll n, i, m, k, a[200001], b[200001];

    cin >> n >> m;
    map<ll, ll> mp;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> k;

    for (i = 0; i < k; i++)
    {
        cin >> b[i];
    }
    ll xa = 0, xb = 0, na = -1, nb = -1, j = 0;
    i = 0;
    ll x = a[i];
    while (!(x % m))
    {
        x /= m;
    }
    na = x;
    mp[a[i]] = x;
    xa += a[i];
    x = b[j];
    while (!(x % m))
    {
        x /= m;
    }
    nb = x;
    mp[b[j]] = x;
    xb += b[j];
    for (i = 1, j = 1; i < n || j < k;)
    {
        if (na != nb)
        {
            cout << "NO\n";
            return;
        }
        if (xa < xb)
        {
            if (!mp[a[i]])
            {
                x = a[i];
                while (!(x % m))
                {
                    x /= m;
                }
                mp[a[i]] = x;
            }
            na = mp[a[i]];
            xa += a[i];
            i++;
        }
        else if (xb < xa)
        {
            if (!mp[b[j]])
            {
                x = b[j];
                while (!(x % m))
                {
                    x /= m;
                }
                mp[b[j]] = x;
            }
            nb = mp[b[j]];
            xb += b[j];
            j++;
        }
        else
        {
            if (xa != xb)
            {
                cout << "NO\n";
                return;
            }
            xa = xb = 0;
            if (!mp[a[i]])
            {
                x = a[i];
                while (!(x % m))
                {
                    x /= m;
                }
                mp[a[i]] = x;
            }
            na = mp[a[i]];
            xa += a[i];
            i++;

            if (!mp[b[j]])
            {
                x = b[j];
                while (!(x % m))
                {
                    x /= m;
                }
                mp[b[j]] = x;
            }
            nb = mp[b[j]];
            xb += b[j];
            j++;
        }
    }
    if (na != nb || (xa != xb))
    {
        cout << "NO\n";
        return;
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
