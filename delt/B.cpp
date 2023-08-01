#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    ll n, i, q, pos, count = 0, m, j, l, k;
    string s;
    char c;
    cin >> n >> q;
    cin >> s;

    for (i = 2; i < n; i++)
    {

        if (s[i] == 'c' && s[i - 1] == 'b' && s[i - 2] == 'a')
        {
            count++;
        }
    }
    while (q--)
    {
        cin >> pos >> c;
        if (s[pos - 1] != c)
        {
            j = max((ll)0, (pos - 3));
            m = min((n - 1), (pos + 1));
            l = 0;
            for (i = j + 2; i <= m; i++)
            {
                if (s[i] == 'c' && s[i - 1] == 'b' && s[i - 2] == 'a')
                {
                    l++;
                }
            }
            s[pos - 1] = c;
            k = 0;
            for (i = j + 2; i <= m; i++)
            {
                if (s[i] == 'c' && s[i - 1] == 'b' && s[i - 2] == 'a')
                {
                    k++;
                }
            }
            count += (k - l);
        }

        cout << count << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;

    solve();

    return 0;
}
