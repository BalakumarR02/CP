#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t, n, i, a, b, c, m, flag, pair;

    cin >> t;
    while (t--)
    {

        cin >> a >> b >> c >> m;
        n = max(a, max(b, c));
        pair = (a - 1) + (b - 1) + (c - 1);
        if (n == a)
        {
            flag = (a - 1) - (b + c);
        }
        else if (n == b)
        {
            flag = (b - 1) - (a + c);
        }
        else
        {
            flag = (c - 1) - (b + a);
        }
        if (m <= pair && m >= flag)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
