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
    ll n, i, j;

    cin >> n;
    vector<ll> a(n + 1, 0), b(n + 1, 0);
    vector<pll> c(n + 1);
    fo(i, 1, n)
    {
        ll x;
        cin >> x;
        a[x] = i;
    }

    fo(i, 1, n)
    {
        ll x;
        cin >> x;
        b[i] = a[x];
    }

    reverse(b.begin() + 1, b.end());
    vector<ll> v;
    fo(i, 1, n)
    {
        auto itr = lower_bound(all(v), b[i]);
        if (itr == v.end())
        {
            v.push_back(b[i]);
        }
        else
        {
            v[(itr - v.begin())] = b[i];
        }
    }
    cout << v.size();
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}

// sort(begin(v), end(v), [] (int a, int b) { return a > b; });           (Custom sort using lambda function)