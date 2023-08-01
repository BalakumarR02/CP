#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    ll n, i, a[200001], num;

    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    num = n / 2;

    for (i = 1; i < n; i++)
    {
        if (!num)
            break;

        cout << a[i] << " " << a[0] << endl;
        num--;
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
