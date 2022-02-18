 #include<iostream>
#include<vector>
#include <stdlib.h>
#include <time.h>
using namespace std;
 
//imitate 21 points game
vector<int> allprob = { 2,2,2,2,3,3,3,3,4,4,4,4,5,5,5,5,6,6,6,6,7,7,7,7,8,8,8,8,9,9,9,9,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,111,111,111,111 };//111代表可能分配1点或者11点

class player
{
public:
    vector<int> point;//points
    int sumpoint;
    int points = 10;
    bool flag = 0;
    void giveout()
    {
        
        int a = rand() % 54;
        int b = rand() % 54;
        point.push_back(allprob[a]);
        point.push_back(allprob[b]);
        if (allprob[a] + allprob[b] == 113)
        {
            cout << "您太幸运了，同时抽到了A，2，直接获得本轮游戏的胜利";
            flag = 1;
        }
        sum();
    }
    void clear()
    {
        sumpoint = 0;
        flag = 0;
        point.clear();

    }
    int sum()
    {
        sumpoint = 0;
       
        for (int i = 0; i < point.size(); ++i)
        {
            if (point[i] == 111)
            {
                int sum1 = sumpoint + 11;
                if (sum1 > 21)
                    sumpoint += 1;
                else
                    sumpoint += 11;
            }
            else
                sumpoint += point[i];
        }
        return sumpoint;
    }
    void display()
    {
        cout << "目前的非擂主总分数为：" << sumpoint << endl;
        cout << "目前的非擂主总积分为：" << points<< endl;
        if (sumpoint > 21)
            cout << "sorry,非擂主分数爆掉了"<<endl;
    }
    void addnew()
    {
        int c = rand() % 54;
        if (allprob[c] == 111)
        {
           
            cout << "恭喜你，抽中了A，现在您的分数为：" << endl;
            display();
            if (sumpoint > 21)
                point.push_back(allprob[c]-110);
            else 
                point.push_back(allprob[c] - 100);
            
           
        }
        else
        point.push_back(allprob[c]);

       sum();
    }
};
class superplayer
{
public:
    vector<int> superpoint;//points
    int supersumpoint;
    int points = 10;
    bool flag = 0;
    void giveout()
    {
        
        int a = rand() % 54;
        int b = rand() % 54;
        superpoint.push_back(allprob[a]);
        superpoint.push_back(allprob[b]);
        if (allprob[a] + allprob[b] == 113)
        {
            cout << "您太幸运了，同时抽到了A，2，直接获得本轮游戏的胜利";
            flag = 1;
        }
        supersum();
    }
    int supersum()
    {
        supersumpoint = 0;
        for (int i = 0; i < superpoint.size(); ++i)
        {
            if (superpoint[i] == 111)
            {
                int sum2 = supersumpoint + 11;
                if (sum2 > 21)
                    supersumpoint += 1;
                else
                    supersumpoint += 11;
            }
            else
                supersumpoint += superpoint[i];
        }
        return supersumpoint;
    }
    void clear()
    {
        supersumpoint = 0;
        flag = 0;
        superpoint.clear();

    }
    void display()
    {
        cout << "目前擂主的总分数为：" << supersumpoint << endl;
        cout << "目前擂主的总积分为：" << points << endl;
        if (supersumpoint > 21)
            cout << "sorry,擂主分数爆掉了"<<endl;
    }
    void addnew()
    {
        int c = rand() % 54;
        if (allprob[c] == 111)
        {

            cout << "恭喜你，抽中了A，现在您的分数为：" << endl;
            display();
            if (supersumpoint > 21)
                superpoint.push_back(allprob[c] - 110);
            else
                superpoint.push_back(allprob[c] - 100);


        }
        else
        superpoint.push_back(allprob[c]);
       
        supersum();
    }
};
void compare(superplayer& a, player& b)
{
    if (a.superpoint.size() >= 5)
    {
        cout << "擂主获胜";
        b.points--;
    }
    else if (b.point.size() >= 5)
    {
        cout << "非擂主获胜";
        a.points--;
    }
    else if (a.supersum() > 21)
    {
        cout << "非擂主获胜";
        a.points--;
    }
    else if (b.sum() > 21)
    {
        cout << "擂主获胜";
        b.points--;
    }
    else if (a.supersum() >= b.sum())
    {
        cout << "擂主获胜";
        b.points--;
    }
    else
    {
        cout << "非擂主获胜";
    a.points--;
   }
    cout << endl;
    a.display();
    b.display();
}
void compete(superplayer &A, player &B)
{
    cout << endl;
A.giveout();

B.giveout();
// player C;
 //C.giveout();
A.display();
B.display();
//C.display();
cout << "首先轮到非擂主成员" << endl;
char b = 'b';
while (b != '@' && B.flag == 0)
{
    int choose = 0;
    cout << "--------------------------------------" << endl;
    cout << "作为非擂主，你将有以下选择" << endl;
    cout << "1.------------------ - 查看自己点数" << endl;
    cout << "2.------------------ - 给自己抽张牌" << endl;
    cout << "3.------------------ - 不再抽牌并退出操作，退出操作" << endl;
    cin >> choose;
    switch (choose)
    {
    case 0: continue;

    case 1: B.display();
        break;
    case 2: B.addnew();
        break;
    case 3: b = '@';

    }


}
cout << "现在轮到擂主";
char a = 'a';
while (a != '@' && A.flag == 0)
{
    int choose = 0;
    cout << "--------------------------------------" << endl;
    cout << "作为擂主，你将有以下选择" << endl;
    cout << "1.------------------ - 查看自己点数" << endl;
    cout << "2.------------------ - 给自己抽张牌" << endl;
    cout << "3.------------------ - 开始比较评判胜负" << endl;
    cout << "4.------------------ - 退出擂主操作" << endl;
    cin >> choose;
    switch (choose)
    {
    case 0: continue;

    case 1: A.display();
        break;
    case 2: A.addnew();
        break;

    case 3: compare(A, B);
        a = '@';

        break;
    case 4:
    {A.display();
    a = '@';
    cout << "over";
    }
    }

}
A.clear();
B.clear();
}
int main()
{
    srand((unsigned)time(NULL));
    superplayer A;
   
    player B;
    while (A.points > 0 && B.points > 0)
        compete(A, B);
   
    return 0;
}