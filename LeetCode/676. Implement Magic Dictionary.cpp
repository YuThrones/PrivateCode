class MagicDictionary {
public:
    vector<string> dic;
    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> dictionary) {
        dic = dictionary;
    }
    
    bool search(string searchWord) {
        for(auto & s : dic) {
            if(s.length() != searchWord.length()) {
                continue;
            }
            int cnt = 0;
            for(int i = 0; i < s.length(); ++i) {
                if(s[i] != searchWord[i]) {
                    ++cnt;
                }
                if(cnt > 1) {
                    break;
                }
            }
            if(cnt == 1) {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */