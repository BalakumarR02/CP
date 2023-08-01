#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;
const ll N = 1e7 + 10;
ll spf[N];
void sieve()
{
    spf[1] = 1;
    for (int i = 2; i < N; i++)
        spf[i] = i;

    for (ll i = 2; i * i <= N; i++)
    {
        if (spf[i] == i)
        {
            for (ll p = i * i; p <= N; p += i)
            {
                spf[p] = i;
            }
        }
    }
}

vector<ll> getFact(ll x)
{
    vector<ll> ret;
    while (x != 1)
    {
        ll j = (spf[x]);
        while (x % j == 0)
        {
            x /= j;
        }
        ret.push_back(j);
    }
    return ret;
}
void solve()
{
    ll a, b, i, ans = 0;

    cin >> a >> b;

    if (__gcd(b, a) > 1)
    {
        cout << 0 << "\n";
        return;
    }
    else if (a % 2 == b % 2)
    {
        cout << 1 << "\n";
        return;
    }
    else if ((b - a) == 1)
    {
        cout << -1 << "\n";
        return;
    }
    ll k = 1e9, dif = b - a;
    vector<ll> fact = getFact(dif);

    for (auto v : fact)
    {
        if ((a % v) == (b % v))
            k = min(k, (v - (a % v)));
    }

    cout << k << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    sieve();
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

// sort(begin(v), end(v), [] (int a, int b) { return a > b; });           (Custom sort using lambda function)
