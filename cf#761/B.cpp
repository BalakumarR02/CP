#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll mod = 1e9 + 7;

void solve()
{
    ll n, i, x, y, prime[] = {3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

    cin >> n;

    if (n % 2 != 0)
    {
        n--;
        for (i = 0; i < 10; i++)
            if ((__gcd((n - prime[i]), prime[i])) == 1)
            {
                break;
            }
        x = prime[i];
        y = n - x;
    }
    else
    {
        x = n / 2;
        y = x - 1;
    }
    cout << x << " " << y << " " << 1 << '\n';
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
