#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    ll n, i, a[200001], j = 0;
    string s;
    vector<pair<ll, char>> p;
    cin >> n;
    ll b[n + 1];
    for (i = 0; i < n; i++)
    {
        cin >> a[i];

        b[i] = 0;
    }
    cin >> s;
    for (i = 0; i < n; i++)
    {
        p.push_back(make_pair(a[i], s[i]));
    }
    sort(p.begin(), p.end());
    for (i = 0; i < n; i++)
    {
        if (p[i].second == 'B')
        {
            if (p[i].first >= (j + 1))
            {
                j++;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        if (p[i].second == 'R')
        {
            if (p[i].first <= (j + 1))
            {
                j++;
            }
        }
    }
    if (j == n)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
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
