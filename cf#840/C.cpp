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
    ll maxi = 0;
    for (i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        v.push_back(x);
        maxi = max(x, maxi);
    }
    if (n >= 4 || n == 1)
    {
        cout << maxi * n;
    }
    else if (n == 2)
    {
        cout << max((v[0] + v[1]), (abs(v[0] - v[1]) * 2));
    }
    else
    {
        cout << max({(v[0] + v[1] + v[2]), 3 * v[0], 3 * v[2], (abs(v[0] - v[2]) * 3), (abs(v[1] - v[2]) * 3), (abs(v[0] - v[1]) * 3)});
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
