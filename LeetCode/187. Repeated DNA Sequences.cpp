// 第一反应就是map存储，也没想到其他更好的办法
// 提交之后看了下最快解法，是把字符串映射为一个数字，然后用bitset来存储，减少数据量，确实更加优秀
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string, int> m;
        vector<string> res;
        if (s.length() < 10) {
            return res;
        }
        for(int i = 0; i <= s.length() - 10; ++i) {
            string sub = s.substr(i, 10);
            m[sub] += 1;
        }
        for (auto it: m) {
            if (it.second > 1) {
                res.push_back(it.first);
            }
        }
        return res;
    }
};

class Solution {
public:
    inline uint32_t decode(char c)
    {
        switch(c)
        {
            case 'A':
                return 0;
            case 'C':
                return 1;
            case 'G':
                return 2;
            case 'T':
                return 3;
            default:
                return 0;
        }
    }
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> results;
        if (s.size() < 11) return results;
        uint32_t id = 0;
        for (int i=0; i<9; ++i)
        {
            id = id << 2;
            id = id & 0xFFFFF;
            id = id | decode(s[i]);
        }
        bitset<0x100000> seen{};
        bitset<0x100000> inresult{};
        for (int i=9; i<s.length(); ++i)
        {
            id = id << 2;
            id = id & 0xFFFFF;
            id = id | decode(s[i]);
            
            if (seen[id])
            {
                if (! inresult[id])
                {
                    results.emplace_back(&s[i-9], &s[i+1]);
                    inresult[id] = 1;
                }
            }
            else
            {
                if (! inresult[id]) seen[id] = 1;
            }
        }
        return results;
    }
};