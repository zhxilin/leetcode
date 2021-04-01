//1507. Reformat Date
class Solution {
public:
    string reformatDate(string date) {
        unordered_map<string, string> 
            months{
                {"Jan", "01"},
                {"Feb", "02"},
                {"Mar", "03"},
                {"Apr", "04"},
                {"May", "05"},
                {"Jun", "06"},
                {"Jul", "07"},
                {"Aug", "08"},
                {"Sep", "09"},
                {"Oct", "10"},
                {"Nov", "11"},
                {"Dec", "12"},
            };
        
        stringstream ss(date);
        string d, m, y;
        ss >> d >> m >> y;
        
        stringstream result;
        result << setfill('0') << setw(4) << y << "-"
            << months[m] << "-"
            << setw(2) << d.substr(0, d.size() - 2);
        return result.str();
    }
};

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();