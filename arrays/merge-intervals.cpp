/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:

Given intervals [1,3],[6,9] insert and merge [2,5] would result in [1,5],[6,9].

Example 2:

Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] would result in [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

Make sure the returned intervals are also sorted.
*/

// sort in ascending based on start time
bool cmp(Interval a, Interval b)
{
     return a.start <= b.start;
}

vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    
    int i, j, n = intervals.size();
    
    // add this element to the vector
    intervals.push_back(newInterval);
    
    // sort based on ascending, newInterval in sorted position based on start time
    sort(intervals.begin(),intervals.end(),cmp);
    
    // now merge
    // i -> intervals iterator
    // j -> solution iterator, making resulting vector inplace
    i=1, j=0;
    while(i < intervals.size())
    {
        // if solution end overlaps with intervals iterator
        if(intervals[j].end >= intervals[i].start)
        {
            // update the end of last interval of solution
            // to whichever is more of the overlapping ranges
            intervals[j].end = max(intervals[i].end, intervals[j].end);
            
            // note: this keeps happening 
            // so long as last interval of solution overlaps
            // with the intervals at iterator index 'i'
        }
        else
        {
            // intervals iterator is non-overlapping
            // so add it, and increment solutions iterator
            j++;
            intervals[j] = intervals[i];
        }
        i++;
    }
    intervals.erase(intervals.begin() + j + 1, intervals.end());
    return intervals;
}
