// 简单的coding，按点划分string，然后转int，最后先从头到尾比，如果长度不够再判断较长的是否全0即可
class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> n1;
        vector<int> n2;
        int last = 0;
        for (int i = 1; i < version1.length(); ++i) {
            if (version1[i] == '.') {
                n1.push_back(ati(version1.substr(last, i - last)));
                last = i + 1;
            }
        }
        n1.push_back(ati(version1.substr(last, version1.length() - last)));
        last = 0;
        for (int i = 1; i < version2.length(); ++i) {
            if (version2[i] == '.') {
                n2.push_back(ati(version2.substr(last, i - last)));
                last = i + 1;
            }
        }
        n2.push_back(ati(version2.substr(last, version2.length() - last)));
        
        int size = min(n1.size(), n2.size());
        for (int i = 0; i < size; ++i) {
            if (n1[i] > n2[i]) {
                return 1;
            }
            else if (n1[i] < n2[i]) {
                return -1;
            }
        }
        
        if (n1.size() > n2.size()) {
            for (int i = n2.size(); i < n1.size(); ++i) {
                if (n1[i] > 0) {
                    return 1;        
                }
            }
        }
        else if (n1.size() < n2.size()) {
            for (int i = n1.size(); i < n2.size(); ++i) {
                if (n2[i] > 0) {
                    return -1;        
                }
            }
        }
        
        return 0;
    }
    
    int ati(string s) {
        int res = 0;
        for (auto c : s) {
            res = res * 10 + c - '0';
        }
        return res;
    }
};