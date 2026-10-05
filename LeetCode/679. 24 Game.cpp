// 这道题思路很容易想到，一开始有些没过也是忘记除法会出现小数了，但是问题在于运行很慢，虽然能过
// 最佳答案保证了每一种情况只计算了一次，极大优化了剪枝，而且尽可能减少了vector的使用，只在预处理操作符序列的时候使用了
// 其他的都通过逻辑判断解决，效率确实差距太大了


class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        vector<float> ca;
        for(int c : cards) {
            ca.push_back(c);
        }
        return cal(ca);
    }

    bool cal(vector<float>& cards) {
        if(cards.size() == 1) {
            return abs(cards[0] - 24) < 0.001;
        }
        for(int i = 0; i < cards.size(); ++i) {
            swap(cards[0], cards[i]);
            for(int j = 1; j < cards.size(); ++j) {
                swap(cards[1], cards[j]);
                vector<float> temp(cards.size() - 1, 0);

                for(int k = 2; k < cards.size(); ++k) {
                    temp[k - 1] = cards[k];
                }
                temp[0] = cards[0] + cards[1];
                if(cal(temp)) {
                    return true;
                }
                temp[0] = cards[0] - cards[1];
                if(cal(temp)) {
                    return true;
                }
                temp[0] = cards[0] * cards[1];
                if(cal(temp)) {
                    return true;
                }
                if (cards[1] != 0) {
                    temp[0] = cards[0] / cards[1];
                    if(cal(temp)) {
                        return true;
                    }
                }
                swap(cards[1], cards[j]);
            }
            swap(cards[0], cards[i]);
        }
        return false;
    }
};  

// 最佳答案
class Solution {
private:
    // ops 保存所有长度为 3 的运算符序列
    // 每个运算符用 0~3 表示：0:+, 1:-, 2:*, 3:/
    // 一共有 4^3 = 64 种组合
    vector<vector<int>> ops;

    // 递归生成所有长度为 3 的运算符序列
    // idx 表示当前正在填第几个运算符（0,1,2）
    // curr 保存当前正在生成的序列
    void _recurse(int idx, auto& curr) {
        // 已经填满 3 个运算符，保存到 ops 中
        if (idx == 3) {
            ops.push_back(curr);
            return;
        }

        // 每个位置都可以尝试 0,1,2,3 四种运算符
        for (int i = 0; i <= 3; i++) {
            curr.push_back(i);          // 放入当前运算符
            _recurse(idx + 1, curr);    // 递归填下一个
            curr.pop_back();            // 回溯，移除当前运算符
        }
    }

    // 预生成所有运算符组合，只调用一次
    void pre() {
        vector<int> curr;
        _recurse(0, curr);  // 从第 0 个位置开始生成
    }

    // 根据运算符 op，计算 a 和 b 的运算结果
    // op: 0 表示 a+b, 1 表示 a-b, 2 表示 a*b, 3 表示 a/b
    double _getOp(double a, double b, int op) {
        if (op == 0) return a + b;
        if (op == 1) return a - b;
        if (op == 2) return a * b;
        if (op == 3) return a / b;  // 注意：这里不检查除零，但浮点除零得到 inf/nan，不会等于 24
        return 0;
    }

    // 检查某一种数字排列 arr 是否能通过某种运算和括号组合得到 24
    // arr 中固定有 4 个数字：a, b, c, d
    bool check(auto& arr) {
        int a = arr[0], b = arr[1], c = arr[2], d = arr[3];

        // 遍历所有 64 种运算符组合
        for (auto& op : ops) {
            // op[0], op[1], op[2] 分别是三个运算符

            // 结构 1： (a op0 b) op1 (c op2 d)
            double v1 = _getOp(_getOp(a, b, op[0]), _getOp(c, d, op[2]), op[1]);
            if (abs(v1 - 24) < 0.000001) return true;

            // 结构 2： ((a op0 b) op1 c) op2 d
            double v2 = _getOp(_getOp(_getOp(a, b, op[0]), c, op[1]), d, op[2]);
            if (abs(v2 - 24) < 0.000001) return true;

            // 结构 3： (a op0 (b op1 c)) op2 d
            double v3 = _getOp(_getOp(a, _getOp(b, c, op[1]), op[0]), d, op[2]);
            if (abs(v3 - 24) < 0.000001) return true;

            // 结构 4： a op0 ((b op1 c) op2 d)
            double v4 = _getOp(a, _getOp(_getOp(b, c, op[1]), d, op[2]), op[0]);
            if (abs(v4 - 24) < 0.000001) return true;

            // 结构 5： a op0 (b op1 (c op2 d))
            double v5 = _getOp(a, _getOp(b, _getOp(c, d, op[2]), op[1]), op[0]);
            if (abs(v5 - 24) < 0.000001) return true;
        }

        return false;
    }

public:
    // 用位掩码 mask 生成 4 个数字的所有全排列
    // a 保存当前正在生成的排列
    // cards 是输入的 4 个数字
    bool solve(auto& a, int mask, auto& cards) {
        // 如果 mask 中有 4 个 1，说明 4 个数字都已经放入 a 中
        if (__builtin_popcount(mask) == 4) {
            return check(a);  // 检查这个排列是否能得到 24
        }

        // 尝试把第 i 个数字放入当前排列
        for (int i = 0; i < 4; i++) {
            // 如果第 i 个数字已经被使用过，跳过
            if (mask & (1 << i)) continue;

            a.push_back(cards[i]);          // 放入数字
            mask ^= (1 << i);               // 标记第 i 个数字已使用（异或相当于置位，因为之前没置位）

            // 递归填充下一个位置
            if (solve(a, mask, cards)) return true;

            // 回溯：移除数字，恢复 mask
            a.pop_back();
            mask ^= (1 << i);               // 注意：mask 是按值传递的，这里恢复其实不影响外层，但写出来更清晰
        }

        return false;
    }

    // 主函数：判断给定的 4 张牌能否算出 24
    bool judgePoint24(vector<int>& cards) {
        vector<int> a;      // 用于保存当前数字排列
        pre();              // 预生成所有 64 种运算符组合
        return solve(a, 0, cards);  // 从空排列、mask=0 开始搜索
    }
};