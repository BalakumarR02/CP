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
    vector<pll> p;
    fo(i, 1, n)
    {
        ll x;
        cin >> x;

        p.pb({x, i - 1});
    }
    sort(all(p));
    vll hash(n + 1, 0), p1(n + 1, 0), p2(n + 1, 0), ze;
    set<ll> st;
    ll x = 1;
    fo(i, 0, n - 1)
    {
        ll val = p[i].first, ind = p[i].second;
        hash[val]++;
    }
    fo(i, 0, n - 1)
    {
        if (!hash[i + 1])
            ze.pb(i + 1);
    }

    ll j = 0;
    fo(i, 0, n - 1)
    {
        ll val = p[i].first, ind = p[i].second;

        if (hash[val] == 1)
        {
            p1[ind] = val;
            p2[ind] = val;
            if (val == x)
            {
                x++;
            }
        }
        else if (hash[val] == 2 && ze[j] < val)
        {

            p1[ind] = ze[j];
            p2[ind] = val;
            i++;
            ind = p[i].second;
            p1[ind] = val;
            p2[ind] = ze[j];
            j++;
        }
        else
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    fo(i, 0, n - 1)
    {
        cout << p1[i] << " ";
    }
    cout << "\n";
    fo(i, 0, n - 1)
    {
        cout << p2[i] << " ";
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
