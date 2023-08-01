#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll n, i, fir;

    cin >> n;
    vector<ll> v;
    for (i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        if (i == 0)
            fir = x;
        else
            v.push_back(x);
    }
    sort(v.begin(), v.end());
    for (i = 0; i < n - 1; i++)
    {
        if (v[i] > fir)
        {
            ll dif = v[i] - fir;
            fir += (dif + 1) / 2;
        }
    }
    cout << fir << "\n";
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
