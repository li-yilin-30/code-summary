//v1.0
//��Ҫ�����ٵ�����
#ifndef CHESS_H_
#define CHESS_H_
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class chess
{ private:
    vector<vector<int>> map;
    vector<vector<int>> cop;
    stack<int> skx;//ά��ջ���������ӵ�˳��
    stack<int> sky;
    int mode;
    int jiex;
    int jiey;
    //0�����ֹ����
    //1������Ի���
    int size;
  public:
    chess(int x,int moded)
    {   size=x;
        jiex=x;
        jiey=x;
        mode=moded;
        map.resize(x);
        for(int i=0;i<x;++i)
        {
            map[i].resize(x);
        }
        for(int i=0;i<x;++i)
        {
            for(int j=0;j<x;++j)
            map[i][j]=0;
        }
        // δ����״̬Ϊ0
        // ����״̬��Ϊ1
        // ����״̬��Ϊ3
         cop.resize(x);
        for(int i=0;i<x;++i)
        {
            cop[i].resize(x);
        }
        for(int i=0;i<x;++i)
        {
            for(int j=0;j<x;++j)
            cop[i][j]=0;
        }
    }
    vector<vector<int>> copy1()
    {
        for(int i=0;i<size;++i)
        {
            for(int j=0;j<size;++j)
            {
                cop[i][j]=map[i][j];
            }
        }
        //���ձ��棬Ӧ���ڻ����ٵ����
    }
       vector<vector<int>> copy2()
    {
        for(int i=0;i<size;++i)
        {
            for(int j=0;j<size;++j)
            {
                map[i][j]=cop[i][j];
            }
        }
        //���ڻָ�
    }
    bool isvalid(int x,int y)
    //�ж�����Ƿ���������
    {
       if(x<0||y<0||x>=size||y>=size)
       return false;
       return true;
    }
    int getspace(int x,int y)
    {
        //�������ӵ�������Ŀ
          int space=0;
    if(isvalid((x-1),y))
        {if(map[x-1][y]!=1&&map[x-1][y]!=3)
        ++space;
        }
    if(isvalid((x+1),y))
        {if(map[x+1][y]!=1&&map[x-1][y]!=3)
        ++space;
        }
    if(isvalid(x,(y-1)))
        {if(map[x][y-1]!=1&&map[x-1][y]!=3)
        ++space;
        }
    if(isvalid(x,(y+1)))
        {if(map[x][y+1]!=1&&map[x-1][y]!=3)
        ++space;
        }
    return space;
    }
    bool isdown(int x,int y,int flag)
    //�ж�����Ƿ�Ϸ�
    //���������ڲ��Ϸ��������������û����Ҳ���Ϸ���������
    {
       if(!isvalid(x,y))
       {cout<<"Please make sure to select points in the chessboard"<<endl;
       return false;
       }
       if(map[x][y]==1||map[x][y]==3)
       {cout<<"It already exists here"<<endl;
       return false;
       }
       if(x==jiex&&y==jiey)
       {
           cout<<"���Ǵ�ٵĽ����"<<endl;
           return false;
       }
       //�Ϸ�������
       int space=0;
    if(isvalid((x-1),y))
        {if(map[x-1][y]!=1&&map[x-1][y]!=3)
        ++space;
        }
    if(isvalid((x+1),y))
        {if(map[x+1][y]!=1&&map[x-1][y]!=3)
        ++space;
        }
    if(isvalid(x,(y-1)))
        {if(map[x][y-1]!=1&&map[x-1][y]!=3)
        ++space;
        }
    if(isvalid(x,(y+1)))
        {if(map[x][y+1]!=1&&map[x-1][y]!=3)
        ++space;
        }
    if(space!=0)
    {  copy1();
        if(flag==0)
    map[x][y]=1;
    else
    map[x][y]=3;
    update();
    skx.push(x);
    sky.push(y);
    jiex=size;
    jiey=size;
    //�ж����±��Ե�������
    return true;
    }
    else
    {   map[x][y]=1;
         vector<int> tmp;
         bool flag1=false;
    for(int i=0;i<size;++i)
    {
        for(int j=0;j<size;++j)
        {
            if(getspace(i,j)==0)
            {  flag1=true;
               tmp.push_back(i);
               tmp.push_back(j);
            }
        }
    }
    for(int i=0;i<tmp.size()-1;i=i+2)
    {
      map[tmp[i]][tmp[i+1]]=0;
      //�ָ���û�����ӵ�״̬
    }
    if(!flag1)
    {   map[x][y]=0;
        cout<<"this is a forbidden point"<<endl;
        return false;
    }
    jiex=size;
    jiey=size;
    return true;
    }
}
void update()
{   vector<int> tmp;
    int num=0;
    for(int i=0;i<size;++i)
    {
        for(int j=0;j<size;++j)
        {
            if(getspace(i,j)==0)
            {
               tmp.push_back(i);
               tmp.push_back(j);
               num++;
            }
        }
    }
    if(num==1)
    {  jiex=tmp[0];
       jiey=tmp[1];
        //ֻ��һ�����Ӿ��Ǵ��
    }
    for(int i=0;i<tmp.size()-1;i=i+2)
    {
      map[tmp[i]][tmp[i+1]]=0;
      //�ָ���û�����ӵ�״̬
    }
}
void repentance_chess()
{   if(skx.empty())
    cout<<"you shoule down chess first"<<endl;
    int x=skx.top();
    int y =sky.top();
    skx.pop();
    sky.pop();
    cout<<"withdraw success!"<<"delete"<<x<<','<<y<<endl;
    copy2();
    cout<<"now the state is:"<<endl;
    showmap();
    //�����ǲ�֧�����ӻ���ģ�֧�����ӻ�����Ҫ�����̵�ÿһ��״̬�������ձ���

}
void showmap()
{
    for(int i=0;i<size;++i)
    {
       for(int j=0;j<size;j++)
       {
           cout<<map[i][j]<<'\t';
       }
       cout<<endl;
    }
}
void neighmore(vector<vector<int>> &a,int i,int j,int flag)
{
if(isvalid(i-1,j))
{   if(a[i-1][j]==0)
{  a[i-1][j]=flag;
neighmore(a,i-1,j,flag);
}
}
if(isvalid(i+1,j))
{
    if(a[i+1][j]==0)
{  a[i+1][j]=flag;
neighmore(a,i+1,j,flag);
}
}
if(isvalid(i,j-1))
{if(a[i][j-1]==0)
{  a[i][j-1]=flag;
neighmore(a,i,j-1,flag);
}
}
if(isvalid(i,j+1))
{   if(a[i][j+1]==0)
{  a[i][j+1]=flag;
neighmore(a,i,j+1,flag);
}
}
}



int  count()
{
    showmap();
    cout<<"The current status of the chessboard is as follows. Please make sure it's not in place"<<endl;
    cout<<"do you make sure to count y/n?"<<endl;
    char ans;
    cin>>ans;
    if(ans=='Y'||ans=='y')
    {
       cout<<"please instruct the miss chess,input 'q' means ending"<<endl;
       while(true)
       {
         int tmp1,tmp2;
         cin>>tmp1>>tmp2;
         if(tmp1=='q'||tmp2=='q')
         break;
         map[tmp1][tmp2]=0;
         
       }
       showmap();
    }
       cout<<"are you sure?y/n"<<endl;
        char temp;
        cin>>temp;
    if(temp=='y'||temp=='Y')
    {
       vector<vector<int>> cp;
       cp.resize(size);
       for(int i=0;i<size;++i)
       {
           cp[i].resize(size);
       }
       for(int i=0;i<size;++i)
       {
           for(int j=0;j<size;++j)
           {
               cp[i][j]=map[i][j];
           }
       }
       int sumwhite=0;
       int sumblack=0;
       while(sumwhite<=(size*size/2+10)&&sumblack<=(size*size+10))
     {
       for(int i=0;i<size;++i)
       {
           for(int j=0;j<size;++j)
           {
               switch(cp[i][j])
               {
                case 0: {
                    ;
                }
                case 1: neighmore(cp,i,j,1);

                case 3: neighmore(cp,i,j,3);
               }
           }
       }
     }

     if(sumwhite>sumblack)
     {
         cout<<"Congratulations,White side won"<<endl;
         return 1;
     }
       if(sumwhite<sumblack)
     {
         cout<<"Congratulations, Black side won"<<endl;
         return 1;
     }
    
     else{
         cout<<"in a tie"<<endl;
         return 1;
     }
    }

    

    else
    {cout<<"something seems to be wrong"<<endl;
    return -1;
    }
}
void review()//���̹���
{
   for(int i=0;i<size;++i)
   {
       for(int j=0;j<size;++j)
       {
           map[i][j]=0;
       }
   }
   stack<int>tmp1;
   stack<int>tmp2;
   while(!skx.empty())
   {   tmp1.push(skx.top());
       skx.pop();
       tmp2.push(sky.top());
       sky.pop();
       
   }
   cout<<"input @ for next step,input q for quit"<<endl;
   int flag=1;//����
   while(true)
   {  
       char control;
       cin>>control;
       if(control=='q')
       break;
       if(control=='@')
       {   if(!tmp1.empty()&&flag==1)
       {
           map[tmp1.top()][tmp2.top()]=flag;
           tmp1.pop();
           tmp2.pop();
           flag=3;
       }
       else if(!tmp1.empty()&&flag==3)
        {
           map[tmp1.top()][tmp2.top()]=flag;
           tmp1.pop();
           tmp2.pop();
           flag=1;
       }
       else
       {
           cout<<"review success"<<endl;
       }
       }
       else
       {
           continue;
       }
   }
}

};
#endif