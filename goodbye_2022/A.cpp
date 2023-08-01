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

bool cmp(pair<ll, ll> &a, pair<ll, ll> &b)
{
    return a.second > b.second;
}
void solve()
{
    ll n, i;

    cin >> n;
    set<pll> st;
    map<ll, ll> mp;
    fo(i, 1, n)
    {
        ll x;
        cin >> x;
        mp[x]++;
    }
    for (auto it : mp)
    {
        st.insert({-it.second, it.first});
    }
    vector<vector<ll>> v;
    while (st.size() > 2)
    {
        pii a = *st.begin();
        st.erase(st.begin());
        pii b = *st.begin();
        st.erase(st.begin());
        pii c = *st.begin();
        st.erase(st.begin());
        vector<ll> t;
        t.push_back(a.second);
        t.push_back(b.second);
        t.push_back(c.second);
        sort(t.rbegin(), t.rend());
        v.push_back(t);
        if (a.first != -1)
        {
            a.first++;
            st.insert(a);
        }
        if (b.first != -1)
        {
            b.first++, st.insert(b);
        }
        if (c.first != -1)
        {
            c.first++, st.insert(c);
        }
    }
    ll m = v.size();
    cout << m << "\n";
    fo(i, 0, m - 1)
    {
        cout << v[i][0] << " " << v[i][1] << " " << v[i][2] << "\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}

// sort(begin(v), end(v), [] (int a, int b) { return a > b; });           (Custom sort using lambda function)
