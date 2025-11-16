想复杂了，自己划分在一一对应，其实浪费的多一点也没关系，代码简洁很多。

class Solution {
public:
    int n, m;
    int rand10() {
        // initialising the values
		n = rand7(), m = 7;
        // making sure n is in the right 1-5 range and, if we can, we settle m too
		while (n > 5) {
            m = n - 5;
            n = rand7();
        }
        // if m was not settled, we do it here
		while (m == 7) m = rand7();
        return (m % 2 ? 5 : 0) + n;
    }
};

// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    unordered_map<int, int> dct;
    bool init = false;

    void Init() {
        if(init) {
            return;
        }
        init = true;
        int count = 0;
        int num = 1;
        for (int i = 1; i <= 7; ++i) {
            if (num == 11) {
                break;
            }
            for(int j = 1; j <= 7; ++j) {
                dct[i * 10 + j] = num;
                ++count;
                if(count == 4) {
                    ++num;
                    count = 0;
                    if(num == 11) {
                        break;
                    }
                }
            }
        }
    }

    int rand10() {
        Init();
        int i = rand7();
        int j = rand7();
        if(dct.find(i * 10 + j) == dct.end()) {
            return rand10();
        }
        return dct[i * 10 + j];
    }
};