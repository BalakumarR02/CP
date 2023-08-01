#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;
vector<ll> vis((100000 + 1), 0);

ll m1 = 0, m2 = 0, ans = 0;
void dfs(ll s[], vector<ll> adj[], ll node, ll par)
{
    vis[node] += s[node];

    for (ll v : adj[node])
    {
        if (v != par)
        {
            dfs(s, adj, v, node);
            if (vis[v] == m1 || vis[v] == m2)
            {
                ans++;
            }
            vis[node] += vis[v];
        }
    }
}
void solve()
{
    ll n, i;

    cin >> n;
    vector<ll> adj[n + 1];
    for (i = 1; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    ll s[n + 1];
    for (i = 1; i <= n; i++)
    {
        char c;
        cin >> c;
        if (c == 'C')
        {
            s[i] = 1;
            m1++;
        }
        else if (c == 'L')
        {
            s[i] = -1;
            m2--;
        }
        else
            s[i] = 0;
    }

    dfs(s, adj, 1, 0);

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
