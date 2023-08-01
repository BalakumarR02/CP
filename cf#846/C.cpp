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
    ll n, i, m;

    cin >> n >> m;
    multiset<ll, greater<ll>> st;
    map<ll, ll> mp;
    vector<ll> v;
    fo(i, 1, n)
    {
        ll x;
        cin >> x;
        mp[x]++;
    }
    fo(i, 1, m)
    {
        ll x;
        cin >> x;
        v.pb(x);
    }
    sort(all(v));
    reverse(all(v));
    fo(i, 1, n)
    {
        if (mp[i])
        {
            st.insert(mp[i]);
        }
    }
    ll ans = 0;
    i = 0;
    // while (!st.empty() && i < m)
    // {
    //     ll fir = 0;
    //     while (v[i] && !st.empty())
    //     {
    //         auto itr = st.begin();
    //         ll val = *itr;
    //         if (v[i] >= val)
    //         {
    //             v[i] -= val;
    //             if (!fir)
    //             {
    //                 ans += (val);
    //                 fir++;
    //             }
    //             val -= v[i];
    //             st.erase(itr);
    //             break;
    //         }
    //         else
    //         {
    //             if (!fir)
    //             {
    //                 ans += (v[i]);
    //                 fir++;
    //             }
    //             val -= v[i];

    //             v[i] = 0;
    //         }

    //         st.erase(itr);
    //         if (val > 0)
    //             st.insert(val);
    //     }
    //     i++;
    // }
    for (i = 0; i < m && !st.empty(); i++)
    {
        auto itr = st.begin();
        ll val = *itr;
        if (v[i] < val)
        {
            val -= v[i];
            ans += (v[i]);
            st.insert(val);
        }
        else
        {
            ans += val;
        }
        st.erase(itr);
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
