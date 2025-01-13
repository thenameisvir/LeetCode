#include <queue>
using namespace std;

class MedianFinder {
private:
    priority_queue<int> maxHeap; // Left part of the data (lower half)
    priority_queue<int, vector<int>, greater<int>> minHeap; // Right part of the data (upper half)

public:
    MedianFinder() {
        // Constructor to initialize the data structure
    }
    
    void addNum(int num) {
        // Add the number to one of the heaps
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }
        
        // Balance the heaps to ensure their sizes differ by at most 1
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        // If the sizes of the heaps are equal, the median is the average of the two middle elements
        if (maxHeap.size() == minHeap.size()) {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
        // If the sizes are not equal, the median is the top of the maxHeap
        return maxHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
