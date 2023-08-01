#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll mod = 998244353;
unsigned long long fac[200002];

unsigned long long power(unsigned long long x, ll y, ll p)
{
    unsigned long long res = 1;

    x = x % p;

    while (y > 0)
    {

        if (y & 1)
            res = (res * x) % p;

        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

unsigned long long modInverse(unsigned long long n, ll p)
{
    return power(n, p - 2, p);
}

unsigned long long nCr(unsigned long long n, ll r, ll p)
{
    if (n < r)
        return 0;
    if (r == 0)
        return 1;

    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
}
void solve()
{

    ll t, n, i, a[200002], j, ans, p;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    i = lower_bound(a, a + n, a[n - 1]) - a;
    j = upper_bound(a, a + n, a[n - 1]) - a;
    if ((j - i) > 1)
    {
        cout << (fac[n] % mod) << endl;
        return;
    }
    else if ((a[i] - a[i - 1]) > 1)
    {
        cout << 0 << endl;
        return;
    }
    j = lower_bound(a, a + n, a[i - 1]) - a;
    ans = fac[n] % mod;
    p = 0;
    for (i = 0; i < n; i++)
    {
        p = p % mod + ((fac[n - i - 1] % mod) * (nCr(j, i, mod) % mod) * (fac[i] % mod)) % mod;
    }
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    fac[0] = 1;
    for (int i = 1; i < 200002; i++)
        fac[i] = (fac[i - 1] % mod) * (i % mod);

    ll t;

    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
