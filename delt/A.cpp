#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    ll n, i, sum = 0, mul = 0, a[16];

    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] % 16 == 0)
        {
            a[i] = 1;
            mul += 4;
        }
        else if (a[i] % 8 == 0)
        {
            a[i] = 1;
            mul += 3;
        }
        else if (a[i] % 4 == 0)
        {
            mul += 2;
            a[i] /= 4;
        }
        else if (a[i] % 2 == 0)
        {
            a[i] /= 2;
            mul += 1;
        }
    }
    sort(a, a + n);
    sum = pow(2, mul) * a[n - 1];
    for (i = 0; i < n - 1; i++)
    {
        sum += a[i];
    }
    cout << sum << endl;
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
