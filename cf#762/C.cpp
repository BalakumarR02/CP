#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll mod = 1e9 + 7;

void solve()
{
    ll n, i, j, m;
    string a, b, s;
    cin >> a >> s;
    n = a.length();
    reverse(a.begin(), a.end());
    reverse(s.begin(), s.end());
    for (i = 0, j = 0; i < n; i++)
    {
        if (j >= s.length())
        {
            cout << -1 << "\n";
            return;
        }
        if ((s[j] - '0') < (a[i] - '0'))
        {
            if (s[j + 1] != '1')
            {
                cout << -1 << "\n";
                return;
            }
            m = 10 * (s[j + 1] - '0') + (s[j] - '0');
            m -= (a[i] - '0');
            j += 2;
        }
        else
        {
            m = (s[j] - '0') - (a[i] - '0');
            j++;
        }
        if (m > 9)
        {

            while (m)
            {
                b.push_back('0' + (m % 10));
                m /= 10;
            }
        }
        else
            b.push_back('0' + m);
    }
    while (j < s.length())
    {
        m = (s[j] - '0');
        b.push_back('0' + m);
        j++;
    }
    reverse(b.begin(), b.end());
    n = 0;
    for (i = 0; i < b.length(); i++)
    {
        if (b[i] == '0' && n == 0)
        {
            continue;
        }
        else
        {
            n = 1;
        }
        cout << b[i];
    }
    cout << "\n";
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
