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

struct tar
{
    ll t;
    ll x;
    ll y;
    ll s;
};
bool cmp(tar a, tar b)
{
    return (a.t < b.t);
}
void solve()
{
    ll n, i;

    cin >> n;
    vector<tar> v;
    for (i = 0; i < n; i++)
    {
        ll x, y, w, z;
        cin >> x >> y >> w >> z;
        v.push_back({w, x, y, z});
    }
    sort(v.begin(), v.end(), cmp);
    set<tar> comp;
    ll ans = 0;
    map<ll, ll> mp;
    for (i = 0; i < n; i++)
    {
        mp[v[i].t] = v[i].s;
        for (ll j = 0; j < i; j++)
        {
            ll tim = (abs(v[j].x - v[i].x) + abs(v[j].y - v[i].y)) - (v[i].t - v[j].t);
            if (tim <= 0)
            {
                mp[v[i].t] = max(mp[v[i].t], (mp[v[j].t] + v[i].s));
            }
        }
        ans = max(ans, mp[v[i].t]);
    }
    cout << ans << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}

// sort(begin(v), end(v), [] (int a, int b) { return a > b; });           (Custom sort using lambda function)
