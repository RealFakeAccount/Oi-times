    #include<cstdio>  
    #include<cstring>  
    int a[5010];//ţ�ķ���0:F 1:B��   
    int n,f[5010];//����[i,i+k-1]�Ƿ���з�ת   
      
    int slove(int k)  
    {  
        memset(f,0,sizeof(f));  
        int ans=0;  
        int sum=0,i;//sum��¼f�ĺͣ�����һ��ţ����ת�Ĵ���   
        for(i=0;i+k<=n;++i)  
        {  
            if((a[i]+sum)%2!=0)  
            {  
                ans++;//��¼��ת�Ĵ���   
                f[i]=1;  
            }  
            sum+=f[i];  
            if(i-k+1>=0)//����һ��ţ��ɷ�תӰ���ֻ����ǰ��k-1��ţ   
                sum-=f[i-k+1];  
        }  
        for(i=n-k+1;i<n;++i)//���ʣ�µ�ţ�Ƿ����泯�󷽵����   
        {  
            if((a[i]+sum)%2!=0)//��ʾ��ǰţ�泯�󷽣����޷����з�ת���޽�   
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
                if(m>=0&&M>m)//����m��k��ֵ��ȷ������m��С��1����£�ȡ����С��kֵ   
                {  
                    M=m;  
                    K=k;  
                }  
            }  
            printf("%d %d\n",K,M);  
        }  
        return 0;  
    }   
