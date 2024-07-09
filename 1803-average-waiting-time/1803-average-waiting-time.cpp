class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int size = customers.size();
        if(size == 0){
            return 0;
        }

        long long totalWaitTime = 0;
        long long currentTime = 0;

        for(const auto& customer : customers) {
            int arrival = customer[0];
            int timeToPrepare = customer[1];

            if(currentTime < arrival) {
                currentTime = arrival;
            }
            currentTime += timeToPrepare;
            totalWaitTime += (currentTime - arrival);
        }

        return (double)totalWaitTime / size;
    }
};
