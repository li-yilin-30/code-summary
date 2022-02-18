#include<iostream>
using namespace std;
const int maxnum=200;//ͼ�����ڵ���Ϊ200
const int maxint=99999;
int dist[maxnum];//Դ�㵽��ǰ��ľ���
int prev[maxnum];//��ǰ�ڵ��ǰ��ڵ�
int c[maxnum][maxnum];//��֮���·������
int n,line;//ͼ�Ľڵ�����·����
void dijkstra(int n,int v,int *dist,int * prev,int c[maxnum][maxnum])
{
    bool s[maxnum];
    for(int i=1;i<=n;++i)
    {
        dist[i]=c[v][i];
        s[i]=0;
        if(dist[i]==maxint)
        prev[i]=0;
        else 
        prev[i]=v;
    }
    dist[v]=0;
    s[v]=1
    for(int i=2;i<=n;++i)
    {
        int tmp=maxint;
        int u=v;
        for(int j=1;j<=n;++j)
        if(!s[j]&&dist[j]<tmp)
        {
            u=j;
            tmp=dist[j]
        }
        s[u]=1;
        for(int j=1;j<=n;++j)
          if(!s[j]&&c[u][j]<maxint)
          {
              int newdist=dist[u]+c[u][j]
              if(newdist<dist[j])
              {
                  dist[j]=newdist;
                  prev[j]=u; 
              }
          }
    }
}
int main()
{for(int i=0;i<5;++i)
{
    for(int j=0;j<5;++j)
    c[i][j]=0;
}
c[0][1]=1;
c[1][2]=2;
c[0][2]=4;
c[2][3]=4;
c[0][3]=7;
dijkstra(0,3,dist,prev,c);

    return 0;
}