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
    ll n, i, a[5] = {0};

    fo(i, 1, 4)
    {
        cin >> a[i];
    }
    if (a[1] == 0)
    {
        cout << 1 << "\n";
        return;
    }
    ll ans = a[1], m1, m2;
    if (a[2] > a[3])
        swap(a[2], a[3]);

    ans += a[2];
    m1 = a[2] % a[1];

    m2 = a[3] % a[1];

    ll n1 = a[2] / a[1] - (m1 == 0 && a[2]), n2 = a[3] / a[1] - (m2 == 0 && a[2]);
    if (!m1 && a[2])
        m1 = a[1];
    if (!m2 && a[3])
        m2 = a[1];
    if (n2 > n1)
    {
        ans += a[2] + m1;
        a[4] += (n2 - n1) * a[1];
        if (m2 < a[1])
            a[4] += m2;
    }
    else
    {
        ans += n2 * a[1] + m2;
    }
    ans += min(a[4], (a[1] + m1 - m2 + 1));
    cout
        << ans << "\n";
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
