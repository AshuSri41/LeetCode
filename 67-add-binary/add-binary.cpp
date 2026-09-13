class Solution {
public:
    string addBinary(string a, string b) {
        string s;
        int i=a.size()-1,j=b.size()-1,c=0;
        while(i>=0||j>=0||c){
            int x=c;
            if(i>=0)x+=a[i--]-'0';
            if(j>=0)x+=b[j--]-'0';
            s+=x%2+'0';
            c=x/2;
        }
        reverse(s.begin(),s.end());
        return s;
    }
};