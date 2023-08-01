#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define lb lower_bound
#define ub upper_bound
#define fo(i, a, b) for (i = a; i <= b; i++)
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

void solve()
{
    ll n, i, p;

    cin >> n >> p;
    vll v(n + 2, 0), in;
    fo(i, 1, n)
    {
        ll x;
        cin >> x;
        v[i] = x;
        if (x == 1)
            in.pb(i);
    }
    v[n + 1] = 1e9;
    ll k = p - 3;
    set<ll> st;
    // if (in.empty())
    // {
    //     cout << "0\n";
    //     return;
    // }
    ll j = 1;
    map<ll, ll> mp;
    ll ans = 0;
    fo(i, 1, n)
    {
        while (j <= (n + 1) && sz(st) <= (p - 2))
        {
            st.insert(v[j]);
            mp[v[j]]++;
            // cout << v[j] << " ";
            j++;
        }
        if (sz(st) == (p - 1))
        {
            ll num = ub(all(in), j - 2) - lb(all(in), i);
            if (num > 0)
            {
                ans = max(ans, j - i - 1);
            }
        }

        mp[v[i]]--;
        if (mp[v[i]] == 0)
            st.erase(v[i]);
    }
    cout << ans << "\n";
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
