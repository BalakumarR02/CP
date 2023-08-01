#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    ll n, i, j, c = 0, m;
    vector<ll> v;

    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> m;
        v.push_back(m);
    }
    c = 0;

    for (i = n - 1; i >= 0; i--)
    {
        if (v[i] % (i + 2) != 0)
        {
            v.erase(v.begin() + i);

            for (j = c - 1; j >= 0; j--)
            {
                if (v[j + i] % (j + i + 2) != 0)
                {
                    v.erase(v.begin() + j + i);
                    c--;
                }
            }
        }
        else
        {
            c++;
        }
    }

    if (!c)
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
