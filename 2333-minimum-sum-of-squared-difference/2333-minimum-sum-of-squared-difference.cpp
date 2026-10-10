class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2,
                               int k1, int k2) {
        int n = nums1.size();
        vector<int> diff(n);

        long long k = (long long)k1 + k2;
        long long total = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            total += diff[i];
        }

        if (k >= total)
            return 0;

        int left = 0, right = 100000;

        while (left < right) {
            int mid = left + (right - left) / 2;
            long long operations = 0;

            for (int d : diff) {
                if (d > mid)
                    operations += d - mid;
            }

            if (operations <= k)
                right = mid;
            else
                left = mid + 1;
        }

        int level = left;
        long long operations = 0;

        for (int d : diff) {
            if (d > level)
                operations += d - level;
        }

        long long remaining = k - operations;
        long long ans = 0;

        for (int d : diff) {
            d = min(d, level);

            if (remaining > 0 && d == level) {
                d--;
                remaining--;
            }

            ans += 1LL * d * d;
        }

        return ans;
    }
};