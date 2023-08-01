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

void solve()
{
    ll n, i, h, w, a, b;

    cin >> h >> w >> a >> b;
    ll dp[h + 1][w + 1];
    memset(dp, 0, sizeof(dp));

    for (ll x = 1; x <= h; x++)
    {
        for (ll y = 1; y <= w; y++)
        {
            if (x == 1 && y == 1)
                dp[x][y] = 1;
            else if ((x >= (h - a + 1)) && (y <= b))
            {
            }
            else
            {
                dp[x][y] = (dp[x - 1][y] + dp[x][y - 1]) % mod;
            }
        }
    }
    ll ans = dp[h][w];

    cout << ans << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}

// sort(begin(v), end(v), [] (int a, int b) { return a > b; });           (Custom sort using lambda function)
