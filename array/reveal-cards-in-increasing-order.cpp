//950. Reveal Cards In Increasing Order
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int size = deck.size();
        
        queue<int> indices;
        for (int i = 0; i < size; ++i)
            indices.push(i);
        
        sort(deck.begin(), deck.end());
        
        vector<int> result(size);
        for (int card : deck) {
            result[indices.front()] = card;
            indices.pop();
            if (!indices.empty()) {
                indices.push(indices.front());
                indices.pop();
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