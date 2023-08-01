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
const ll N = 1e5 + 7; // limit for array size

ll lvl[N], dist1[N], dist2[N];
ll end1, end2, maxi = -1;

void dfs(vector<ll> adj[], ll u, ll p)
{
    // Calculating level of nodes
    lvl[u] = 1 + lvl[p];
    if (lvl[u] > maxi)
    {
        maxi = lvl[u];
        end1 = u;
    }

    for (auto i : adj[u])
    {
        if (i != p)
        {
            dfs(adj, i, u);
        }
    }
}

void dfs1(vector<ll> adj[], ll u, ll p)
{

    lvl[u] = 1 + lvl[p];
    if (lvl[u] > maxi)
    {
        maxi = lvl[u];
        end2 = u;
    }

    for (auto i : adj[u])
    {
        if (i != p)
        {
            dfs1(adj, i, u);
        }
    }
}

void clear(ll n)
{

    for (ll i = 0; i <= n; i++)
    {
        lvl[i] = 0;
    }

    maxi = 0;
    dist1[0] = dist2[0] = -1;
}

void dfsd1(vector<ll> adj[], ll u, ll p)
{

    dist1[u] = 1 + dist1[p];
    for (auto i : adj[u])
    {
        if (i != p)
        {
            dfsd1(adj, i, u);
        }
    }
}

void dfsd2(vector<ll> adj[], ll u, ll p)
{
    dist2[u] = 1 + dist2[p];
    for (auto i : adj[u])
    {
        if (i != p)
        {
            dfsd2(adj, i, u);
        }
    }
}
void solve()
{
    ll n, i;

    cin >> n;
    vector<ll> adj[n + 1];
    fo(i, 1, n - 1)
    {
        ll x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    end1 = end2 = -1;
    memset(dist1, 0, sizeof(dist1));
    memset(dist2, 0, sizeof(dist2));
    clear(n);

    dfs(adj, 1, 0);
    clear(n);
    dfs1(adj, end1, 0);

    dfsd1(adj, end1, 0);
    dfsd2(adj, end2, 0);

    vector<ll> ans;
    for (i = 1; i <= n; i++)
    {
        ll x = dist1[i];
        ll y = dist2[i];

        ans.pb(max(x, y));
    }
    sort(all(ans));
    // for (i = 0; i < n; i++)
    // {
    //     cout << ans[i] << " ";
    // }
    ll val = 1, j = 0;
    fo(i, 0, n - 1)
    {
        while (j < n && ans[j] < (i + 1))
        {
            j++;
            val++;
        }
        if (j == n)
        {
            val--;
            j++;
        }
        cout << val << " ";
    }

    cout << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}

// sort(begin(v), end(v), [] (int a, int b) { return a > b; });           (Custom sort using lambda function)
