// ds生成的后缀自动机，用于辅助理解
// 核心点：
// 1. 每个state代表的是一个相同的未来状态，而不是某个具体字符串，可能是多个字符串后缀合并到一起
// 2. 每个节点最多分裂一次，因此状态最多是2 * N - 1，N代表字符串长度
// 3. 分裂是为了解决新加入字符之后，原有的一个节点无法描述多个状态的问题
// 4. 后缀自动机构筑之后可以解决的问题：最长公共字符串、不同子串个数、某个子串首次出现位置、某个子串出现次数等

#include <bits/stdc++.h>
using namespace std;

class SuffixAutomaton {
public:
    struct State {
        int len, link;
        int next[26];          // 假设只含小写字母
        long long endposSize;  // 该状态代表的子串的出现次数（需预处理）
        int firstPos;          // 该状态中某个子串的结束位置（用于提取子串）
        State() : len(0), link(-1), endposSize(0), firstPos(-1) {
            memset(next, 0, sizeof(next));
        }
    };

    vector<State> st;
    int last;
    string str;  // 构建时用的原串（用于提取子串）

    SuffixAutomaton() {
        st.emplace_back();  // 状态0，空串
        last = 0;
    }

    // 预留空间，n 为字符串长度上限
    void reserve(int n) {
        st.reserve(2 * n);
    }

    // 加入一个字符 c ('a'..'z')，pos 为该字符在原串中的下标
    void extend(char ch, int pos = -1) {
        int c = ch - 'a';
        int cur = st.size();
        st.emplace_back();
        st[cur].len = st[last].len + 1;
        st[cur].endposSize = 1;      // 新状态的 endpos 至少包含当前位置
        st[cur].firstPos = pos;      // 记录结束位置

        int p = last;
        while (p != -1 && !st[p].next[c]) {
            st[p].next[c] = cur;
            p = st[p].link;
        }

        if (p == -1) {
            st[cur].link = 0;        // 连向空串状态
        } else {
            int q = st[p].next[c];
            if (st[p].len + 1 == st[q].len) {
                st[cur].link = q;
            } else {
                int clone = st.size();
                st.emplace_back();
                st[clone].len = st[p].len + 1;
                memcpy(st[clone].next, st[q].next, sizeof(st[q].next));
                st[clone].link = st[q].link;
                st[clone].endposSize = 0;   // clone 本身不是终点
                st[clone].firstPos = st[q].firstPos; // 复制 firstPos

                while (p != -1 && st[p].next[c] == q) {
                    st[p].next[c] = clone;
                    p = st[p].link;
                }
                st[q].link = st[cur].link = clone;
            }
        }
        last = cur;
    }

    // 建完 SAM 后调用，计算每个状态的 endposSize（子树和）
    void build() {
        // 按 len 从大到小排序（计数排序）
        int n = str.size();
        vector<int> order(st.size());
        vector<int> cnt(n + 1, 0);
        for (int i = 0; i < st.size(); ++i)
            cnt[st[i].len]++;
        for (int i = 1; i <= n; ++i)
            cnt[i] += cnt[i - 1];
        for (int i = st.size() - 1; i >= 0; --i)
            order[--cnt[st[i].len]] = i;

        // 从长到短累加 endposSize（link 树上的子树和）
        for (int i = st.size() - 1; i > 0; --i) {
            int v = order[i];
            st[st[v].link].endposSize += st[v].endposSize;
        }
        st[0].endposSize = 0;  // 空串不计出现次数
    }

    // 1. 本质不同子串个数
    long long distinctSubstrings() const {
        long long ans = 0;
        for (int i = 1; i < st.size(); ++i)
            ans += st[i].len - st[st[i].link].len;
        return ans;
    }

    // 2. 所有本质不同子串的总长度
    long long totalDistinctLength() const {
        long long ans = 0;
        for (int i = 1; i < st.size(); ++i) {
            int l = st[st[i].link].len + 1;
            int r = st[i].len;
            ans += (long long)(l + r) * (r - l + 1) / 2;
        }
        return ans;
    }

    // 3. 查询子串 t 的出现次数（匹配不到则返回 0）
    int count(const string &t) const {
        int v = 0;
        for (char ch : t) {
            int c = ch - 'a';
            if (!st[v].next[c]) return 0;
            v = st[v].next[c];
        }
        return st[v].endposSize;
    }

    // 4. 查询子串 t 第一次出现的位置（匹配不到则返回 -1）
    int firstPos(const string &t) const {
        int v = 0;
        for (char ch : t) {
            int c = ch - 'a';
            if (!st[v].next[c]) return -1;
            v = st[v].next[c];
        }
        // firstPos 是结束位置，要减去长度得到起始位置
        return st[v].firstPos - (int)t.size() + 1;
    }

