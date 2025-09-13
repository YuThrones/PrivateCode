// 一开始想用单调栈，但是好像想复杂了，直接检测就行了

class Solution {
public:
    int nextGreaterElement(int n) {
        // 将数字转换为字符串以便操作
        string s = to_string(n);
        int i = s.size() - 2;
        
        // 从右向左找到第一个可以交换的位置
        while (i >= 0 && s[i] >= s[i + 1]) {
            i--;
        }
        
        // 如果没有找到这样的位置，说明无法得到更大的数
        if (i < 0) {
            return -1;
        }
        
        // 从右向左找到比s[i]大的最小数字
        int j = s.size() - 1;
        while (s[j] <= s[i]) {
            j--;
        }
        
        // 交换这两个数字
        swap(s[i], s[j]);
        
        // 反转i右侧的数字，以获得最小可能值
        reverse(s.begin() + i + 1, s.end());
        
        // 检查结果是否在有效范围内
        long long result = stoll(s);
        return (result > INT_MAX) ? -1 : (int)result;
    }
};


class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> v;
        int temp = n;
        while(temp > 0) {
            v.push_back(temp % 10);
            temp /= 10;
        }
        stack<int> st;
        bool find = false;
        int record = -1;
        for(int i = 0; i < v.size(); ++i) {
            if (st.empty()) {
                st.push(i);
            }
            else {
                if (v[i] < v[st.top()]) {
                    find = true;
                    int index = i;
                    while(!st.empty() && v[i] < v[st.top()]) {
                    
                        index = st.top();
                        st.pop();
                    }
                    int num = v[index];
                    v[index] = v[i];
                    v[i] = num;
                    record = i;
                    break;
                }
                else if(v[i] > v[st.top()]) {
                    st.push(i);
                }
            }
        }
        if (!find) {
            return -1;
        }
        sort(v.begin(), v.begin() + record, [&v](int a, int b) {
            return a > b;
        });

        int ans = 0;
        for (int i = v.size() - 1; i >= 0; --i) {
            cout << v[i];
            if (ans > INT_MAX / 10) {
                return -1;
            }
            if (ans * 10 > INT_MAX - v[i]) {
                return -1;
            }
            ans = ans * 10 + v[i];
        }
        return ans;
    }
};