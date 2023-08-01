#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

const ll N = 200001;
ll fac[N];
// Factorial
void fact(ll p)
{
    fac[0] = 1;
    for (int i = 1; i <= N; i++)
        fac[i] = (fac[i - 1] * i) % p;
}
void solve()
{
    ll n, i;

    cin >> n;
    if (n % 2 != 0)
    {
        cout << 0;
    }
    else
    {
        cout << (fac[n / 2]) * (fac[n / 2]) % mod1;
    }
    cout << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    fact(mod1);
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

// sort(begin(v), end(v), [] (int a, int b) { return a > b; });           (Custom sort using lambda function)
