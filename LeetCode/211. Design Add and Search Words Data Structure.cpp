// 有点奇怪，正常应该就是前缀树解，但是输入之后超时，看了下讨论的其他答案，也是一样思路，copy输入之后也是超时，不知道是不是用例变了


#include <string>
#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;

class Node {
public:
    // unordered_map<char, Node*> nodes;
    map<char, Node*> nodes;
    bool flag;
};

class WordDictionary {
public:
    Node* root;
    
    WordDictionary() {
        root = new Node();
        root->flag = false;
    }
    
    void addWord(string word) {
        Node* cur = root;
        for (int i = 0; i < word.length(); ++i) {
            char c = word[i];
            if (cur->nodes.find(c) == cur->nodes.end()) {
                cur->nodes[c] = new Node();
            }
            cur = cur->nodes[c];
        }
        cur->flag = true;
    }
    
    bool search(string word) {
        return isMatch(root, word, 0);
    }
    
    bool isMatch(Node* cur, string& word, int start) {
        if (start == word.length()) {
            return cur->flag;
        }
        
        char c = word[start];
        if (c == '.') {
            for (auto next: cur->nodes) {
                if (isMatch(next.second, word, start + 1)) {
                    return true;
                }
            }
        }
        else {
            if (cur->nodes.find(c) != cur->nodes.end()) {
                return isMatch(cur->nodes[c], word, start + 1);
            }
        }
        
        return false;
    }
};


/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

int main() {
    WordDictionary wd = WordDictionary();
    wd.addWord("bad");
    wd.addWord("dad");
    wd.addWord("mad");
    cout << wd.search("pad") << endl;
    cout << wd.search("bad") << endl;
    cout << wd.search(".ad") << endl;
    cout << wd.search("b..") << endl;
    return 0;
}