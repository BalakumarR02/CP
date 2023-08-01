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

ll query(ll r, ll c)
{
    ll x;
    cout << "? " << r << " " << c << endl;
    cin >> x;
    return x;
}
void solve()
{
    ll n, i, m;

    cin >> n >> m;
    ll x1 = query(1, 1);
    ll x2 = query(n, m);
    ll cx1 = x1 + 1, cy1 = x1 + 1;
    ll cx2 = n - x2, cy2 = m - x2;
    ll x, y;
    ll mx1, mx2, my1, my2;
    mx1 = cx1, my1 = cy2;
    mx2 = cx2, my2 = cy1;
    if (x1 + x2 == n - 1)
    {
        x = 1 + x1;
        y = 1 + query(x, 1);
        cout << "! " << x << " " << y << endl;
        return;
    }
    else if (x1 + x2 == m - 1)
    {
        y = 1 + x1;
        x = 1 + query(1, y);
        cout << "! " << x << " " << y << endl;
        return;
    }
    else
    {
        if (1 + x1 <= n && m - x2 >= 1 && query(1 + x1, m - x2) == 0)
        {
            x = 1 + x1;
            y = m - x2;
        }
        else
        {
            x = n - x2;
            y = 1 + x1;
        }
    }
    cout << "! " << x << " " << y << endl;
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
