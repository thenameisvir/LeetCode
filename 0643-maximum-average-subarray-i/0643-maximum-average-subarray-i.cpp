class Solution {
public:
    double bruteforce(vector<int>& nums, int k){
        double max_sum = numeric_limits<double>::lowest();
        for(int i = 0; i <= nums.size() - k; i++){
            double current_sum = 0;
            for(int j = i; j < i + k; j++){
                current_sum += nums[j];
            }
            max_sum = max(max_sum, current_sum);
        }
        return max_sum / k;
    }
    double newapproach(vector<int>& nums,int k){
    double currentSum = 0;
    
    
    for (int i = 0; i < k; i++) {
        currentSum += nums[i];
    }

    double maxSum = currentSum;

    
    int i = k;
    
    while (i < nums.size()) {
        currentSum += nums[i] - nums[i - k];
        if (currentSum > maxSum) {
            maxSum = currentSum;
        }
        i++;
    }

    return maxSum/k;
}

    double findMaxAverage(vector<int>& nums, int k) {
        return newapproach(nums, k);
    }
};
