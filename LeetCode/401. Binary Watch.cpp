// 自己先试了递归，然后再试了cache，都不是最快最省的，比较了一下最佳答案，简洁明了太多了，遍历所有可能也才720种，一个bitset统计比较，太优雅了

class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> rs;  // 存储结果的字符串向量
        // 遍历小时和分钟的可能值
        for (int h = 0; h < 12; h++) {
            for (int m = 0; m < 60; m++) {
                // 使用位运算将小时和分钟组合成一个10位的二进制数，检查二进制数中1的数量是否等于给定的 turnedOn
                if (bitset<10>(h << 6 | m).count() == turnedOn) {
                    // 如果匹配，将当前小时和分钟转换为字符串，并加入到结果向量中
                    rs.emplace_back(to_string(h) + (m < 10 ? ":0" : ":") + to_string(m));
                }
            }
        }    
        return rs;  // 返回包含结果的字符串向量
    }
};


#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <bitset>
using namespace std;


class Solution {
public:
    vector<vector<string>> hourCache;
    vector<vector<string>> minCache;
    vector<vector<string>> totalCache;
    bool isInit = false;


    void initHourCache() {
        hourCache.resize(5);
        for (int i = 0; i < 12; ++i) {
            int count = 0;
            int num = i;
            while(num) {
                if (num & 1)
                    ++count;
                num >>= 1;
            }
            hourCache[count].push_back(to_string(i));
        }
    }

    void initMinCache() {
        minCache.resize(7);
        for (int i = 0; i < 60; ++i) {
            int count = 0;
            int num = i;
            while(num) {
                if (num & 1)
                    ++count;
                num >>= 1;
            }
            std::stringstream formattedTime;
            if (i < 10)
                formattedTime << "0";
            formattedTime << i;
            minCache[count].push_back(formattedTime.str());
        }
    }

    void initTotalCache() {
        if (isInit) return;
        initHourCache();
        initMinCache();
        isInit = true;
    }

    vector<string> readBinaryWatch(int turnedOn) {
        initTotalCache();
        vector<string> res;
        for (int h = 0; h <= 4; ++h) {
            int m = turnedOn - h;
            if (m < 0 || m >= minCache.size()) continue;
            for (auto hRes: hourCache[h]) {
                for (auto mRes: minCache[m]) {
                    std::stringstream formattedTime;
                    formattedTime << hRes << ":" << mRes;
                    res.push_back(formattedTime.str());
                }
            }
        }
        return res;
    }
};


int main() {
}