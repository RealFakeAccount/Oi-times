    #include<cstdio>  
    #include<cstring>  
    int a[5010];//牛的方向（0:F 1:B）   
    int n,f[5010];//区间[i,i+k-1]是否进行反转   
      
    int slove(int k)  
    {  
        memset(f,0,sizeof(f));  
        int ans=0;  
        int sum=0,i;//sum记录f的和，即下一个牛被反转的次数   
        for(i=0;i+k<=n;++i)  
        {  
            if((a[i]+sum)%2!=0)  
            {  
                ans++;//记录反转的次数   
                f[i]=1;  
            }  
            sum+=f[i];  
            if(i-k+1>=0)//对下一个牛造成反转影响的只是它前面k-1个牛   
                sum-=f[i-k+1];  
        }  
        for(i=n-k+1;i<n;++i)//检查剩下的牛是否有面朝后方的情况   
        {  
            if((a[i]+sum)%2!=0)//表示当前牛面朝后方，已无法经行反转，无解   
                return -1;   
            if(i-k+1>=0)  
                sum-=f[i-k+1];  
        }  
        return ans;  
    }  
      
    int main()  
    {  
        int m,k,i;  
        char s[2];  
        while(scanf("%d",&n)!=EOF)  
        {  
            for(i=0;i<n;++i)  
            {  
                scanf("%s",s);  
                if(s[0]=='F')  
                    a[i]=0;  
                else  
                    a[i]=1;  
            }  
            int K=1,M=n;  
            for(k=1;k<=n;++k)  
            {  
                m=slove(k);  
                if(m>=0&&M>m)//更新m，k的值，确保是在m最小的1情况下，取得最小的k值   
                {  
                    M=m;  
                    K=k;  
                }  
            }  
            printf("%d %d\n",K,M);  
        }  
        return 0;  
    }   
