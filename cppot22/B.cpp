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

void dfs(ll node, ll d[], vector<ll> adj[], vector<ll> vis)
{
    vis[node] = 1;
    for (ll v : adj[node])
    {
        if (!vis[v])
        {
            d[v] = d[node] + 1;
            dfs(v, d, adj, vis);
        }
    }
}
void solve()
{
    ll n, i, a, b;

    cin >> n;
    vector<ll> adj[n];
    for (i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        adj[i].push_back(x);
    }
    cin >> a >> b;
    ll d1[n], d2[n];
    memset(d1, -1, sizeof(d1));
    memset(d2, -1, sizeof(d2));
    d1[a] = 0;
    d2[b] = 0;
    vector<ll> vis(n, 0);
    dfs(a, d1, adj, vis);
    for (i = 0; i < n; i++)
    {
        vis[i] = 0;
    }
    dfs(b, d2, adj, vis);
    ll ans = n + 1, node = -1;
    for (i = n - 1; i >= 0; i--)
    {
        if (d1[i] == -1 || d2[i] == -1)
            continue;
        if (ans >= max(d1[i], d2[i]))
        {
            ans = max(d1[i], d2[i]);
            node = i;
        }
    }
    cout << node << "\n";
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
