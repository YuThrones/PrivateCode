#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

/**
 * SAM(后缀自动机)单个状态节点结构体
 * 每个State代表SAM里的一个等价类状态，存储一类后缀的信息
 */
struct State {
    int maxLength;      // 该状态所能表示的【最长连续子串长度】(关键属性)
    int suffixLink;     // 后缀链接(失配指针)：匹配失败时回跳的状态下标，-1代表无，指向虚拟空
    int transitions[101]; // 转移数组：题目数字范围0~100，transitions[val]=目标状态编号；-1代表无此转移

    // 构造函数：初始化成员变量
    State() {
        maxLength = 0;
        suffixLink = -1;
        // 全部转移边初始化为-1：没有任何数字可以从本状态跳转
        memset(transitions, -1, sizeof(transitions)); 
    }
};

class Solution {
private:
    vector<State> automaton; // 后缀自动机本体，容器存所有状态节点
    int lastState;           // 上一次插入字符后，SAM的末尾状态编号(初始是根节点0)

    /**
     * extend函数：SAM核心构造函数，往自动机中插入一个数字num，动态更新SAM结构
     * @param number：待插入的数组元素(数字)
     */
    void extend(int number) {
        // 1. 创建新状态cur，当前新状态下标就是automaton现有size
        int cur = automaton.size();
        automaton.emplace_back(); 

        // 新状态最长子串 = 上一个末尾状态的最长长度 +1
        automaton[cur].maxLength = automaton[lastState].maxLength + 1;
        
        // p从last开始，沿着后缀链接向前回溯
        int p = lastState;

        // 步骤1：沿着后缀链往上找，所有没有number转移的p，全部连边指向cur
        // 含义：原来所有后缀末尾接上当前数字，都可以走到新状态cur
        while (p != -1 && automaton[p].transitions[number] == -1) {
            automaton[p].transitions[number] = cur;
            p = automaton[p].suffixLink; // 顺着后缀链接继续往前找
        }

        // 循环结束分两种情况：p==-1(走到最前面空节点) 或 p存在number转移
        if (p == -1) {
            // 找不到任何已有转移，新状态cur的后缀链接直接指向根节点(0号)
            automaton[cur].suffixLink = 0;
        } 
        else {
            // p节点已经存在number的转移，拿到转移目标节点q
            int q = automaton[p].transitions[number];
            
            // 分支1：q的最长长度刚好等于p最长+1，不需要拆分节点
            // p后面加一个number刚好就是q代表的子串，直接让cur后缀链接指向q
            if (automaton[p].maxLength + 1 == automaton[q].maxLength) {
                automaton[cur].suffixLink = q;
            } 
            // 分支2：q不能直接接，必须克隆拆分q节点(clone拆点，SAM最难的地方)
            else {
                // 新建克隆节点clone，复制q除maxLength以外所有信息
                int clone = automaton.size();
                automaton.emplace_back();

                // clone的最长长度 = p.max+1
                automaton[clone].maxLength = automaton[p].maxLength + 1;
                // 拷贝q所有转移边
                memcpy(automaton[clone].transitions, automaton[q].transitions, sizeof(automaton[q].transitions));
                // clone继承q原来的后缀链接
                automaton[clone].suffixLink = automaton[q].suffixLink;

                // 再次从p向前回溯：所有原来指向q的number转移，全部改成指向clone
                while (p != -1 && automaton[p].transitions[number] == q) {
                    automaton[p].transitions[number] = clone;
                    p = automaton[p].suffixLink;
                }

                // 修改原q和新cur的后缀链接，都挂到clone上
                automaton[q].suffixLink = clone;
                automaton[cur].suffixLink = clone;
            }
        }
        
        // 更新last为当前新节点cur，作为下一次插入的末尾状态
        lastState = cur;
    }

public:
    /**
     * 主函数：求两个数组最长公共连续子数组
     * @param nums1：第一个数组，用来构建SAM
     * @param nums2：第二个数组，在SAM上遍历匹配
     * @return 最长公共连续子数组长度
     */
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        // 初始化SAM：0号节点是根节点
        automaton.emplace_back();
        lastState = 0;
        
        // SAM节点上限：n个元素最多2*n个状态，提前预分配内存，避免vector频繁扩容
        automaton.reserve(nums1.size() * 2);
        
        // ==========阶段1：用nums1全量构建后缀自动机SAM==========
        for (int num : nums1) {
            extend(num);
        }

        // ==========阶段2：拿着nums2逐个数字在SAM中遍历匹配，统计最长连续匹配==========
        int longestMatch = 0;    // 最终答案：全局最长匹配长度
        int currentLength = 0;   // 当前正在连续匹配的子串长度
        int currentState = 0;    // 当前走到SAM中的哪个状态(起点在根节点0)

        for (int num : nums2) {
            // 当前状态没有num转移边：沿着后缀链接不断回退，缩短匹配串
            while (currentState != -1 && automaton[currentState].transitions[num] == -1) {
                // 沿着后缀链接回跳到上一个状态
                currentState = automaton[currentState].suffixLink;
                
                if (currentState != -1) {
                    // 回退到有效状态，当前匹配长度更新为该状态的maxLength
                    currentLength = automaton[currentState].maxLength;
                } else {
                    // 回退到-1(空)，完全匹配失败，长度清零
                    currentLength = 0;
                }
            }

            // 退出while后分两种：找到有效转移 / 彻底找不到
            if (currentState != -1) {
                // 存在num转移，跳转到下一状态
                currentState = automaton[currentState].transitions[num];
                // 成功匹配一个数字，连续长度+1
                currentLength++;
                // 更新全局最大值
                longestMatch = max(longestMatch, currentLength);
            } 
            else {
                // currentState=-1，没有任何匹配，重置到根节点，长度归零
                currentState = 0;
                currentLength = 0;
            }
        }

        return longestMatch;
    }
};

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int ans = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(nums1[i] != nums2[j]) {
                    dp[i][j] = 0;
                }
                else {
                    if(i > 0 && j > 0) {
                        dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
                    }
                    else {
                        dp[i][j] = max(dp[i][j], 1);
                    }
                    
                }
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};