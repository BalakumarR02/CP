#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    ll n, i, c1 = 0, j, c0 = 0;
    string s;
    vector<ll> v;
    cin >> n;
    cin >> s;
    for (i = 0; i < n; i++)
    {
        if (c1 && s[i] == '0')
        {
            c0++;
        }
        if (s[i] == '1')
        {
            c1++;
        }
    }
    if (!c0)
    {
        cout << 0 << endl;
        return;
    }
    for (i = 0, j = n - 1; i < n; i++)
    {
        if (i >= j)
            break;
        if (s[i] == '1')
        {
            v.push_back(i + 1);
            for (; j > i; j--)
            {

                if (s[j] == '0')
                {
                    v.push_back(j + 1);
                    j--;
                    break;
                }
            }
        }
    }

    sort(v.begin(), v.end());
    cout << 1 << endl;
    cout << v.size() << " ";
    for (i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
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
