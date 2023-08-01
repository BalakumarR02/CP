#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define lb lower_bound
#define ub upper_bound
#define all(v) (v).begin(), (v).end()
#define all1(v) (v).begin() + 1, (v).end()
#define allr(v) (v).rbegin(), (v).rend()
#define allr1(v) (v).rbegin() + 1, (v).rend()
#define sort0(v) sort(all(v))
#define fo(i, a, b) for (i = a; i <= b; i++)
#define fi(i, a, b) for (i = a; i >= b; i--)

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;

#define sz(x) (ll) x.size()
#define pb push_back
#define ppb pop_back
#define mkp make_pair
#define inf 1000000000000000005

const ll mod = 1e9 + 7;
const ll mod1 = 998244353;
const ll N = 1e5; // limit for array size

void solve()
{
    ll n, i, q, j;

    cin >> n >> q;
    multiset<pair<ll, pll>> a;
    vector<vector<ll>> b(q + 1, vector<ll>(2));
    ll totmons = 0;
    fo(i, 1, n)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        a.insert(make_pair(z, make_pair(y, x)));
        // a[i].first = z;
        // a[i].second.first = x;
        // a[i].second.second = y;

        totmons += (y - x + 1);
    }
    // cout << totmons << " ";
    fo(i, 1, q)
    {
        fo(j, 0, 1)
        {
            cin >> b[i][j];
        }
        auto ub2 = a.upper_bound(make_pair(b[i][1], make_pair(b[i][0], b[i][0]))), lb2 = a.lower_bound(make_pair(0LL, make_pair(b[i][0], 0LL)));
        // ll ub1 = upper_bound(a.begin(), a.end(), make_pair(b[i][1], make_pair(b[i][0], b[i][0]))) - a.begin(), lb1 = lower_bound(a.begin(), a.end(), make_pair(0LL, make_pair(0LL, b[i][0]))) - a.begin();

        for (auto k = lb2; k != ub2;)
        {
            if ((*k).second.first >= b[i][0] && (*k).second.second <= b[i][0])
            {
                pair<ll, pll> x, y;
                totmons -= 1;
                auto itr = k;
                if (b[i][0] != (*k).second.first)
                    x = (make_pair((*k).first, make_pair((*k).second.first, b[i][0] + 1)));
                if (b[i][0] != (*k).second.second)
                    y = (make_pair((*k).first, make_pair(b[i][0] - 1, (*k).second.second)));
                a.erase(itr);
            }
            k++;
        }
        cout << (*ub2).second.first << " " << (*lb2).second.first << " " << totmons << " ";
    }

    cout << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}

// sort(begin(v), end(v), [] (int a, int b) { return a > b; });           (Custom sort using lambda function)

// 3 2
// 1 3 7
// 2 5 4
// 4 8 6
// 3 5
// 5 8