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

ll dfs(vector<pll> adj[], vector<bool> &vis, pll node)
{
    vis[node.first] = 1;
    ll ans = 0;
    for (auto &i : adj[node.first])
    {
        if (!vis[i.first])
        {
            if (node.second < i.second)
            {
                ans = max(dfs(adj, vis, i), ans);
            }
            else
            {
                ans = max(dfs(adj, vis, i) + 1, ans);
            }
        }
    }
    return ans;
}
void solve()
{
    ll n, i;

    cin >> n;
    vector<pll> adj[n + 1];
    fo(i, 1, n - 1)
    {
        ll x, y;
        cin >> x >> y;
        adj[x].pb({y, i});
        adj[y].pb({x, i});
    }

    vector<bool> vis(n + 1, 0);
    ll ans = 0;

    cout << (dfs(adj, vis, make_pair(1, 0))) + 1;

    cout << "\n";
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
