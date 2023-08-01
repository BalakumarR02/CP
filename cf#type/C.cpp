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

void solve()
{
    ll n, i, s;

    cin >> n >> s;
    vector<ll> v(n + 1, 0), y(n + 1, 0);
    fo(i, 1, n)
    {
        ll x;
        cin >> x;
        v[i] = x;
    }
    ll ans = v[1] * v[2];
    if ((v[3] <= v[1]))
    {
        y[2] = max(max(v[2] - s, 0LL), s);
    }
    else
        y[2] = min(max(v[2] - s, 0LL), s);
    ans += (y[2] * (v[3] - v[1]));
    // cout << y[2] << " " << ans << " ";
    fo(i, 3, n - 1)
    {
        if (y[i - 1] >= v[i + 1])
        {
            y[i] = max(max(v[i] - s, 0LL), s);
        }
        else
            y[i] = min(max(v[i] - s, 0LL), s);
        ans += (y[i] * v[i + 1] - y[i - 1] * y[i]);
        cout << y[i] << " ";
    }

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
