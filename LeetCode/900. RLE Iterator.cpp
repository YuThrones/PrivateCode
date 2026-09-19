class RLEIterator {
public:
    vector<int> data;
    int fi;
    int si;
    RLEIterator(vector<int>& encoding) {
        data = encoding;
        fi = 0;
        si = 0;
    }
    
    int next(int n) {
        int sz = data.size();
        if(fi >= sz) {
            return -1;
        }
        if (fi == n - 2 && si >= data[sz - 1]) {
            return -1;
        }
        while(fi < sz) {
            if(si + n < data[fi]) {
                si += n;
                return data[fi + 1];
            }
            n = n - (data[fi] - si);
            si = 0;
            fi += 2;
            if(n == 0) {
                return data[fi - 1];
            }
        }
        return -1;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */