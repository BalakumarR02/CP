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
    ll n, i, c, d, ans = 0;

    cin >> n >> c >> d;
    vector<ll> v(n + 1, 0), rem(n + 1, 0), add(n + 1, 0);
    map<ll, ll> mp;
    fo(i, 1, n)
    {
        cin >> v[i];
        mp[v[i]]++;
    }
    vector<ll> nv;
    if (!mp[1])
    {
        nv.pb(1);
        ans += d;
    }
    fo(i, 1, n)
    {
        if (mp[v[i]] == 1)
        {
            nv.pb(v[i]);
        }
        else
        {
            mp[v[i]]--;
            ans += c;
        }
    }
    sort(all(nv));
    ll si = nv.size();
    ll las = nv[si - 1];
    // cout << ans << "  ";
    for (i = si - 2; i >= 0; i--)
    {
        rem[i] = rem[i + 1];
        add[i] = add[i + 1];
        if (nv[i] != (las - 1))
        {
            ll dif = las - nv[i] - 1;
            add[i] = min(add[i + 1] + (dif * d), rem[i + 1] + (dif * d));
            rem[i] = ((si - i - 1) * c);
            // cout << rem[i] << "  << add[i] << "  ";
        }
        las = nv[i];
    }

    cout << ans + min(rem[0], add[0]) << "\n";
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
