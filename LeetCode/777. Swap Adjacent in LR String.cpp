// 这道题dfs过不了，核心思路是双指针，保证L往左，所以目标位置不能在右边，得通过看懂这个字符的设置才能这么解题

class Solution {
public:
    bool canTransform(string start, string end) {
        int n = start.size();
        int i = 0, j = 0;
        while(i < n || j < n) {
            // 跳过X
            while(i < n && start[i] == 'X') i++;
            while(j < n && end[j] == 'X') j++;

            if(i == n || j == n) return i == j;
            if(start[i] != end[j]) return false;
            
            if(start[i] == 'L') {
                // L只能往左，原来位置不能比目标更靠左
                if(i < j) return false;
            } else {
                // R只能往右，原来位置不能比目标更靠右
                if(i > j) return false;
            }
            i++; j++;
        }
        return true;
    }
};