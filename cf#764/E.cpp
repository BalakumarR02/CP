#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll n, i, m, a[1001][1001], j;
    char c;
    cin >> n >> m;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cin >> c;
            a[i][j] = (ll)(c - '0');
        }
    }
    ll ne[m + 1];
    for (i = 0; i < m; i++)
    {
        cin >> c;
        ne[i] = (ll)(c - '0');
    }
    ll tl[101] = {0}, tr[101] = {0}, thl[1001] = {0}, thr[1001] = {0};
    for (i = 0; i < n; i++)
    {
        for (j = 1; j < m; j++)
        {
            ll num = a[i][j - 1] * 10 + a[i][j];
            tl[num] = i;
            tr[num] = j;
        }
        for (j = 2; j < m; j++)
        {
            ll num = a[i][j - 2] * 100 + a[i][j - 1] * 10 + a[i][j];
            thl[num] = i;
            thr[num] = j;
        }
    }
    // dp
    ll pos[m + 1], lst[m + 1], seg[m + 1], rs[m + 1], ls[m + 1];
    memset(pos, 0, sizeof(pos)), memset(lst, 0, sizeof(lst)), memset(seg, 0, sizeof(seg));
    pos[0] = 1;
    for (i = 1; i < m; i++)
    {
        if (i > 0)
        {
            ll num = ne[i - 1] * 10 + ne[i];
            if (tl[num] && pos[i - 1] == 1)
            {
                pos[i] = 1;
                lst[i] = i - 1;
                seg[i] = tl[num];
                rs[i] = tr[num];
                ls[i] = rs[i] - 1;
                cout << i << "  ";
            }
        }
        if (i > 1)
        {
            ll num = ne[i - 2] * 100 + ne[i - 1] * 10 + ne[i];
            if (thl[num] && pos[i - 2] == 1)
            {
                pos[i] = 1;
                lst[i] = i - 2;
                seg[i] = thl[num];
                rs[i] = thr[num];
                ls[i] = rs[i] - 2;
                cout << i << "  ";
            }
        }
    }
    if (pos[m - 1] == 0)
    {
        cout << -1 << "\n";
        return;
    }
    ll curr = m;
    vector<tuple<ll, ll, ll>> ans;
    while (curr)
    {
        ans.push_back({ls[i], rs[i], seg[i]});
        curr = lst[curr];
    }
    for (auto x = ans.begin(); x != ans.end(); x++)
    {
        cout << get<0>((*x)) + 1 << " " << get<1>((*x)) + 1 << " " << get<2>((*x)) + 1 << "\n";
    }
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
