class Solution {
public:

    unordered_map<string, string> dct;
    unordered_map<string, string> re_dct;
    int count = 0;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if(re_dct.find(longUrl) != re_dct.end()) {
            return re_dct[longUrl];
        }
        count += 1;
        string shortUrl = string("http://tinyurl.com/") + to_string(count);
        re_dct[longUrl] = shortUrl;
        dct[shortUrl] = longUrl;
        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        if(dct.find(shortUrl) != dct.end()) {
            return dct[shortUrl];
        }
        return "";
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));