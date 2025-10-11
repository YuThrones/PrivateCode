class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        pair<int, int> val1 = getVal(num1);
        pair<int, int> val2 = getVal(num2);
        return to_string(val1.first * val2.first - val1.second * val2.second) + "+" +
        to_string(val1.first * val2.second + val2.first * val1. second) + "i";
    }

    pair<int, int> getVal(string num) {
        int real = 0;
        int imag = 0;
        size_t pos = num.find('+');
        if (pos != std::string::npos) {
            real = stoi(num.substr(0, pos));
            imag = stoi(num.substr(pos + 1, num.length() - pos));
        }
        else {
            real = stoi(num);
        }
        return {real, imag};
    }
};