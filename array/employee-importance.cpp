//690. Employee Importance
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
        unordered_map<int, Employee*> mx;
        for (auto& e : employees) {
            mx[e->id] = e;
        }
        
        return dfs(mx, id);
    }

private:
    int dfs(unordered_map<int, Employee*>& mx, int id) {
        if (!mx.count(id))
            return 0;
        
        int v = mx[id]->importance;
        for (auto& sub : mx[id]->subordinates) {
            v += dfs(mx, sub);
        }
        return v;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();