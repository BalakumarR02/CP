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

    if (n % 2 != 0)
    {
        cout << 2 << "\n";
        return;
    }

    ll sq = (ll)ceil((double)sqrt(n)), n1, k = 0, x;
    for (i = sq; i >= 2; i--)
    {
        k = 0;
        x = ((n + 1) / i) - 1;
        n1 = x;
        ll p = n1 + 1;
        while (n1 + p <= n)
        {
            n1 += p;
            p++;
            k++;
        }
        k++;
        if (n1 == n)
        {
            cout << k << "\n";
            return;
        }
        else
        {
            if ((n - n1) <= n1 && (n - n1) >= x)
            {
                continue;
            }
            k++;
            cout << k << "\n";
            return;
        }
    }
    cout << -1 << "\n";
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
