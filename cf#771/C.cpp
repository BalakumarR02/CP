#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll n, i, a[200001], h[200001] = {0};

    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll max_so = a[0], ans = 0, c = 0;
    for (i = 1; i < n; i++)
    {
        c++;
        if (a[i] > max_so)
        {
            if ((c) == max_so)
            {
                ans++;
            }
            max_so = a[i];
        }
    }
    if (c + 1 == max_so)
    {
        ans++;
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