#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

vector<ll> query(ll l, ll r)
{
    cout << "? " << l << " " << r << endl;
    vector<ll> q;
    ll n = r - l + 1, i;
    for (i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        q.push_back(x);
    }
    return q;
}
void answe(ll x)
{
    cout << "! " << x << endl;

    return;
}
void solve()
{
    ll n, i;

    cin >> n;
    ll l = 1, r = n;
    while (l < r)
    {
        ll mid = (l + r) / 2;
        vector<ll> lh;
        lh = query(l, mid);
        ll c = 0;
        for (i = 0; i < (ll)lh.size(); i++)
        {
            if (lh[i] >= l && lh[i] <= mid)
                c++;
        }
        if (c % 2)
        {
            r = mid;
        }
        else
            l = mid + 1;
    }

    answe(l);
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
