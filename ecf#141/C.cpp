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
    ll n, i, m, mini = 1e9 + 7, ind = -1;

    cin >> n >> m;
    vll v(n + 1, 0), pre(n + 1, 0);
    ll count = 0;

    fo(i, 1, n)
    {
        ll x;
        cin >> x;
        v[i] = x;
        pre[i] = pre[i - 1] + v[i];
        if (mini > pre[i])
        {
            mini = pre[i];
            ind = i;
        }
    }
    if (v[m] > 0)
    {
        v[m] *= -1;
        pre[m] += (2 * v[m]);
        count++;
    }
    fo(i, 1, n)
    {
        pre[i] = pre[i - 1] + v[i];
    }
    if (m == ind)
    {
        cout << "0\n";
        return;
    }
    else if (m < ind)
    {
        set<ll> sm;
        fo(i, m + 1, ind)
        {
            if (v[i] < 0)
                sm.insert(v[i]);
        }
        while (pre[m] > mini)
        {
        }
        mini = 1e9 + 7, ind = -1;
        fo(i, 1, m)
        {
            if (mini > pre[i])
            {
                mini = pre[i];
                ind = i;
            }
        }
        set<ll, greater<ll>> st;
        fo(i, ind, m)
        {
            if (v[i] > 0)
                st.insert(v[i]);
        }
        while (pre[m] > mini)
        {
            auto itr = st.begin();
            ll val = *itr;
            st.erase(itr);
            pre[m] -= (2 * val);
            count++;
        }
    }
    else
    {
        set<ll, greater<ll>> st;
        fo(i, ind, m)
        {
            if (v[i] > 0)
                st.insert(v[i]);
        }
        while (pre[m] > mini)
        {
            auto itr = st.begin();
            ll val = *itr;
            st.erase(itr);
            pre[m] -= (2 * val);
            count++;
        }
        mini = 1e9 + 7, ind = -1;
        fo(i, 1, m)
        {
            if (mini > pre[i])
            {
                mini = pre[i];
                ind = i;
            }
        }
        fo(i, m + 1, ind)
        {
            pre[i] = pre[i - 1] + v[i];
            if (pre[i] < pre[m])
            {
                v[i] *= -1;
                pre[i] += (2 * v[i]);
                count++;
            }
        }
    }

    cout << count << "\n";
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
