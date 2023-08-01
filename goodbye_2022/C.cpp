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
    ll n, i, ev = 0, od = 0;

    cin >> n;
    vector<ll> v;
    map<ll, ll> mp;
    for (i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        v.pb(x);
        if (x % 2)
            od++;
        else
            ev++;
        mp[x]++;
    }
    if (od >= 2 && ev >= 2)
    {
        cout << "NO\n";
        return;
    }
    ll ch = 0;
    for (i = 0; i < n; i++)
    {
        if (mp[v[i]] >= 2)
        {
            cout << "NO\n";
            return;
        }
        if (ev >= 2)
        {
            v[i] += 1;
            ch = 1;
        }
    }
    string ans = "NO";
    for (ll tot = 0; tot <= 101; tot++)
    {
        if (ch)
        {
            ll on = 0;
            for (i = 0; i < n; i++)
            {
                for (ll j = i + 1; j < n; j++)
                {
                    if (__gcd(v[i], v[j]) != 1)
                    {
                        on = 1;
                        break;
                    }
                }
                if (on)
                    break;
            }
            if (!on)
            {
                ans = "YES";
                break;
            }
        }
        ch = 0;
        for (i = 0; i < n; i++)
        {
            v[i] += 2;
            ch = 1;
        }
    }

    cout << ans << "\n";
    cout << "YES\n";
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
