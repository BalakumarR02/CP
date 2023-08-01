#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t, n, i, j, two = 0, temp, k;
    string s;
    vector<ll> v;

    cin >> t;
    while (t--)
    {
        two = 0;
        cin >> n;
        cin >> s;
        for (i = 0; i < n; i++)
        {
            if (s[i] == '2')
            {
                two++;
                v.push_back(i);
            }
        }

        if (two >= 3 || two == 0)
        {
            if (two != 0)
            {
                temp = v[0];
                for (i = 1; i < two; i++)
                {
                    v[i - 1] = v[i];
                }
                v[i - 1] = temp;

                temp = 0;
                k = v[two - 2];
            }

            cout << "YES" << endl;
            for (i = 0; i < n; i++)
            {

                for (j = 0; j < n; j++)
                {
                    if (i == j)
                    {
                        cout << 'X';
                    }
                    else if (s[i] == '1' || s[j] == '1')
                    {
                        cout << '=';
                    }
                    else if (j == k)
                    {
                        cout << '-';
                    }
                    else if (v[temp] == j)
                    {
                        cout << '+';
                    }

                    else
                    {
                        cout << '=';
                    }
                }
                if (s[i] == '2')
                {
                    temp++;
                    k = i;
                }
                cout << endl;
            }
        }
        else
        {
            cout << "NO" << endl;
        }
        v.clear();
    }
    return 0;
}
