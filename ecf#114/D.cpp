#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = a; i <= b; i++)

using namespace std;
using ll = long long;

void solve()
{
    ll n, i, a, b, ans;
    vector<pair<ll, ll>> p;
    map<ll, ll> m, m1;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        p.push_back(make_pair(a, b));
    }
    sort(p.begin(), p.end());
    for (auto c = p.begin() + 1; c != p.end(); c++)
    {
        if ((*c).first == (*(c - 1)).first)
        {
            m[(*c).first]++;
        }
        if ((*c).second == (*(c - 1)).second)
        {
            m1[(*c).second]++;
        }
    }
    ans = (n * (n - 1) * (n - 2)) / 6;
    if (m.empty() || m1.empty())
    {
        cout << ans << endl;
        return;
    }
    for (auto c = m.begin(); c != m.end(); c++)
    {
        auto l = lower_bound(p.begin(), p.end(), c->first);
        auto l1 = upper_bound(p.begin(), p.end(), c->first) - 1;
        cout << (*l).first << " " << (*l).second << " ";
        while (l != l1)
        {
            for (auto c1 = m1.begin(); c1 != m1.end(); c1++)
            {

                if ((*l).second == c1->first)
                {
                    ans--;
                }
            }
            l++;
        }
    }
    ans++;
    cout << ans << endl;
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
