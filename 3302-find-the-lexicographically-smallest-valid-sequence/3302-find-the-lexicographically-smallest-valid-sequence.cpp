class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> last(m, -1);
        int i = n - 1, j = m - 1;

        while (i >= 0 && j >= 0) {
            if (word1[i] == word2[j]) {
                last[j] = i;
                j--;
            }
            i--;
        }

        vector<int> ans(m);
        bool used = false;
        j = 0;

        for (i = 0; i < n && j < m; i++) {
            if (word1[i] == word2[j]) {
                ans[j++] = i;
            } 
            else if (!used && (j == m - 1 || i < last[j + 1])) {
                used = true;
                ans[j++] = i;
            }
        }

        return j == m ? ans : vector<int>();
    }
};