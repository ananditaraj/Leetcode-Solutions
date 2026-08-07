class Solution {
public:
    string smallestNumber(string num,long long t){
        int r2=0,r3=0,r5=0,r7=0;
        while(t%2==0)t/=2,r2++;
        while(t%3==0)t/=3,r3++;
        while(t%5==0)t/=5,r5++;
        while(t%7==0)t/=7,r7++;
        if(t>1)return "-1";

        int dp[60][40];
        memset(dp,0x3f,sizeof(dp));
        dp[0][0]=0;

        int tr[6][2]={{1,0},{0,1},{2,0},{1,1},{3,0},{0,2}};
        for(int i=0;i<60;i++)
            for(int j=0;j<40;j++){
                if(dp[i][j]>1e8)continue;
                for(auto &x:tr){
                    int ni=min(59,i+x[0]),nj=min(39,j+x[1]);
                    dp[ni][nj]=min(dp[ni][nj],dp[i][j]+1);
                }
            }
        for(int i=59;i>=0;i--)
            for(int j=39;j>=0;j--){
            if(i<59)dp[i][j]=min(dp[i][j],dp[i+1][j]);
                if(j<39)dp[i][j]=min(dp[i][j],dp[i][j+1]);
            }

        int F2[]={0,0,1,0,2,0,1,0,3,0},F3[]={0,0,0,1,0,0,1,0,0,2}, F5[]={0,0,0,0,0,1,0,0,0,0},F7[]={0,0,0,0,0,0,0,1,0,0};

        int n=num.size(),z=n;
        for(int i=0;i<n;i++)if(num[i]=='0'){z=i;break;}
        if(z==n){
            int a=r2,b=r3,c=r5,d=r7;
            for(char ch:num){
                int x=ch-'0';
                a=max(0,a-F2[x]);
                b=max(0,b-F3[x]);
                c=max(0,c-F5[x]);
                d=max(0,d-F7[x]);
            }
            if(!a&&!b&&!c&&!d)return num;
        }

        int lim=min(n-1,z),p2=0,p3=0,p5=0,p7=0;
        for(int i=0;i<lim;i++){
            int x=num[i]-'0';
            p2+=F2[x];
            p3+=F3[x];
            p5+=F5[x];
            p7+=F7[x];
        }

        for(int i=lim;i>=0;i--){
            for(int d=num[i]-'0'+1;d<=9;d++){
                int a=max(0,r2-p2-F2[d]);
                int b=max(0,r3-p3-F3[d]);
                int c=max(0,r5-p5-F5[d]);
                int e=max(0,r7-p7-F7[d]);
                int L=n-1-i;

                if(e+c+dp[a][b]<=L){
                    string ans=num.substr(0,i)+to_string(d);
                    int x2=a,x3=b,x5=c,x7=e;

                    for(int pos=0;pos<L;pos++){
                        for(int x=1;x<=9;x++){
                            int y2=max(0,x2-F2[x]);
                            int y3=max(0,x3-F3[x]);
                            int y5=max(0,x5-F5[x]);
                            int y7=max(0,x7-F7[x]);

                            if(y7+y5+dp[y2][y3]<=L-1-pos){
                                ans+=char('0'+x);
                                x2=y2;x3=y3;x5=y5;x7=y7;
                                break;
                            }
                        }
                    }
                    return ans;
                }
            }
            if(i){
                int x=num[i-1]-'0';
                p2-=F2[x];
                p3-=F3[x];
                p5-=F5[x];
                p7-=F7[x];
            }
        }

        int m=max(n+1,r7+r5+dp[r2][r3]);
        string ans="";
        int a=r2,b=r3,c=r5,d=r7;

        for(int pos=0;pos<m;pos++){
            for(int x=1;x<=9;x++){
                int y2=max(0,a-F2[x]);
                int y3=max(0,b-F3[x]);
                int y5=max(0,c-F5[x]);
                int y7=max(0,d-F7[x]);

                if(y7+y5+dp[y2][y3]<=m-1-pos){
                    ans+=char('0'+x);
                    a=y2;b=y3;c=y5;d=y7;
                    break;
                }
            }
        }
        return ans;
    }
};