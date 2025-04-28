class Solution {
    public:
        char nextGreatestLetter(vector<char>& letters, char target) {
            char result = 0;
            for (auto c : letters) {
                if (c > target && (c < result || result == 0)) {
                    result = c;
                }
            }
            if (result == 0) {
                result = letters[0];
            }
            return result;
        }
    };