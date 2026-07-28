class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {

        if(intervals.empty()) return true;

        sort(intervals.begin(), intervals.end(),
             [](Interval &a, Interval &b){
                 return a.start < b.start;
             });

        int s1 = intervals[0].start;
        int e1 = intervals[0].end;

        for(int i = 1; i < intervals.size(); i++){

            int s2 = intervals[i].start;
            int e2 = intervals[i].end;

            if(s2 < e1){
                return false;
            }

            s1 = s2;
            e1 = e2;
        }

        return true;
    }
};