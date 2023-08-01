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

vector<ll> fib(46, 0);
map<ll, ll> chfib;
void solve()
{
    ll n, i, x, y;

    cin >> n >> x >> y;
    ll w = fib[n + 1], h = fib[n];
    ll lef = (x - 1), bot = (y - 1), rig = (w - y), up = (h - x);
    // if (lef == rig || lef == bot || lef == up || bot == rig || bot == up || rig == up)
    // {
    //     cout << "NO\n";
    //     return;
    // }
    if (lef && !chfib[lef])
    {
        cout << "NO\n";
        return;
    }
    if (bot && !chfib[bot])
    {
        cout << "NO\n";
        return;
    }
    if (rig && !chfib[rig])
    {
        cout << "NO\n";
        return;
    }
    if (up && !chfib[up])
    {
        cout << "NO\n";
        return;
    }

    ll ans = lef * lef + rig * rig + bot * bot + up * up + 1;
    cout << ans << " ";
    if (ans == (h * w))
    {
        cout << "YES\n";
    }
    else
        cout << "NO\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t, i;
    fib[0] = fib[1] = 1;
    chfib[1]++;
    fo(i, 2, 46)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
        chfib[fib[i]]++;
    }
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

// sort(begin(v), end(v), [] (int a, int b) { return a > b; });           (Custom sort using lambda function)
