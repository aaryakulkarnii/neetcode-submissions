/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * };
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval> &intervals) {

        if(intervals.empty())
            return 0;

        sort(intervals.begin(), intervals.end(),
             [](const Interval &a, const Interval &b) {
                 return a.start < b.start;
             });

        priority_queue<int, vector<int>, greater<int>> pq;

        // First meeting occupies one room
        pq.push(intervals[0].end);

        for(int i = 1; i < intervals.size(); i++) {

            int start = intervals[i].start;
            int end = intervals[i].end;

            // Reuse the earliest available room
            if(start >= pq.top()) {
                pq.pop();
            }

            // Occupy a room
            pq.push(end);
        }

        return pq.size();
    }
};