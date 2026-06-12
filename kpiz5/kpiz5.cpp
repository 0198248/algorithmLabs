//22. Generate Parentheses
class Solution {
public:
    void backtrack(string current, int open, int close, int n, vector<string>& res) {
        if (current.size() == 2 * n) {
            res.push_back(current);
            return;
        }

        if (open < n) {
            backtrack(current + "(", open + 1, close, n, res);
        }

        if (close < open) {
            backtrack(current + ")", open, close + 1, n, res);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack("", 0, 0, n, res);
        return res;
    }
};