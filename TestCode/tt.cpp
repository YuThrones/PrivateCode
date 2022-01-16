#include<iostream>
#include<queue>
using namespace std;

int main() {
    priority_queue<int, vector<int>, greater<int> > heap1 = priority_queue<int, vector<int>, greater<int> >();
    priority_queue<int, vector<int>, greater<int> > heap2 = priority_queue<int, vector<int>, greater<int> >();
    // int input[] = {1, 2, 3, 4, 5};
    // // for (auto i: input) {
    // //     heap.push(i);
    // //     cout << heap.top() << endl;
    // // }
    // cout << 0 - 1 << endl;
    // if (0 - 1 > 1) {
    //     cout << "one";
    // }
    // else {
    //     cout << "two";
    // }
    cout << heap1.size() << endl;
    cout << heap2.size() << endl;
    cout << heap1.size() + 1 << endl;
    cout << heap2.size() - 1 << endl;
    cout << (heap2.size() - heap1.size()) << endl;
    cout << (heap1.size() - heap2.size()) << endl;
    return 0;
}