#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
    string capitalizeTitle(string title) {
        int n = title.length();
        int start = 0;  // Start index of the current word

        for (int i = 0; i <= n; i++) {
            if (i == n || title[i] == ' ') {
                if (i - start > 0) {
                    if (i - start > 2) {
                        title[start] = tolower(title[start]);
                        title[start] = toupper(title[start]);
                    } else {
                        title[start] = tolower(title[start]);
                    }
                    for (int j = start + 1; j < i; j++) {
                        title[j] = tolower(title[j]);
                    }
                }
                start = i + 1;
            }
        }

        return title;
    }
};
