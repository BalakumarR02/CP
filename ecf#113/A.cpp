#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t, n, i, l = 0, r = 0;
    string s;

    cin >> t;
    while (t--)
    {
        cin >> n;
        cin >> s;
        l = r = -1;

        for (i = 1; i < n; i++)
        {
            if ((s[i] == 'a' && s[i - 1] == 'b') || (s[i] == 'b' && s[i - 1] == 'a'))
            {
                l = i;
                r = i + 1;
                break;
            }
            else
            {
                l = r = -1;
            }
        }
        cout << l << " " << r << endl;
    }
    return 0;
}
