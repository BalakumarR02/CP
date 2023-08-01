#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll n, i, k;

    cin >> n >> k;
    if (k == n - 1)
    {
        if (n == 4)
        {
            cout << -1 << "\n";
        }
        else
        {
            cout << n - 2 << " " << n - 1 << "\n";
            cout << 1 << " " << 3 << "\n";
            cout << 0 << " " << n - 4 << "\n";
            for (i = 2; i < (n + 1) / 2; i++)
            {
                if (i == 3)
                    continue;
                cout << i << " " << n - i - 1 << "\n";
            }
        }
        return;
    }
    cout << k << " " << n - 1 << "\n";
    if (k != 0)
        cout << 0 << " " << n - 1 - k << "\n";
    for (i = 1; i < (n + 1) / 2; i++)
    {
        if (i == k || i == n - 1 - k)
            continue;
        cout << i << " " << n - i - 1 << "\n";
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
