#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t, n, i, ans;

    cin >> t;
    while (t--)
    {
        cin >> n;

        if (n < 6)
            ans = 15;
        else if (n % 6 == 0 || n % 8 == 0 || n % 10 == 0)
            ans = (n / 2) * 5;
        else
        {
            i = ((n / 6) - 1);

            if ((n - i * 6) <= 8 && (n - (i * 6)) > 6)
            {
                ans = (i * 15) + 20;
            }

            else if ((n - (i * 6)) <= 10 && (n - (i * 6)) > 8)
            {
                ans = (i * 15) + 25;
            }
            else if ((n - (i * 6)) <= 11 && (n - (i * 6)) > 10)
            {
                ans = (i * 15) + 30;
            }
        }

        cout << ans << endl;
    }
    return 0;
}
