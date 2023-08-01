#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    ll n, i = 0, k, m = 1;

    cin >> n >> k;
    n--;
    while (n > 0 && m < k)
    {
        n -= m;
        m *= 2;
        i++;
    }
    if (n <= 0)
    {
        cout << i << endl;
        return;
    }
    i += (n / k);
    if (n % k != 0)
    {
        i++;
    }

    cout << i << endl;
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
