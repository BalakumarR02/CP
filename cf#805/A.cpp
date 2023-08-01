#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

bool bipartiteDfs(ll node, vector<ll> adj[], vector<ll> &color)
{
    for (auto it : adj[node])
    {
        if (color[it] == -1)
        {
            color[it] = 1 - color[node];
            if (!bipartiteDfs(it, adj, color))
            {
                return false;
            }
        }
        else if (color[it] == color[node])
            return false;
    }
    return true;
}
void solve()
{
    ll n, i;

    cin >> n;

    vector<ll> graph[n + 1];
    unordered_map<ll, ll> mp, co;
    for (i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        co[x]++;
        co[y]++;
        if (mp[x] == y || mp[y] == x)
            continue;
        graph[x].push_back(y);
        graph[y].push_back(x);
        mp[x] = y;
        mp[y] = x;
    }
    for (i = 1; i <= n; i++)
    {
        if (co[i] != 2)
        {
            cout << "NO\n";
            return;
        }
    }
    vector<ll> color(n + 1, -1);
    queue<ll> q;
    for (i = 1; i <= n; i++)
    {
        if (color[i] == -1)
        {
            color[i] = 1;
            if (!bipartiteDfs(i, graph, color))
            {
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n";
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
