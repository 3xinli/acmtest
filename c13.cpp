#include<cstdio>
#include<iostream>
#include<vector>
#include<map>

using namespace std;

int findorder(int);
map<int,int> order;
vector< vector<int> > edge;

int main()
{
    int K;
    scanf("%d",&K);
    while(K--)
    {
        order.clear();
        edge.clear();
        int k,m,p;
        scanf("%d%d%d",&k,&m,&p);
        for (int i=0;i<=m;i++)
        {
            vector<int> tmp;
            edge.push_back(tmp);
        }
        for(int i=0;i<p;i++)
        {
            int tmp1,tmp2;
            scanf("%d%d",&tmp1,&tmp2);
            edge[tmp2].push_back(tmp1);
        }
        int result=findorder(m);
        /*
        for(int i=1;i<=edge.size();i++)
        {
            printf("%d:",i);
            for(int j=0;j<edge[i].size();j++)
                printf("%d ",edge[i][j]);
            printf("\n");
        }
        */
        /*
        for(int i=1;i<=order.size();i++)
            printf("%d|",order[i]);
        */
        printf("%d %d\n",k,result);
    }
}

int findorder(int m)
{
    if(order[m]!=0)
        return order[m];
    if(edge[m].size()==0)
    {
        order[m]=1;
        return order[m];
    }
    else if(edge[m].size()==1)
    {
        order[m]=findorder(edge[m][0]);
        return order[m];
    }
    else
    {
        int max1=0,max2=0;
        for(int i=0;i<edge[m].size();i++)
        {
            int tmp=findorder(edge[m][i]);
            if(tmp>max1)
            {
                max2=max1;    
                max1=tmp;
            }
            else if(tmp>max2)
                max2=tmp;
        }    
        if(max1==max2)
            order[m]=max1+1;
        else
            order[m]=max1;
        return order[m];
    }
}
