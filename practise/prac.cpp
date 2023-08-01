#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// int equalTo(ll b[], ll a[], ll n)
// {
//     ll i = 0;
//     for (i = 0; i < n; i++)
//     {
//         if (b[i] != a[i])
//         {
//             return 0;
//         }
//     }
//     return 1;
// }
// int main()
// {

//     ll t, n, i, a[1001], b[1001], flag = 0, ans = 0;

//     cin >> t;
//     while (t--)
//     {
//         flag = 0, ans = 0;
//         cin >> n;
//         cout << "hi1";
//         for (i = 0; i < n; i++)
//         {
//             cin >> a[i];
//             b[i] = a[i];
//         }
//         sort(b, b + n);

//         flag = equalTo(b, a, n);
//         while (!flag)
//         {
//             if ((ans + 1) % 2 != 0)
//                 i = 0;
//             else
//                 i = 1;
//             for (; i < n; i += 2)
//             {
//                 if (a[i] > a[i + 1])
//                 {
//                     swap(a[i], a[i + 1]);
//                 }
//             }
//             ans++;
//             flag = equalTo(b, a, n);
//         }
//         cout << ans;
//     }
//     return 0;
// }
#define PI 3.14159265

int main()
{
    double x, y = 0, r2 = (75 * 75) / (4 * PI * PI), w[6], ans;

    while (y <= 15)
    {
        ans = 0.1 + (3 * y * 0.1) / (r2 + (y * y));
        cout << ans << endl;
        y += 3;
    }
    return 0;
}