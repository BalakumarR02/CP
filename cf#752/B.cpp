#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    ll n, i, a[100001], c = 0;

    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if (n % 2 == 0)
    {
        cout << "YES" << endl;
        return;
    }
    for (i = 1; i < n; i++)
    {
        if (a[i - 1] >= a[i])
        {
            c = 1;
            break;
        }
    }
    if (c)
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
