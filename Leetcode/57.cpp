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
    static bool compareStart(const Interval a, const Interval& b) {
        return a.start < b.start;
    }
    static bool compareEnd(const Interval& a, const Interval& b) {
        return a.end < b.end;
    }
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> result;
        int startPosition = upper_bound(intervals.begin(), intervals.end(), newInterval, compareStart) - intervals.begin();
        if (startPosition > 0 && intervals[startPosition - 1].end >= newInterval.start) {
            if (intervals[startPosition - 1].end >= newInterval.end) return intervals;
            newInterval.start = intervals[startPosition - 1].start;
            startPosition--;
        }
        for (int i = 0; i < startPosition; i++) {
            result.push_back(intervals[i]);
        }
        int endPosition = upper_bound(intervals.begin(), intervals.end(), newInterval, compareEnd) - intervals.begin();
        if (endPosition < intervals.size() && intervals[endPosition].start <= newInterval.end) {
            newInterval.end = intervals[endPosition].end;
            endPosition++;
        }
        result.push_back(newInterval);
        for (int i = endPosition; i < intervals.size(); i++) {
            result.push_back(intervals[i]);
        }
        return result;
    }
};