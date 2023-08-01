#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll n, i, a[200001], mi = 1e9 + 1, ma = 0, j, k;

    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        if (mi > a[i])
        {
            mi = a[i];
            j = i;
        }
        if (ma < a[i])
        {
            ma = a[i];
            k = i;
        }
    }

    cout << j + 1 << " " << k + 1 << "\n";
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
