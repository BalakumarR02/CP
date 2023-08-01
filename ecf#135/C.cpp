#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll n, i, ans = 0;

    cin >> n;
    map<ll, ll> ma, mb;
    vector<ll> a, b;
    for (i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x;
        ma[x]++;
        a.push_back(x);
    }
    for (i = 0; i < n; i++)
    {
        ll x, y;
        cin >> y;
        mb[y]++;
        b.push_back(y);
    }
    vector<ll> na, nb;

    for (i = 0; i < n; i++)
    {

        if (mb[a[i]])
        {
            mb[a[i]]--;
        }
        if (ma[b[i]])
        {
            ma[b[i]]--;
        }
    }
    for (i = 0; i < n; i++)
    {
        if (mb[b[i]] > 0)
        {
            ll num = 0;
            if (b[i] >= 10)
            {
                num = log10(b[i]) + 1;
                nb.push_back(num);
                ans++;
            }
            else
                nb.push_back(b[i]);
            mb[b[i]]--;
        }
        if (ma[a[i]] > 0)
        {
            ll num = 0;
            if (a[i] >= 10)
            {
                num = log10(a[i]) + 1;
                na.push_back(num);
                ans++;
            }
            else
                na.push_back(a[i]);
            ma[a[i]]--;
        }
    }
    a.clear(), b.clear();
    ma.clear(), mb.clear();
    n = na.size();
    for (i = 0; i < n; i++)
    {
        ma[na[i]]++;
        mb[nb[i]]++;
    }
    for (i = 0; i < n; i++)
    {
        if (mb[na[i]])
        {
            mb[na[i]]--;
        }
        if (ma[nb[i]])
        {
            ma[nb[i]]--;
        }
    }

    for (i = 0; i < n; i++)
    {
        if (mb[nb[i]])
        {
            ll num = 0;
            if (nb[i] != 1)
            {
                num = log10(nb[i]) + 1;
                b.push_back(num);
                ans++;
            }
            mb[nb[i]]--;
        }
        if (ma[na[i]])
        {
            ll num = 0;
            if (na[i] != 1)
            {
                num = log10(na[i]) + 1;
                a.push_back(num);
                ans++;
            }
            ma[na[i]]--;
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
