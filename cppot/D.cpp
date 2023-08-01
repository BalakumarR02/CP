#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int ans = 0, i;
        vector<int> arr(n), dup(n);
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            mp[arr[i]] = i;
            dup[i] = arr[i];
        }
        sort(dup.begin(), dup.end());
        for (i = n - 1; i >= 0; i--)
        {
            if (arr[i] == dup[i])
            {
                ans++;
                continue;
            }
            auto it = find(dup.begin(), dup.end(), arr[i]);
            int pos = it - dup.begin();
            ans++;
            i -= abs(pos - i);
        }
        cout << ans << endl;
    }
    return 0;
}