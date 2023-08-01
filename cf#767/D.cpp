#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
ll mod = 1e9 + 7;
ll mod1 = 998244353;

void solve()
{
    ll n, i, j, k;
    string s, c;

    map<string, pair<string, ll>> mp;
    cin >> n;
    cin.ignore();
    for (i = 0; i < n; i++)
    {
        getline(cin, s);
        string name;
        j = 0;
        while (s[j] != ' ')
        {
            name.push_back(s[j]);
            j++;
        }
        j++;
        if (s[j] == ':')
        {
            string s1;
            ll ans = 0;
            j += 3;
            for (; j < (ll)s.length(); j++)
            {
                s1.push_back(s[j]);
            }
            for (j = 3; j < (ll)s1.length(); j++)
            {
                if (s1[j - 1] == 'h' && s1[j] == 'a' && s1[j - 3] == 'h' && s1[j - 2] == 'a')
                {
                    ans++;
                }
            }
            mp[name] = make_pair(s1, ans);
        }
        else if (s[j] == '=')
        {
            ll xtra = 0;
            string s1, s2;
            j += 2;
            for (; s[j] != ' '; j++)
            {
                s1.push_back(s[j]);
            }
            j += 3;
            while (j < (ll)s.length())
            {
                s2.push_back(s[j]);
                j++;
            }
            if (s1[(ll)s1.length() - 1] == 'h' && s2[0] == 'a')
            {
                xtra = 1;
            }

            mp[name] = make_pair((mp[s1].first + mp[s2].first), ((mp[s1].second) + (mp[s2]).second + xtra));
        }
        c = name;
        name.clear();
    }

    cout << mp[c].second << "\n";
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

// sort(begin(v), end(v), [] (int a, int b) { return a > b; });           (Custom sort using lambda function)