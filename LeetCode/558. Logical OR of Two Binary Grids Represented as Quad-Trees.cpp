// 这道题目虽然写出来了，但是对于情况的分析和剪枝做的不是很好，代码有点长了，参考最佳答案还是可以压缩下

/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
        Node* intersect(Node* quadTree1, Node* quadTree2) {
        if(quadTree1->isLeaf && quadTree1->val) return quadTree1;
        if(quadTree2->isLeaf && quadTree2->val) return quadTree2;
        if(quadTree1->isLeaf && !quadTree1->val) return quadTree2;
        if(quadTree2->isLeaf && !quadTree2->val) return quadTree1;     
        
        auto tl = intersect(quadTree1->topLeft, quadTree2->topLeft);
        auto tr = intersect(quadTree1->topRight, quadTree2->topRight);
        auto bl = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
        auto br = intersect(quadTree1->bottomRight, quadTree2->bottomRight);
        
        if(tl->val == tr->val && tl->val == bl->val && tl->val == br->val && tl->isLeaf && tr->isLeaf && bl->isLeaf && br->isLeaf)
            return new Node(tl->val, true, nullptr, nullptr, nullptr, nullptr);
        else         
            return new Node(false, false, tl, tr, bl, br);
    }
};

/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* intersect(Node* quadTree1, Node* quadTree2) {
        if (!quadTree1) {
            return quadTree2;
        }
        if (!quadTree2) {
            return quadTree1;
        }
        if(quadTree1->isLeaf) {
            if (quadTree1->val) {
                return quadTree1;
            }
            else {
                return quadTree2;
            }
        }
        if (quadTree2->isLeaf) {
            if (quadTree2->val) {
                return quadTree2;
            }
            else {
                return quadTree1;
            }
        }
        quadTree1->topLeft = intersect(quadTree1->topLeft, quadTree2->topLeft);
        quadTree1->topRight = intersect(quadTree1->topRight, quadTree2->topRight);
        quadTree1->bottomLeft = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
        quadTree1->bottomRight = intersect(quadTree1->bottomRight, quadTree2->bottomRight);
        if (quadTree1->topLeft && quadTree1->topRight && quadTree1->bottomLeft && quadTree1->bottomRight) {
            if (quadTree1->topLeft->isLeaf && quadTree1->topRight->isLeaf && quadTree1->bottomLeft->isLeaf && quadTree1->bottomRight->isLeaf) {
                if (quadTree1->topLeft->val == quadTree1->topRight->val && quadTree1->bottomLeft->val == quadTree1->topLeft->val && quadTree1->topLeft->val == quadTree1->bottomRight->val) {
                    quadTree1->val = quadTree1->topLeft->val;
                    quadTree1->isLeaf = true;
                    quadTree1->topLeft = nullptr;
                    quadTree1->topRight = nullptr;
                    quadTree1->bottomLeft = nullptr;
                    quadTree1->bottomRight = nullptr;
                }
            }
        }
        return quadTree1;
    }
};