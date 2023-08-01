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
    ll n, i;

    cin >> n;
    vector<ll> adj[n + 2];
    fo(i, 0, n - 2)
    {
        ll x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    vector<ll> vis(n + 2, 0);
    vis[1] = 1;
    queue<pll> q;
    q.push({1, 1});
    ll mval = 1;
    vector<ll> bfs[n + 1];
    while (!q.empty())
    {
        ll node = q.front().first, val = q.front().second;
        q.pop();
        ll child = 0;
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                vis[it] = 1;
                q.push({it, val + 1});
                child++;
                mval = max(val + 1, mval);
            }
        }
        bfs[val].pb(child);
        // cout << child << " " << val << "  ";
    }
    for (i = 1; i <= mval; i++)
    {
        map<ll, ll> mp;
        ll sn = bfs[i].size();
        for (ll j = 0; j < sn; j++)
        {
            mp[bfs[i][j]]++;
            // cout << bfs[i][j] << " ";
        }
        // cout << "\n";
        ll od = 0;
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            ll val = it->second;
            od += val % 2;
        }
        if (od > 1)
        {
            cout << "NO\n";
            return;
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
