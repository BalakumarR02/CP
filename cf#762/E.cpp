#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll mod = 1e9 + 7;

void solve()
{
    ll n, i, a[200001], j = -1, c = 0, f = 0, m = -1;

    cin >> n;
    ll h[n + 1];
    vector<pair<ll, ll>> p;
    memset(h, 0, sizeof(h));
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        h[a[i]]++;
        m = max(m, a[i]);
    }

    for (i = 0; i <= n; i++)
    {
        if (h[i] == 0)
        {
            cout << 0 + c << " ";

            if (p.size())
            {
                f = 1;
                p[j].first--;
                c += (i - p[j].second);
                if (p[j].first == 1)
                {
                    if (p.size() == 1)
                    {
                        p.clear();
                    }
                    else
                    {
                        p.erase(p.begin() + j);
                    }

                    j--;
                }
            }
            if (f == 1)
            {
                f = 0;
            }
            else
            {
                break;
            }
        }
        else
        {

            cout << h[i] + c << " ";
            if (h[i] > 1)
            {
                p.push_back(make_pair(h[i], i));
                j++;
            }
        }
    }
    for (i = i + 1; i <= n; i++)
    {
        cout << -1 << " ";
    }
    cout << "\n";
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