    // 5. 与另一个串的最长公共子串（返回子串本身）
    string longestCommonSubstring(const string &other) const {
        int v = 0, len = 0;
        int bestLen = 0, bestV = 0;  // 记录最大值时的状态
        for (char ch : other) {
            int c = ch - 'a';
            while (v != 0 && !st[v].next[c]) {
                v = st[v].link;
                len = st[v].len;
            }
            if (st[v].next[c]) {
                v = st[v].next[c];
                ++len;
            } else {
                v = 0;
                len = 0;
            }
            if (len > bestLen) {
                bestLen = len;
                bestV = v;
            }
        }
        if (bestLen == 0) return "";
        // 从 bestV 的 firstPos 中截取对应长度的子串
        int endPos = st[bestV].firstPos;
        return str.substr(endPos - bestLen + 1, bestLen);
    }

    // 6. 字典序第 k 小的本质不同子串（k 从 1 开始，若超过总数则返回空串）
    string kthDistinctSubstring(long long k) const {
        // 先 DP 计算从每个状态出发能走出的不同子串数（包括在该状态结束）
        vector<long long> dp(st.size(), 1); // 1 表示当前状态本身作为一个子串结束
        // 按 len 降序 DP（因为转移边的 len 严格递增）
        int n = str.size();
        vector<int> order(st.size());
        vector<int> cnt(n + 1, 0);
        for (int i = 0; i < st.size(); ++i) cnt[st[i].len]++;
        for (int i = 1; i <= n; ++i) cnt[i] += cnt[i - 1];
        for (int i = st.size() - 1; i >= 0; --i)
            order[--cnt[st[i].len]] = i;

        for (int i = st.size() - 1; i >= 0; --i) {
            int v = order[i];
            for (int c = 0; c < 26; ++c) {
                if (st[v].next[c]) {
                    dp[v] += dp[st[v].next[c]];
                }
            }
        }
        // 根结点 dp[0] 包含了空串，我们需要去除空串
        if (k > dp[0] - 1) return "";  // 超过总数

        string ans;
        int v = 0;
        while (k > 0) {
            for (int c = 0; c < 26; ++c) {
                if (!st[v].next[c]) continue;
                int nxt = st[v].next[c];
                if (dp[nxt] >= k) {
                    // 进入这个分支，先消耗掉“当前状态本身”的计数（即一个字符）
                    k--;          // 已经把这个字符当作子串的结尾
                    ans += char('a' + c);
                    v = nxt;
                    break;
                } else {
                    k -= dp[nxt];
                }
            }
        }
        return ans;
    }

    // 7. 不在原串中的最短字符串（字典序最小）
    string shortestMissing() const {
        // BFS 状态 (v, 当前字符串)
        queue<pair<int, string>> q;
        q.push({0, ""});
        while (!q.empty()) {
            auto [v, s] = q.front(); q.pop();
            for (int c = 0; c < 26; ++c) {
                if (!st[v].next[c]) {
                    // 没有转移，说明这个字符加上去后不在原串中
                    return s + char('a' + c);
                }
                q.push({st[v].next[c], s + char('a' + c)});
            }
        }
        return ""; // 永远不会执行到
    }

    // 辅助：打印所有状态信息（调试用）
    void debug() const {
        for (int i = 0; i < st.size(); ++i) {
            printf("State %d: len=%d, link=%d, endposSize=%lld, firstPos=%d\n",
                   i, st[i].len, st[i].link, st[i].endposSize, st[i].firstPos);
        }
    }
};

int main() {
    // 示例：构建 "ababa" 的 SAM
    string s = "ababa";
    SuffixAutomaton sam;
    sam.reserve(s.size());
    for (int i = 0; i < s.size(); ++i)
        sam.extend(s[i], i);
    sam.str = s;
    sam.build();

    cout << "原串: " << s << endl;
    cout << "本质不同子串个数: " << sam.distinctSubstrings() << endl;
    cout << "本质不同子串总长度: " << sam.totalDistinctLength() << endl;
    cout << "\"ba\" 出现次数: " << sam.count("ba") << endl;
    cout << "\"ab\" 第一次出现位置: " << sam.firstPos("ab") << endl;

    string t = "baba";
    cout << "与 \"" << t << "\" 的最长公共子串: " << sam.longestCommonSubstring(t) << endl;

    // 字典序第 k 小子串
    for (int k = 1; k <= 9; ++k) {
        cout << "第 " << k << " 小子串: " << sam.kthDistinctSubstring(k) << endl;
    }

    cout << "最短未出现子串: " << sam.shortestMissing() << endl;

    sam.debug();

    return 0;
}