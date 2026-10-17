class Solution {
public:
    int digitSum(int x) {
        int sum = 0;
        while (x) {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<pair<int, int>, int>> v;

        for (int i = 0; i < n; i++) {
            v.push_back({{digitSum(nums[i]), nums[i]}, i});
        }

        sort(v.begin(), v.end());

        vector<int> pos(n);
        for (int i = 0; i < n; i++) {
            pos[v[i].second] = i;
        }

        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i] || pos[i] == i) continue;

            int cycle = 0;
            int j = i;

            while (!visited[j]) {
                visited[j] = true;
                j = pos[j];
                cycle++;
            }

            swaps += cycle - 1;
        }

        return swaps;
    }
};