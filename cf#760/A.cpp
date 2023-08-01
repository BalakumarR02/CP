#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll mod = 1e9 + 7;

void solve()
{
    ll n, i, b[7], t;

    for (i = 0; i < 7; i++)
    {
        cin >> b[i];
    }
    t = 3;
    if (b[t] == (b[4] - b[0]))
    {
        t--;
    }
    cout << b[0] << " " << (b[4] - b[0]) << " " << (b[t] - b[0]) << endl;
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
