//3. Longest Substring Without Repeating Characters
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        int left = 0, maxLen = 0;

        for (int right = 0; right < s.size(); right++) {
            while (set.count(s[right])) {
                set.erase(s[left]);
                left++;
            }

            set.insert(s[right]);
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};