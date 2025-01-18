#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> result;

        // Sort the product list lexicographically
        sort(products.begin(), products.end());

        string prefix = "";
        auto it = products.begin(); // iterator to track the current valid range

        for (char ch : searchWord) {
            prefix += ch;

            // Use lower_bound to find the first product >= prefix
            it = lower_bound(it, products.end(), prefix);

            vector<string> suggestions;
            for (int i = 0; i < 3 && it + i != products.end(); i++) {
                // Check if the product starts with the current prefix
                if ((*(it + i)).substr(0, prefix.size()) == prefix) {
                    suggestions.push_back(*(it + i));
                } else {
                    break;
                }
            }

            result.push_back(suggestions);
        }

        return result;
    }
};
