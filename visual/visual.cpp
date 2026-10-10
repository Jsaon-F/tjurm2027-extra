/*本题目主要考查类的使用,不了解类的同学建议先去学习相关知识。

    背景介绍：在Robomaster比赛中，一个机器人在进行自瞄的时候有时会同时识别到多个敌方目标。此时机器人需要
    选择其中一个来作为最佳打击目标并进行打击。通常我们会锁定距离准心（操作手端的屏幕中心）最近的目标。
    示例    ————————————————————————————————————————————
            |                       T                  |
            |        H            (1,4)                |
            |      (-9,3)                              |         
            |                                          |
            |                     +                    |      此时应当锁定S目标
            |                S                         |
            |              (-3,1)                      |
            |                              I           |
            |                            (7,-3)        |
            ————————————————————————————————————————————

    题目：编写一个程序，记录4个敌方目标的二维坐标，锁定距离准心最近的目标并输出对应的兵种ID。
    
    要求：采用面向对象的方法，设计两个类：
    Enemy 类：包含敌人的坐标和兵种ID，以及相应的设置和获取函数。
    Target 类：包含一个 Enemy 类的对象数组，并具备选择并返回最佳打击目标和输出的功能。

    PS：获取输入数据的框架已经替各位实现好了，在对应的地方调用你们编写的设置函数即可。
*/

#include <iostream>
#include <cmath>

using namespace std;

// ==================== 在此处编写 Enemy和Target 类 ====================
class Enemy
{
public:
    int x,y;
    char id;
public:
    void myset(int pos_x,int pos_y,char give_id){
        x = pos_x;y = pos_y;
        id = give_id;
    }
    char returnid(){
        return this->id;
    }
    int return_pos_x(char id){
        return this->x;
    }
    int return_pos_y(char id){
        return this->y;
    }
};

class Target : public Enemy
{
public:
    double distance[4] = {0.0};
    Enemy enemys[4];
    //Target(const Enemy& e1,const Enemy& e2,const Enemy& e3,const Enemy& e4):enemys{e1,e2,e3,e4}{}
public:
    double get_distance(int x,int y){
        double val = sqrt(x*x + y*y);
        return val;
    }
    void choose(double distance[]){
        double min = fmin(distance[0],fmin(distance[1],fmin(distance[2],distance[3])));
        int record = 0;
        for (int i = 0; i < 4; i++)
        {
            if (min == distance[i])
            {   
                record = i;
                break;
            }  
        }
        //enemy[i]是最近的
        char tar = enemys[record].returnid();
        cout << tar <<endl;
        
    }
};



// ====================================================================


int main() {
    Enemy enemy[4];
    for (int i = 0; i < 4; i++) {
        double x, y;
        char id;
        cout << "请输入第 " << i + 1 << " 个目标的兵种ID和坐标(x y): ";
        cin >> id >> x >> y;

        //在此处调用你的Enemy的设置函数，传入id,x,y
        enemy[i].myset(x,y,id);
    }
    Target tar;
    for(int j = 0;j < 4;j++)
    {
        tar.enemys[j] =  enemy[j];
        tar.distance[j] = tar.get_distance(tar.enemys[j].x,tar.enemys[j].y);
    }
    tar.choose(tar.distance);
    return 0;
}
