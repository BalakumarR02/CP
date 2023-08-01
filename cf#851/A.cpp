#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define ll long long
#define ld long double
#define mod 1000000007
// #define mod 998244353
#define INF (ll)1e18
#define endl '\n'
#define pii pair<int, int>
#define vi vector<int>
#define vb vector<bool>
#define vc vector<char>
#define vpii vector<pii>
#define vvi vector<vi>
#define vvc vector<vc>
#define fo(i, a, b) for (int i = a; i < b; i++)
#define rfo(i, b, a) for (int i = b; i >= a; i--)
#define foi(i, a, b, d) for (int i = a; i < b; i += d)
#define fod(i, b, a, d) for (int i = b; i >= a; i -= d)
#define afo(it, v) for (auto it : v)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sort_second(all_v) sort(all_v, [](pii &a, pii &b) { return a.second < b.second; })
#define ya                     \
    {                          \
        cout << "YES" << endl; \
        return;                \
    }
#define na                    \
    {                         \
        cout << "NO" << endl; \
        return;               \
    }
#define ret(x)   \
    {            \
        show(x); \
        return;  \
    }
#ifndef ONLINE_JUDGE
#define dbg(x)          \
    cerr << #x << ": "; \
    _print(x);          \
    cerr << endl;
#else
#define dbg(x)
#endif
template <class T>
void _print(T t)
{
    cerr << t;
}
template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.first);
    cerr << ",";
    _print(p.second);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(queue<T> v)
{
    cerr << "[ ";
    while (!v.empty())
    {
        _print(v.front());
        cerr << " ";
        v.pop();
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(multimap<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void read(T &x) { cin >> x; }
template <class T>
void read(vector<T> &v)
{
    for (auto &i : v)
        read(i);
}
template <class T>
void write(T t) { cout << t << ' '; }
template <class T>
void show(T t) { cout << t << endl; }
template <class T>
void show(vector<T> v)
{
    for (auto i : v)
        cout << i << ' ';
    cout << endl;
}
template <class T>
void show(vector<vector<T>> v)
{
    for (auto row : v)
    {
        for (auto it : row)
            cout << it << ' ';
        cout << endl;
    }
}
template <class T, class... V>
void read(T &h, V &...t)
{
    read(h);
    read(t...);
}
template <class T, class... V>
void write(T h, V... t)
{
    write(h);
    write(t...);
}
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order (kth element in set), order_of_key (# ele < k) ; less_equal, greater, greater_equal

/**********CODE BEGINS HERE**********/

void solve()
{
    int n;
    read(n);

    vi v(n);
    read(v);
    int ans = 0;
    fo(i, 0, n)
    {
        st.insert(v[i]);
        fo(j, i + 1, n)
        {
            st.insert(v[j]);
            ans += (*st.begin() ^ (*(++st.begin())));
        }
    }

    ret(ans)
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}