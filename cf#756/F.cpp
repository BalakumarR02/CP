#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    ll n, i, j, s, a[200001], m1 = -1, m2 = 0, ans = 0, pos[2], p = 0;

    cin >> n >> s;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (i = 0, j = 0; i < n; i++)
    {
        m2 += a[i];
        p++;
        if (a[i] < 0 && (s + m2) <= 0)
        {
            m1 = i;
        }
        if ((s + m2) < 0)
        {
            if ((p - 1) > ans)
            {
                ans = p - 1;
                pos[0] = j + 1;
                pos[1] = i;
            }

            m2 = 0;
            p = 0;
            if (m1 == -1)
            {
                j = i + 1;
                continue;
            }
            j = m1 + 1;
            i = m1;
            m1 = -1;
        }
    }

    if ((p - 1) > ans)
    {
        ans = p - 1;
        pos[0] = j + 1;
        pos[1] = i;
    }
    if (ans == 0)
    {
        cout << -1 << endl;
        return;
    }
    cout << pos[0] << " " << pos[1] << endl;
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
