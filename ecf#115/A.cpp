#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t, n, i, j;
    string s[2];

    cin >> t;
    while (t--)
    {
        cin >> n;
        for (i = 0; i < 2; i++)
        {
            cin >> s[i];
        }
        j = 0;
        for (i = 1; i < n; i++)
        {
            if (s[0][i] == '0' || s[1][i] == '0')
            {
            }
            else
            {
                j = 1;
                break;
            }
        }
        if (j == 1)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}
