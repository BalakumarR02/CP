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
    ll n, i, eq = 1, on = 0;

    cin >> n;
    vector<pll> v(n + 1);
    multiset<ll> st;
    fo(i, 1, n)
    {
        ll x;
        cin >> x;
        v[i] = {x, i};
        if (i > 1 && x != v[i - 1].first)
            eq = 0;
        if (x == 1)
            on = 1;
    }
    if (eq)
    {
        cout << "0\n";
        return;
    }
    else if (on)
    {
        cout << "-1\n";
        return;
    }
    sort(v.begin() + 1, v.end());
    vector<pll> ans;
    while (v[1].first != v[n].first)
    {
        ll lv = v[1].first;
        ll ind = upper_bound(v.begin() + 1, v.end(), make_pair(lv, (ll)1e9)) - (v.begin());
        v[ind].first = ceil((double)v[ind].first / v[1].first);
        ans.pb({v[ind].second, v[1].second});
        sort(v.begin() + 1, v.end());
    }
    ll m = ans.size();
    cout << m << "\n";
    fo(i, 0, m - 1)
    {
        cout << ans[i].first << " " << ans[i].second << "\n";
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
