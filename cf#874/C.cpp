#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define lb lower_bound
#define ub upper_bound
#define all(v) (v).begin(), (v).end()
#define all1(v) (v).begin() + 1, (v).end()
#define allr(v) (v).rbegin(), (v).rend()
#define allr1(v) (v).rbegin() + 1, (v).rend()
#define sort0(v) sort(all(v))
#define fo(i, a, b) for (i = a; i <= b; i++)
#define fon(i, a, b) for (i = a; i < b; i++)
#define fi(i, a, b) for (i = a; i >= b; i--)

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
#define rep(i, begin, end)                                                              \
    for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); \
         i += 1 - 2 * ((begin) > (end)))
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;

#define sz(x) (ll) x.size()
#define pb push_back
#define ppb pop_back
#define mkp make_pair
#define inf 1000000000000000005

const ll mod = 1e9 + 7;
const ll mod1 = 998244353;
const ll N = 200007;
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
ll nCr(ll n, ll r, ll p)
{
    if (n < r)
        return 0;
    if (r == 0)
        return 1;
    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
}
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

void solve()
{
    ll n, i, m;

    cin >> n >> m;
    set<pll> st;
    map<ll, ll> mp;
    fo(i, 1, n)
    {
        ll x;
        cin >> x;

        mp[x]++;
    }
    ll p = mp.size();
    vector<ll> v(p + 1, 1);

    i = 0;
    for (auto &it : mp)
    {
        i++;
        st.insert({it.first, i});
        v[i] = ((v[i - 1] % mod) * (it.second)) % mod;
    }

    ll ans = 0;
    for (auto it = st.begin(); it != st.end(); it++)
    {
        auto x = st.lower_bound({it->first + m, 0LL});
        x--;
        ll sec_index = x->second, fir_index = it->second;
        ll total = sec_index - fir_index + 1;
        // cout<<it->first<<" "<<sec_index<<" "<<fir_index<<"  ";
        if (total < m)
            break;
        ll prod = v[sec_index] / v[fir_index - 1];
        // cout<<prod<<" "<<total<<" ";
        ans = ((ans % mod) + (prod % mod) * (nCr(total, m, mod))) % mod;
        // cout<<ans<<"  ";
    }

    cout << ans << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    fact(mod);
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

// sort(begin(v), end(v), [] (int a, int b) { return a > b; });           (Custom sort using lambda
// function)
