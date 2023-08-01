#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll m, n, i, h[200001], x, y, a1, a2, ans1, ans2, ans;

    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    sort(h, h + n);
    cin >> m;
    a2 = 0;
    for (i = 0; i < n; i++)
    {
        a2 += h[i];
    }
    while (m--)
    {
        cin >> x >> y;

        if (x <= h[0])
        {
            a1 = 0;
        }
        else if (x >= h[n - 1])
        {
            a1 = n - 1;
        }
        else
        {
            a1 = (upper_bound(h, h + n, x) - h) - 1;
        }

        ans = 0;

        if (y <= (a2 - h[a1]))
            ans += 0;
        else
        {
            ans += (y - (a2 - h[a1]));
        }
        if (x <= h[a1])
            ans += 0;
        else
        {
            ans += (x - h[a1]);
        }
        ans1 = 0;
        if (a1 != (n - 1))
        {
            if (y <= (a2 - h[a1 + 1]))
                ans1 += 0;
            else
            {
                ans1 += (y - (a2 - h[a1 + 1]));
            }
            if (x <= h[a1 + 1])
                ans1 += 0;
            else
            {
                ans1 += (x - h[a1 + 1]);
            }
            ans = min(ans, ans1);
        }
        cout << ans << "\n";
    }
    return 0;
}
