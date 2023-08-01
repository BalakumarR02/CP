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
    ll sum = 0, od = 0;
    for (i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        v.push_back(x);
        if (x % 4 == 1 || x % 4 == 2)
        {
            od++;
        }

        sum += x;
    }
    if (sum % 2 == 0)
        cout << 0;
    else if (od)
    {
        cout << 1;
    }
    else
    {
        ll k = 0, ans = 1e9;
        for (i = 0; i < n; i++)
        {
            ll p = v[i] % 2;
            while (v[i] % 2 == p)
            {
                k++;
                v[i] /= 2;
            }
            ans = min(ans, k);
            k = 0;
        }
        cout << ans;
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
