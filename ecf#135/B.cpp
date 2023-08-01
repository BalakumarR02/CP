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
    if (n % 2 == 0)
    {
        for (i = 1; i < n - 1; i += 2)
        {
            cout << i + 1 << " " << i << " ";
        }
        cout << i << " " << i + 1 << " ";
    }
    else
    {
        ll m = n - 5, x = n - 2;
        while (m > 0)
        {
            cout << x << " ";
            x--;
            m--;
        }
        cout << 1 << " " << 2 << " " << 3 << " " << n - 1 << " " << n;
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
