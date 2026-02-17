class Solution {
  public:
  bool isPossible(vector<int> &arr,int n,int k,int maxAllowedTime){
      int painters=1,time=0;
      for(int i=0;i<n;i++)
      {
          if(time+arr[i]<=maxAllowedTime)
          {
              time=time+arr[i];
              
          }
          else
          {
              painters++;
              time=arr[i];
          }
      }
      return painters<=k;
  }
    int minTime(vector<int>& arr, int k) {
        int sum=0;
        int n=arr.size();
        int maxVal=INT_MIN;
        for(int i=0;i<n;i++)
        {
            sum=sum+arr[i];
            maxVal=max(maxVal,arr[i]);
        }
        int st=maxVal;
         int end=sum;
         int ans=-1;
         while(st<=end)
         {
             int mid=st+(end-st)/2;
             if(isPossible(arr,n,k,mid))
             {
                 ans=mid;
                 end=mid-1;
             }
             else{
                 st=mid+1;
             }
         }
         return ans;
    }
};
