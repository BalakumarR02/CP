#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll n, i, a[200001];

    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll last = a[n - 1], last_bef = a[n - 2];
    if (is_sorted(a, a + n))
    {
        cout << 0;
        cout << "\n";
        return;
    }
    else if (last < last_bef)
    {
        cout << -1 << "\n";
        return;
    }
    ll m = last_bef - last;
    if (m > last_bef)
    {
        cout << -1 << "\n";
        return;
    }
    cout << n - 2 << "\n";
    for (i = 1; i <= n - 2; i++)
    {
        cout << i << " " << n - 1 << " " << n << "\n";
    }
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
