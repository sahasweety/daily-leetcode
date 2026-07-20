class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>arr;
        bool inserted = false;

        for(int i =0; i<intervals.size(); i++){
            if(inserted ==false && newInterval[0] < intervals[i][0]){
                arr.push_back(newInterval);
                inserted = true;
            }
            arr.push_back(intervals[i]);
        }
        if(inserted ==false){
            arr.push_back(newInterval);
        }

        vector<vector<int>>ans;
        int start1 = arr[0][0];
        int end1 = arr[0][1];

        for(int i = 1; i<arr.size(); i++){
            int start2 = arr[i][0];
            int end2 = arr[i][1];

            if(start2 <=  end1){
                end1= max(end1,end2);
                continue;            
            }
            ans.push_back({start1 , end1});
            start1 = start2;
            end1=end2;

        }
        ans.push_back({start1 , end1});
        return ans;
            
    }
};