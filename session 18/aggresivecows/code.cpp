class Solution {
  public:
  bool canplace(vector<int> &stalls,int k,int mid){
            int count=1;
            int pos=stalls[0];
            for(int i=1;i<stalls.size();i++){
                if(stalls[i]-pos>=mid) {
                    count++;
                    pos = stalls[i];
                }
            }
            return count>=k; 
        }
    int aggressiveCows(vector<int> &stalls, int k) {
        
        
        
        sort(stalls.begin(),stalls.end());
        int high = stalls[stalls.size()-1];
        int low=0;
        int ans=0;
        while(low<=high){
            
           int mid=(low+high)/2;
            if(canplace(stalls,k,mid)){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};
