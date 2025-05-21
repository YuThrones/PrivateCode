最快答案限定范围用bitset检索，确实要更快

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        
        bitset<200002> bf;
        
        int sumA = 0, sumB = 0;
        for(auto n: A) {
            sumA += n;
        }
        for(auto n: B) {
            sumB += n;
            bf.set(2*n);
        }
        
        int diff = sumA - sumB;
        
        for(auto n: A) {
            int det = 2*n - diff;
            if(det > 0 && det < 200002 && bf.test(det)) {
                return {n, (2*n-diff)/2};
            }
        }
        return {};
    }
};

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int sum1 = accumulate(aliceSizes.begin(), aliceSizes.end(), 0);
        int sum2 = accumulate(bobSizes.begin(), bobSizes.end(), 0);
        int diff = (sum1 - sum2) / 2;
        for (int i = 0; i < aliceSizes.size(); ++i) {
            for (int j = 0; j < bobSizes.size(); ++j) {
                if (aliceSizes[i] - bobSizes[j] == diff) {
                    return {aliceSizes[i], bobSizes[j]};
                }
            }
        }
        return {0, 0};
    }
};