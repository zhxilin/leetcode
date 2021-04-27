//350. Intersection of Two Arrays II
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        unordered_map<int, int> mx;
        
        vector<int> result;
        
        for (int i = 0; i < n1; ++i) {
            mx[nums1[i]]++;
        }
        
        for (int i = 0; i < n2; ++i) {
            if (--mx[nums2[i]] >= 0) {
                result.push_back(nums2[i]);
            }
        }
        
        return result;
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();