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
    ll n, i, m, j;

    // cin >> n;
    string a, b;
    cin >> a >> b;
    n = a.length(), m = b.length();
    string lcs = "";
    if (a[0] == b[0])
    {
        cout << "YES\n";
        cout << a[0] << "*\n";
        return;
    }
    else if (a[n - 1] == b[m - 1])
    {
        cout << "YES\n";

        cout << "*" << a[n - 1] << "\n";
        return;
    }
    lcs.pb('*');
    for (i = 0; i < n - 1; i++)
    {
        ll p, len = 0;
        string val = "", match = "";
        match.pb(a[i]);
        match.pb(a[i + 1]);
        for (j = 0; j < m - 1; j++)
        {
            string val = "";
            val.pb(b[j]);
            val.pb(b[j + 1]);

            if (val == match)
            {
                cout << "YES\n";

                cout << "*" << val << "*"
                     << "\n";
                return;
            }
        }
    }

    cout << "NO\n";
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
