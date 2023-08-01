

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll mod = 1e9 + 7;

const ll N = 200001;
ll fac[N];
// Factorial
void fact(ll p)
{
    fac[0] = 1;
    for (int i = 1; i <= N; i++)
        fac[i] = (fac[i - 1] * i) % p;
}

// MOD Power
ll power(ll x, ll y, ll p)
{
    ll res = 1;
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

// Fermat's MOD Inverse
ll modInverse(ll n, ll p)
{
    return power(n, p - 2, p);
}

// nCr
ll nCrModPFermat(ll n, ll r, ll p)
{
    if (n < r)
        return 0;
    if (r == 0)
        return 1;
    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
}

// new
ll inv(ll i)
{
    if (i == 1)
        return 1;
    return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;
}

ll mod_mul(ll a, ll b)
{
    a = a % mod;
    b = b % mod;
    return (((a * b) % mod) + mod) % mod;
}

ll mod_add(ll a, ll b)
{
    a = a % mod;
    b = b % mod;
    return (((a + b) % mod) + mod) % mod;
}

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll ceil_div(ll a, ll b) { return a % b == 0 ? a / b : a / b + 1; }

ll pwr(ll a, ll b)
{
    a %= mod;
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
// end

int main()
{

    fact(mod);
    return 0;
}