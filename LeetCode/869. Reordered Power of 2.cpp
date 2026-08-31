// 这道题虽然全排列能过，但是太慢了，其实核心在于范围，32位的2的幂是有限的，只需要列举出来之后按顺序排列比较是否相同就行，想少了

class Solution
{
public:
	bool reorderedPowerOf2(int n)
	{
		string s = to_string(n);
		std::sort(s.begin(), s.end());

		for (int i = 0; i < 32; ++i)
		{
			string s2 = to_string(1 << i);

			std::sort(s2.begin(), s2.end());
			if (s == s2)
				return true;
		}

		return false;
	}
};

class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<int> arr;
        while(n > 0) {
            arr.push_back(n % 10);
            n /= 10;
        }
        return cal(arr, 0);
    }
    bool cal(vector<int>& arr, int start) {
        if(start == arr.size()) {
            int temp = 0;
            for(int i = 0; i < arr.size(); ++i) {
                temp *= 10;
                temp += arr[i];
            }
            return test(temp);
        }
        for(int i = start; i < arr.size(); ++i) {
            if (arr[i] == 0 && start == 0) {
                continue;
            }
            if (i > start) {
                swap(arr[i], arr[start]);
                if(cal(arr, start + 1)) {
                    return true;
                }
                swap(arr[i], arr[start]);
            }
            else {
                if(cal(arr, start + 1)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool test(int n) {
        while(n > 1) {
            if (n % 2 != 0) {
                return false;
            }
            n /= 2;
        }
        return n == 1;
    }

};