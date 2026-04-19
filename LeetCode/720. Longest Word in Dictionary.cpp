// 虽然字典可以检查前缀是否存在，但是速度跟前缀树这种专用数据结构有差异，最佳答案还是前缀树更快

class Solution {
public:
    long long ans;
    static const int N = 10000 + 9;
    int id = 1;
    int tr[N][26];
    bool term[N];

    struct Trie {
        int (&tr)[N][26];
        bool (&term)[N];
        int &id;

        Trie(int (&_tr)[N][26], bool (&_term)[N], int &_id) : tr(_tr), term(_term), id(_id) {}

        void inserT(const string &s) {
            int x = 0;
            for (char cc : s) {
                int c = cc - 'a';
                if (!tr[x][c]) tr[x][c] = id++;
                x = tr[x][c];
            }
            term[x] = true;
        }

        bool valid(const string &s) {
            int x = 0;
            for (char cc : s) {
                int c = cc - 'a';
                if (!tr[x][c]) return false;
                x = tr[x][c];
                if (!term[x]) return false;   // every prefix must be a word
            }
            return true;
        }
    };

    string longestWord(vector<string>& words) {
        Trie T(tr, term, id);

        for (auto &w : words) T.inserT(w);

        string best = "";
        for (auto &w : words) {
            if (T.valid(w)) {
                if (w.size() > best.size() || (w.size() == best.size() && w < best)) {
                    best = w;
                }
            }
        }
        return best;
    }
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        unordered_set<string> word_set(words.begin(), words.end());
        string ans = "";

        for (auto& w : words) {
            bool valid = true;
            for (int i = 1; i < w.size(); ++i) {
                string prefix = w.substr(0, i);
                if (!word_set.count(prefix)) {
                    valid = false;
                    break;
                }
            }
            if (!valid) continue;

            if (compare(w, ans)) {
                ans = w;
            }
        }
        return ans;
    }

    bool compare(string& a, string& b) {
        if (a.length() < b.length()) {return false;}
        if (a.length() > b.length()) {return true;}
        for(int i = 0; i < a.length(); ++i) {
            if (a[i] < b[i]) {
                return true;
            }
            if (a[i] > b[i]) {
                return false;
            }
        }
        return true;
    }
};