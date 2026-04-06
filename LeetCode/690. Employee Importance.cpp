/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> dct;
        for(const auto& e : employees) {
            dct[e->id] = e;
        }
        int ans = 0;
        queue<Employee*> que;
        que.push(dct[id]);
        while(!que.empty()) {
            Employee* temp = que.front();
            que.pop();
            ans += temp->importance;
            for(const auto& i : temp->subordinates) {
                que.push(dct[i]);
            }
        }
        return ans;
    }
};