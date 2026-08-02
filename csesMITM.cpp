#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    long long x;
    cin >> x;

    vector<long long> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int n1 = n / 2;
    int n2 = n - n1;

    vector<long long> suma;
    vector<long long> sumb;

    // All subset sums of first half
    for (int mask = 0; mask < (1 << n1); mask++) {
        long long sum = 0;
        for (int i = 0; i < n1; i++) {
            if (mask & (1 << i))
                sum += arr[i];
        }
        suma.push_back(sum);
    }

    // All subset sums of second half
    for (int mask = 0; mask < (1 << n2); mask++) {
        long long sum = 0;
        for (int i = 0; i < n2; i++) {
            if (mask & (1 << i))
                sum += arr[n1 + i];
        }
        sumb.push_back(sum);
    }

    sort(sumb.begin(), sumb.end());

    long long ans = 0;

    for (long long sum : suma) {
        long long need = x - sum;

        auto l = lower_bound(sumb.begin(), sumb.end(), need);
        auto r = upper_bound(sumb.begin(), sumb.end(), need);

        ans += (r - l);
    }

    cout << ans << endl;

    return 0;
}