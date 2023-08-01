#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    ll n, m, i, x = 0, y = 0, xmin = 0, xmax = 0, ymin = 0, ymax = 0;
    string s;
    cin >> n >> m;
    cin >> s;
    for (i = 0; i < s.length(); i++)
    {
        if (s[i] == 'R')
        {
            y++;
            ymax = max(ymax, y);
        }
        else if (s[i] == 'L')
        {
            y--;
            ymin = min(ymin, y);
        }
        else if (s[i] == 'D')
        {
            x++;
            xmax = max(xmax, x);
        }
        else if (s[i] == 'U')
        {
            x--;
            xmin = min(xmin, x);
        }
        if (ymax - ymin >= m)
        {
            if (y == (ymin))
            {
                ymin++;
            }

            break;
        }
        if (xmax - xmin >= n)
        {
            if (x == (xmin))
            {
                xmin++;
            }

            break;
        }
    }
    x = (1 - xmin);
    y = (1 - ymin);
    cout << x << " " << y << endl;
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
