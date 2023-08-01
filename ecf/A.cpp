#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int main()
{
    int n;
    cin >> n;
    vector<int> a(n + 2, 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int thanospower;
    cin >> thanospower;
    int dp[n + 1][n + 1]; // dp[l][r] = max value possible from deleting all elements from substring l to r
    memset(dp, 0, sizeof(dp));
    for (int substrsize = 1; substrsize <= n; substrsize++)
    {
        for (int l = 1; l <= n; l++)
        {
            int r = l + substrsize - 1;
            if (r > n)
                break;
            // finding dp[l][r]
            // dp[l][r] = max( dp[l][pos-1] + dp[pos+1][r] + a[l-1]a[pos]a[r] ) for pos from l to r
            for (int pos = l; pos <= r; pos++)
            {
                // updating dp when pos is the last element deleted in the substring from l to r
                int val = a[l - 1] * a[pos] * a[r + 1];
                if (l <= pos - 1)
                    val += dp[l][pos - 1];
                if (pos + 1 <= r)
                    val += dp[pos + 1][r];
                dp[l][r] = max(dp[l][r], val);
            }
            cout << dp[l][r] << " ";
        }
        cout << "\n";
    }
    cout << dp[1][n] << endl;
    if (dp[1][n] >= thanospower)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}