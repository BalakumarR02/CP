#include <bits/stdc++.h>

using namespace std;
using ll = long long;
bool prime[1000002];
void solve()
{
    ll n, i, e, a[200002], pair = 0, j, k = 0, m = 0;

    cin >> n >> e;
    for (i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    for (i = 1; i <= n; i++)
    {
        if (prime[a[i]])
        {
            k = m = 0;
            for (j = i + e; j <= n; j += e)
            {
                if (a[j] == 1)
                {
                    m++;
                }
                else
                {
                    break;
                }
            }
            for (j = i - e; j >= 1; j -= e)
            {
                if (a[j] == 1)
                {
                    k++;
                }
                else
                {

                    break;
                }
            }
            pair += (k * (m + 1)) + m;
        }
    }
    cout << pair << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(prime, true, sizeof(prime));

    ll n = 1000000;
    for (int p = 2; p * p <= n; p++)
    {

        if (prime[p] == true)
        {

            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    prime[1] = false;
    ll t;

    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
