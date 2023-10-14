// 这道题是用宽度优先搜索，一个队列来维护当前步数能突变成的基因，用一个set维护能够突变的基因
// 每次当前基因搜索所有突变，假设startGene的length为m，bank的size为n，复杂度最差是O(mn）

#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:

    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> bSet(bank.begin(), bank.end());
        queue<string> sQueue;
        sQueue.push(startGene);
        string gene = "ACGT";
        int res = 0;
        while(!sQueue.empty()) {
            int size = sQueue.size();
            for (int i = 0; i < size; ++i) {
                string top = sQueue.front();
                sQueue.pop();
                if (top == endGene) return res;
                for (int j = 0; j < top.length(); ++j) {
                    char old = top[j];
                    for (auto& c: gene) {
                        if (c == old) continue;
                        top[j] = c;
                        if (bSet.find(top) != bSet.end()) {
                            sQueue.push(top);
                            bSet.erase(top);
                        }
                    }
                    top[j] = old;
                }
            }
            ++res;
        }
        return -1;
    }
};

int main() {
    string startGene = "AACCGGTT", endGene = "AAACGGTA";
    vector<string> bank = {"AACCGGTA","AACCGCTA","AAACGGTA"};
    Solution sol;
    sol.minMutation(startGene, endGene, bank);
    return 0;
}