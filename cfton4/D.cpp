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
    ll n, i, q, l = -1, r = 1e18;

    cin >> q;
    while (q--)
    {
        ll val, a, b;
        cin >> val;
        if (val == 1)
        {
            cin >> a >> b >> n;

            ll low = (n - 2) * (a - b) + a + 1, high = (n - 1) * (a - b) + a;
            if (n == 1)
            {
                low = 1;
            }
            if ((low <= r) || (high >= l))
            {
                l = max(low, l);
                r = min(high, r);
                // cout << l << " " << r << "  ";
            }
            if (l == low || r == high)
                cout << 1 << " ";
            else
                cout << 0 << " ";
        }
        else
        {
            cin >> a >> b;
            if (l == -1)
            {
                cout << -1 << " ";
                continue;
            }
            ll t1 = l <= a ? 1LL : (l - b + a - b - 1) / (a - b);
            ll t2 = r <= a ? 1LL : (r - b + a - b - 1) / (a - b);
            if (t1 == t2)
            {
                cout << t1 << " ";
            }
            else
                cout << "-1 ";
        }
    }

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