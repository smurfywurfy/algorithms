#define dbg(x) cout << (#x) << " is " << (x) << endl;
class Solution {
public:
    int strStr(string s, string t) {
        
        //kmp
        // 
        int m = s.size();
        int n = t.size();
        if(t=="") return 0;
        // dp[] -> prefix suffix table of kmp algo
        int dp[n];
        memset(dp,0,sizeof(dp));
        // dp[0] = 0;
        int len = 0;
        for(int i=1;i<n;i++) // wrong
        {
            while(t[i]!=t[len] && len>0)
            {
                len = dp[len-1]; // very IMP step, take eg: ABACxyzABAD, and find answer for 'D'
            }
            if(t[i]==t[len])
            {
                len++;
                dp[i] = len;
            }
            
            
        }
        
        
        // for(int i=0;i<n;i++)
        // {
        //     cout << dp[i] << " ";
        // }cout << endl;
        
        int p =0;
        for(int i=0;i<m;i++)
        {
            
            if(s[i]==t[p]) p++;
            else if(p>0)
            {
                
                p = dp[p-1];
                i--;
            }
            // dbg(p);
            if(p==t.size()) return i-p+1;
            
            
        }
        
        return -1;
        
        
    }
};