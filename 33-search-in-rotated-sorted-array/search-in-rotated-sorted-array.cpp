typedef int ll; 
class Solution {
public:
    int search(vector<int>& a,int target) {
        int n = a.size();
        ll low = 0 ; 
        ll high = n-1 ; 
        
        while(low<=high){
            ll mid = (low+high)/2;
            if(a[mid]==target){
                return mid; 
            }else{
                ll current = a[mid];
                if(current<=a[n-1]){
                    //we are in right part of sorted array 
                    if(target<=a[n-1]){
                        if(current<target){
                            low = mid + 1;
                        }else{
                            high = mid - 1;
                        }
                    }else{
                        high = mid - 1;
                    }

                }else{
                    //we are in left part of sorted array 
                    if(target>=a[0]){
                        if(current<target){
                            low = mid + 1;
                        }else{
                            high = mid - 1;
                        }
                    }else{
                        low = mid + 1;
                    }
                }

            }
        }

        return -1;
    }
};