#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;
bool gameover;
const int width=30,hight=10;
int x,y,fx,fy,scor;
int ntail ,tailX[40],tailY[40];
enum dirx {Stop,Left,Right,up,down};
dirx dir;

void setup(){
    gameover =false;
    dir=Stop;
    x=width/2;
    y=hight/2;
    fx=rand()%width;
    fy=rand()%hight;
    scor=0;
}

void draw(){
    system("cls");
    for(int i=0;i<width+2;i++)  //for top part of border
    {cout<<"#";}
    cout<<endl;

    for(int i=0;i<hight;i++){

        for(int j=0;j<width;j++) //for left and right part
        {
            if(j==0) cout<<"#";

            if(i==y && j==x) cout<<"O";

            else if (i == fy && j == fx)
                cout << "F";

            else {//for tail part to print 
                    bool print =false;
                    for(int k=0;k<ntail;k++)
                    {
                        if(tailX[k]==j && tailY[k]==i)
                       { cout<<"*";
                         print=true;}
                    }
                if(!print)
                cout<<" ";}

            if(j==width-1) cout<<"#";
        }
        cout<<endl;
    }

    for(int i=0;i<width+2;i++)  //for bottem part of border
    {cout<<"#";}
   cout<<endl<<"the score is: "<<scor;
}

void input(){
    if(_kbhit()) //check if hit any key if yes then give +ve 
    {
        switch (_getch())
        {
        case 'w':
            dir=up;
            break;
        case 's':
            dir=down;
            break;
        case 'a':
            dir=Left;
            break;
        case 'd':
            dir=Right;
            break;
        case 'x':
            gameover=true;
            break;
        default:
            break;
        }

    }
}

void logic(){

    //for tail to fallow
    tailX[0] = x;
    tailY[0] = y;
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    for (int i = 1; i < ntail; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
        switch (dir)
        {
        case up:
            y--;
            break;
        case down:
            y++;
            break;
        case Left:
            x--;
            break;
        case Right:
            x++;
            break;
        default:
            break;
        }

    // if(x<0||x>width||y<0||y>hight) //for ending when hit border.
    // gameover=true;

    if(x>=width) x=0; else if(x==0) x=width-1;
    if(y>=hight) y=0; else if(y==-1) y=hight-1; 

    for(int i=0;i<ntail;i++)      // for when hit tail.
        if(tailX[i]==x && tailY[i]==y)
            gameover=true;

    if(x==fx && y==fy)
    {       // for inc sror and replacing f
        scor++;
        fx=rand()%width;
        fy=rand()%hight;
        ntail++;
    }

}

int main(){

    setup();
         while(!gameover)
        {
            draw();
            input();
            logic();
            Sleep(50);
        }

}