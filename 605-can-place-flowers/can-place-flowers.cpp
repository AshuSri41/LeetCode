class Solution {
public:
    bool canPlaceFlowers(vector<int>& a, int n) {
        for(int i=0;i<a.size();i++){
            if(a[i]==0 && (i==0 || a[i-1]==0) && 
               (i==a.size()-1 || a[i+1]==0)){
                a[i]=1;
                n--;
            }
        }
        return n<=0;
    }
};