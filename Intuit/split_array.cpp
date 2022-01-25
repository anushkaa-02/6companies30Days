class Solution {
public:
    bool condition(vector<int>& w,int d,int orignalCap){
        int n=w.size();
        int daysReq = 0;
        int c=orignalCap;
        
        for(int i=0;i<n;i++){
            if(w[i] <= c){
                c-= w[i];
            }
            else{
                daysReq++;
                if(daysReq > d) return false;
                
                c = orignalCap;
                c -= w[i];
            }
        }
        daysReq++;
        if(daysReq <= d) return true;
        else return false;
        
    }
    
    int minCapacity(vector<int>& w,int d){
        int n=w.size();
        int sum = 0;
        int maxWt = INT_MIN;
        for(int i=0;i<n;i++){
            sum += w[i];
            maxWt = max(maxWt,w[i]);
        }
        
        int l = maxWt,r=sum;
        
        while(l < r){
            int mid = l + (r-l)/2;
            
            if(condition(w,d,mid)) r = mid;
            else l = mid+1;
        }
        
        return l;
    }
    
    int splitArray(vector<int>& nums, int m) {
        return minCapacity(nums,m);
    }
};
