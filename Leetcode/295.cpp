class MedianFinder {
private:
    multiset<int> smallData;
    multiset<int> largeData;
public:

    // Adds a number into the data structure.
    void addNum(int num) {
        if (smallData.empty() && largeData.empty()) {
            smallData.insert(num);
        } else if (smallData.empty()) {
            largeData.insert(num);
        } else if (largeData.empty()) {
            smallData.insert(num);
        } else {
            if (num >= *largeData.begin()) largeData.insert(num);
            else smallData.insert(num);
        }
        if (largeData.size() > smallData.size() + 1) {
            int temp = *largeData.begin();
            largeData.erase(largeData.begin());
            smallData.insert(temp);
        } else if (smallData.size() > largeData.size() + 1) {
            int temp = *smallData.rbegin();
            auto end = smallData.end();
            end--;
            smallData.erase(end);
            largeData.insert(temp);
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        int totalSize = smallData.size() + largeData.size();
        if (totalSize & 1) {
            if (smallData.size() > largeData.size()) return *smallData.rbegin();
            else return *largeData.begin();
        } else {
            return (double) (*smallData.rbegin() + *largeData.begin()) / 2;
        }
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();