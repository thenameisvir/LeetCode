class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int stops = 0;
        int dist = 0;
        int i = 0;
        int fuel = startFuel;
        priority_queue<int> pq; // Changed to a max heap of int (fuel only).

        while (dist + fuel < target) {
            while (i < stations.size() && stations[i][0] <= dist + fuel) {
                pq.push(stations[i][1]); // Push only fuel values.
                i++;
            }

            if (pq.empty()) {
                return -1; // Return -1 directly if no station is reachable.
            }

            fuel += pq.top(); // Refuel with the maximum available.
            pq.pop();
            stops++;
        }

        return stops;
    }
};
