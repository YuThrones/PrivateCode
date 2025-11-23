// 我的想法是固定第一个数，然后第二个数二分，但是好像想复杂了，不够快。
// 最佳答案是第一个数从0开始，第二个数从sqrt开始，平方之和小了就加左边，大了就减少右边，好像足以覆盖了。

class Solution {
 public:
  bool judgeSquareSum(int c) {
    unsigned l = 0;
    unsigned r = sqrt(c);

    while (l <= r) {
      const unsigned sum = l * l + r * r;
      if (sum == c)
        return true;
      if (sum < c)
        ++l;
      else
        --r;
    }

    return false;
  }
};

class Solution {
public:
    bool judgeSquareSum(int c) {
        long long min = 0;
        long long max = sqrt(c) + 1;
        for(long long i = min; i <= max; ++i) {
            long long l = i;
            long long r = max;
            while(l <= r) {
                long long mid = (l + r) / 2;
                long long temp = i * i + mid * mid;
                if(temp == c) {
                    return true;
                }
                else if (temp > c) {
                    r = mid - 1;
                }
                else {
                    l = mid + 1;
                }
            }
        }
        return false;
    }
};