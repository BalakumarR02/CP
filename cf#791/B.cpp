#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll n, i, q, s = 0;

    cin >> n >> q;
    map<ll, ll> mp;
    for (i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        mp[i] = x;
        s += x;
    }
    ll t, x, j, oth = -1;
    i = 0;
    for (j = 0; j < q; j++)
    {
        cin >> t;
        if (t == 1)
        {
            cin >> i >> x;
            if (mp.size() == n)
                s += (x - mp[i]);
            else if (!mp[i])
            {
                s += (x - oth);
            }
            else
            {
                s += (x - mp[i]);
            }
            cout << s << "\n";
            mp[i] = x;
        }
        else
        {
            cin >> x;
            s = x * n;
            mp.clear();
            oth = x;
            cout << s << "\n";
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}

// sort(begin(v), end(v), [] (int a, int b) { return a > b; });           (Custom sort using lambda function)
