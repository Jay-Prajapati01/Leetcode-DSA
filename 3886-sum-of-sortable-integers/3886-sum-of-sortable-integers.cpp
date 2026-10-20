class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefMax(n + 1, 0), suffMin(n + 1, INT_MAX), drops(n, 0);

        for (int i = 0; i < n; i++)
            prefMax[i + 1] = max(prefMax[i], nums[i]);

        for (int i = n - 1; i >= 0; i--)
            suffMin[i] = min(nums[i], suffMin[i + 1]);

        for (int i = 1; i < n; i++)
            drops[i] = drops[i - 1] + (nums[i - 1] > nums[i]);

        auto check = [&](int k) {
            for (int l = 0; l < n; l += k) {
                int r = l + k - 1;
                int cnt = drops[r] - drops[l];

                if (nums[r] > nums[l]) cnt++;
                if (cnt > 1 || prefMax[l] > suffMin[l]) return false;
            }
            return true;
        };

        int ans = 0;

        for (int d = 1; d <= n / d; d++) {
            if (n % d == 0) {
                if (check(d)) ans += d;

                int other = n / d;
                if (other != d && check(other)) ans += other;
            }
        }

        return ans;
    }
};