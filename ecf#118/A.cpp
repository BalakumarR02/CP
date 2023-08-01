#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    ll x1, x2, p1, p2, i, n1 = 0, n2 = 0;

    cin >> x1 >> p1;
    cin >> x2 >> p2;

    n1 = log10(x1) + 1;
    n2 = log10(x2) + 1;

    if ((n1 + p1) > (n2 + p2))
    {

        cout << ">" << endl;
    }
    else if ((n1 + p1) < (n2 + p2))
    {
        cout << "<" << endl;
    }
    else if ((n1 + p1) == (n2 + p2))
    {
        if (n1 > n2)
        {
            x2 *= pow(10, (n1 - n2));
        }
        else
        {
            x1 *= pow(10, (n2 - n1));
        }
        if (x1 > x2)
        {
            cout << ">" << endl;
        }
        else if (x1 < x2)
        {
            cout << "<" << endl;
        }
        else
        {
            cout << "=" << endl;
        }
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
