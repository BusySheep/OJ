/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
private:
    static bool compare(const Interval& a, const Interval& b) {
        return a.start < b.start;
    }
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> result;
        sort(intervals.begin(), intervals.end(), compare);
        for (int i = 0; i < intervals.size(); i++) {
            if (!result.empty() && result.rbegin()->end >= intervals[i].start) {
                result.rbegin()->end = max(result.rbegin()->end, intervals[i].end);
            } else {
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};