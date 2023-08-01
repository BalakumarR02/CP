#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll n, a, b, i;

    cin >> a >> b;
    ll k = 0, intest = 0;

    for (i = a; i <= b; i++)
    {
        ll sum = 0, prod = 1;
        n = i;
        while (n)
        {
            prod *= ((n % 10));
            sum += (n % 10);
            n /= 10;
        }
        if (prod % (sum) == 0)
        {
            intest++;
        }
    }

    cout << intest << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;

    cin >> t;
    for (ll i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}

// sort(begin(v), end(v), [] (int a, int b) { return a > b; });           (Custom sort using lambda function)
