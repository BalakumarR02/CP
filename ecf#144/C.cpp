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
#define fi(i, a, b) for (i = a; i >= b; i--)

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;

#define sz(x) (ll) x.size()
#define pb push_back
#define ppb pop_back
#define mkp make_pair
#define inf 1000000000000000005

const ll mod1 = 1e9 + 7;
const ll mod = 998244353;
const ll N = 1e5; // limit for array size

ll mod_mul(ll a, ll b)
{
    a = a % mod;
    b = b % mod;
    return (((a * b) % mod) + mod) % mod;
}
void solve()
{
    ll n, i, l, r, j;

    cin >> l >> r;
    ll mx_size = 0;
    ll val = l, m2val = r, m3val = r, val1 = 1;
    vector<ll> all_val;
    while (val <= r)
    {
        val *= 2;
        mx_size++;
    }
    val = 1;
    for (i = 1; i < mx_size; i++)
    {
        val1 *= 2;
        if (i == mx_size - 1)
            val *= 3;
        else
            val *= 2;
    }
    // cout << m2val << " " << m3val << " ";
    m2val /= val1;
    m3val /= val;
    ll ans = 0;
    ans += (m2val - l + 1);
    if (mx_size > 1)
        ans = (ans % mod + (max(0LL, m3val - l + 1) * (mx_size - 1) % mod)) % mod;

    cout << mx_size << " " << ans % mod << "\n";
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
