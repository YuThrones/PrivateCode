class OrderedStream {
public:
    vector<string> stream;
    int last;
    OrderedStream(int n) {
        stream.resize(n);
        last = -1;
    }
    
    vector<string> insert(int idKey, string value) {
        stream[idKey - 1] = value;
        int start = last;
        for (int i = last + 1; i < stream.size(); ++i) {
            if (stream[i] == "") {
                break;
            }
            last = i;
        }
        if (start < last) {
            return vector<string>(stream.begin() + start + 1, stream.begin() + last + 1);
        }
        return {};
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */