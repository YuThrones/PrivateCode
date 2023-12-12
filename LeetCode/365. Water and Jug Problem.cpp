// 自己想了半天分析情况，虽然过了，但是速度差很多，一看答案说是用贝祖定理，用最大公约数来做，本质是一道数学题，那确实是想不到。

class Solution {
public:
    int gcd(int a,int b){
        if(a==0)return b;
        return gcd(b%a,a);
    }
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        return targetCapacity%gcd(jug1Capacity,jug2Capacity) == 0 && targetCapacity<=jug1Capacity+jug2Capacity; 
    }
};

#include <vector>
#include <stack>
#include <cmath>



class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        if (targetCapacity < 0 || targetCapacity > jug1Capacity + jug2Capacity) return false;
        if (targetCapacity == 0 || targetCapacity == jug1Capacity + jug2Capacity) return true;
        std::vector<bool> vec(jug1Capacity + jug2Capacity + 1, false);
        std::stack<int> st;
        vec[0] = true;
        vec[jug1Capacity] = true;
        vec[jug2Capacity] = true;
        
        int temp = abs(jug1Capacity - jug2Capacity);
        vec[temp] = true;
        st.push(temp);
        st.push(jug1Capacity);
        st.push(jug2Capacity);

        int res;

        while(!st.empty()) {
            temp = st.top();
            st.pop();

            // all left in one and add another
            res = temp + jug1Capacity;
            if (temp <= jug2Capacity && !vec[res]) {
                vec[res] = true;
                st.push(res);
            }

            res = temp + jug2Capacity;
            if (temp <= jug1Capacity && !vec[res]) {
                vec[res] = true;
                st.push(res);
            }

            // add left in one and sub another
            res = jug1Capacity - temp;
            if (temp <= jug2Capacity && res > 0 && !vec[res]) {
                vec[res] = true;
                st.push(res);
            }

            res = jug2Capacity - temp;
            if (temp <= jug1Capacity && res > 0 && !vec[res]) {
                vec[res] = true;
                st.push(res);
            }

            res = temp - jug1Capacity;
            if (res > 0 && !vec[res]) {
                vec[res] = true;
                st.push(res);
            }

            res = temp - jug2Capacity;
            if (res > 0 && !vec[res]) {
                vec[res] = true;
                st.push(res);
            }
        }

        return vec[targetCapacity];
    }
};


int main() {
    Solution sol;
    sol.canMeasureWater(34, 5, 6);
}