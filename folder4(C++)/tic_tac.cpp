#include<iostream>
using namespace std;

char matrix[3][3]={'1','2','3','4','5','6','7','8','9'};
char play='X';

void mat(){
    system("cls");//it clear the terminal.
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<matrix[i][j]<<"|";
        } 
        cout<<endl<<"_|_|_|"<<endl;
        }
}

void Input(){
    int a; 
    cout<<"enter the no. to replace with "<<play<<" :";
    cin>>a;

    switch (a)
    {
    case(1):
    if(matrix[0][0]=='1'){matrix[0][0]=play;}
    else {cout<<"place is already used,other player turn"<<endl;
    Input();}
        break;
    case(2):
    if(matrix[0][1]=='2'){matrix[0][2]=play;}
    else {cout<<"place is already used,other player turn"<<endl;
    Input();}
        break;
    case(3):
    if(matrix[0][2]=='3'){matrix[0][2]=play;}
    else{cout<<"place is already used,other player turn"<<endl;
        Input();}
        break;
    case(4):
    if(matrix[1][0]=='4'){matrix[1][0]=play;}
    else{cout<<"place is already used,other player turn"<<endl;
        Input();}   
        break;
    case(5):
    if(matrix[1][1]=='5'){matrix[1][1]=play;}
    else {cout<<"place is already used,other player turn"<<endl;
    Input();}
        break;
        case(6):
     if(matrix[1][2]=='6'){matrix[1][2]=play;}
    else {cout<<"place is already used,other player turn"<<endl;
    Input();}
        break;
        case(7):
     if(matrix[2][0]=='7'){matrix[2][0]=play;}
    else {cout<<"place is already used,other player turn"<<endl;
    Input();}
        break;
    case(8):
    if(matrix[2][1]=='8'){matrix[2][1]=play;}
    else {cout<<"place is already used,other player turn"<<endl;
    Input();}
        break;
    case(9):
    if(matrix[2][2]=='9'){matrix[2][2]=play;}
    else {cout<<"place is already used,other player turn"<<endl;
    Input();}
        break;
    default:
        break;
    } 
}

void otherplay(){
    if(play=='X') play='O';
    else play ='X';
}

char win(){
    /* 00 01 02
       10 11 12
       20 21 22  */
     if( matrix[0][0]=='X' && matrix[0][1]=='X' && matrix[0][2]=='X')
    { return 'X';}
     if( matrix[1][0]=='X' && matrix[1][1]=='X' && matrix[1][2]=='X')
    { return 'X';}
     if( matrix[2][0]=='X' && matrix[2][1]=='X' && matrix[2][2]=='X')
    { return 'X';}
     if( matrix[0][0]=='X' && matrix[1][0]=='X' && matrix[2][0]=='X')
    { return 'X';}
     if( matrix[0][1]=='X' && matrix[1][1]=='X' && matrix[2][1]=='X')
    { return 'X';}
     if( matrix[0][2]=='X' && matrix[1][2]=='X' && matrix[2][2]=='X')
    { return 'X';}
     if( matrix[0][0]=='X' && matrix[1][1]=='X' && matrix[2][2]=='X')
    { return 'X';}
     if( matrix[2][0]=='X' && matrix[1][1]=='X' && matrix[0][2]=='X')
    { return 'X';}

     if( matrix[0][0]=='O' && matrix[0][1]=='O' && matrix[0][2]=='O')
    { return 'O';}
     if( matrix[1][0]=='O' && matrix[1][1]=='O' && matrix[1][2]=='O')
    { return 'O';}
     if( matrix[2][0]=='O' && matrix[2][1]=='O' && matrix[2][2]=='O')
    { return 'O';}
     if( matrix[0][0]=='O' && matrix[1][0]=='O' && matrix[2][0]=='O')
    { return 'O';}
     if( matrix[0][1]=='O' && matrix[1][1]=='O' && matrix[2][1]=='O')
    { return 'O';}
     if( matrix[0][2]=='O' && matrix[1][2]=='O' && matrix[2][2]=='O')
    { return 'O';}
     if( matrix[0][0]=='O' && matrix[1][1]=='O' && matrix[2][2]=='O')
    { return 'O';}
     if( matrix[2][0]=='O' && matrix[1][1]=='O' && matrix[0][2]=='O')
    { return 'O';}

    else {return '?';}

}

int main(){
    int w=1;
    mat();
    while(w<=9){
        w++;
    Input();
    mat();
    if(win()=='X')
    {cout<<"X Wins!";
    break;}
    else if(win()=='O')
    {cout<<"O Wins!";
    break;}
    else if(win()=='?' && w==9)
    {cout<<"It's a draw";
    break;}

    otherplay();
    }
    
    return 0;
}