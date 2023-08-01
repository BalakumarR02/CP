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

const ll mod = 1e9 + 7;
const ll mod1 = 998244353;
const ll N = 1e5; // limit for array size

vector<pll> primeFactors(ll n)
{
    // Print the number of 2s that divide n
    vector<pll> val;
    ll x = 0;
    while (n % 2 == 0)
    {
        x++;
        n = n / 2;
    }
    if (x)
        val.pb({x, 2});

    for (ll i = 3; i <= sqrt(n); i = i + 2)
    {
        // While i divides n, print i and divide n
        ll x = 0;

        while (n % i == 0)
        {
            x++;
            n = n / i;
        }
        if (x)
            val.pb({x, i});
    }

    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2)
        val.pb({1, n});
    return val;
}
void solve()
{
    ll n, i;

    cin >> n;
    ll n1 = n;
    vector<pll> val = primeFactors(n1);
    sort(all(val));
    reverse(all(val));
    ll ans = 0, bef = -1, num = -1;
    for (auto itr = val.begin(); itr != val.end(); itr++)
    {

        if (bef == -1)
        {
            num = itr->second;
            bef = itr->first;
        }
        else
        {
            ll cnum = itr->second;
            ll cbef = itr->first;
            ans += max(0LL, (bef - cbef) * num);
            ans += max(0LL, (cbef - bef) * cnum);
            bef = min(bef, cbef);
            num = cnum * num;
        }
    }
    ans += (num * bef);

    cout << ans << "\n";
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
