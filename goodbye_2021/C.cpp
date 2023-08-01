#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll n, i, a[100], j, ans = 1e9, k, m = 0;
    double diff, num;

    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if (n <= 2)
    {
        cout << 0 << "\n";
        return;
    }
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (j == i)
                continue;
            m = 0;
            diff = (double)(a[j] - a[i]) / (j - i);
            for (k = 0; k < n; k++)
            {
                num = a[i] - diff * (i - k);
                if (abs(a[k] - num) > 1e-3)
                {
                    m++;
                }
            }

            ans = min(m, ans);
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
