#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define mod 1000000007;
#define mod1 998244353;
ll isEven(ll x)
{
    ll i;
    for (i = 0; i <= 30; i++)
    {
        if ((1 << i) & x)
        {
            return i;
        }
    }
    return i;
}
void solve()
{
    ll n, i, a[200001];

    cin >> n;
    ll od = 0;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] % 2 != 0)
            od++;
    }
    if (od == n)
    {
        cout << "0\n";
        return;
    }
    if (od)
    {
        cout << n - od << "\n";
        return;
    }
    ll isev = 1e9;
    for (i = 0; i < n; i++)
    {
        isev = min(isev, isEven(a[i]));
    }
    cout << n - 1 + isev << "\n";
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
