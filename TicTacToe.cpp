#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <windows.h>
using namespace std;

static int Board[3][3],score1=0,score2=0;
const int player1=50,player2=100;
static int Result=0;
char Out_Board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
string pl1,pl2;

// Initialization and Welcome design FUNCTION //

int initialize()
{
    int i,j,counter=0;
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            ++counter;
            Board[i][j]=counter;
        }
    }
    cout<<"\t\t\tPRESS ENTER TO PLAY TIC_TAC_TOE ;)\t\t\t\n";
    cout.width(29);
    cout.fill(' ');
    cout<<"";
    cout.width(24);
    cout.fill('#');
    cout<<"\n";
    for(i=0; i<3; i++)
    {
        cout.width(30);
        cout.fill(' ');
        cout<<"#";
        if(i==1)
        {
            cout.width(14);
            cout.fill(' ');
            cout<<"WELCOME";
            cout.width(9);
        }
        else
        {
            cout.width(23);
        }
        cout.fill(' ');
        cout<<"#\n";
    }
    cout.width(29);
    cout.fill(' ');
    cout<<"";
    cout.width(24);
    cout.fill('#');
    cout<<"\n";
    if(cin.get()=='\n')
    {
        system("CLS");
        return 0;
    }
}

// OUTPUT LOGIC WHICH USER CAN SEE //

void board_logic()
{

    cout<<"\t\t\t"<<pl1<<"'s SCORE : "<<score1<<"\t\t\t"<<endl<<endl;
    cout<<"\t\t\t"<<pl2<<"'s SCORE : "<<score2<<"\t\t\t"<<endl<<endl;
    cout << "     |     |     " << endl;
	cout << "  " << Out_Board[0][0] << "  |  " << Out_Board[0][1] << "  |  " << Out_Board[0][2] << endl;
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << Out_Board[1][0] << "  |  " << Out_Board[1][1] << "  |  " << Out_Board[1][2] << endl;
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << Out_Board[2][0] << "  |  " << Out_Board[2][1] << "  |  " << Out_Board[2][2] << endl;
	cout << "     |     |     " << endl << endl;
}

// INPUT LOGIC WHICH USER CAN'T SEE //

int arr_logic(int n,const int khiladi,int check)
{
    int i,j;
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            if(Board[i][j]==n)
            {
                Board[i][j]=khiladi;
            }
        }
    }
    if(check>=5)
    {
        if(((Board[0][0]==Board[0][1])&&(Board[0][1]==Board[0][2]))&&(Board[0][0]==khiladi))
            return khiladi;
        else if(((Board[1][0]==Board[1][1])&&(Board[1][1]==Board[1][2]))&&(Board[1][0]==khiladi))
            return khiladi;
        else if(((Board[2][0]==Board[2][1])&&(Board[2][1]==Board[2][2]))&&(Board[2][0]==khiladi))
            return khiladi;
        else if(((Board[0][0]==Board[1][0])&&(Board[1][0]==Board[2][0]))&&(Board[0][0]==khiladi))
            return khiladi;
        else if(((Board[0][1]==Board[1][1])&&(Board[1][1]==Board[2][1]))&&(Board[0][1]==khiladi))
            return khiladi;
        else if(((Board[0][2]==Board[1][2])&&(Board[1][2]==Board[2][2]))&&(Board[0][2]==khiladi))
            return khiladi;
        else if(((Board[0][0]==Board[1][1])&&(Board[1][1]==Board[2][2]))&&(Board[0][0]==khiladi))
            return khiladi;
        else if(((Board[0][2]==Board[1][1])&&(Board[1][1]==Board[2][0]))&&(Board[0][2]==khiladi))
            return khiladi;
        else
            return 0;
    }
    else
        return 0;
}

// Reset values for next use //

void reset()
{
    int i,j,counter=0;
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            ++counter;
            Board[i][j]=counter;
        }
    }
    Out_Board[0][0]='1';
    Out_Board[0][1]='2';
    Out_Board[0][2]='3';
    Out_Board[1][0]='4';
    Out_Board[1][1]='5';
    Out_Board[1][2]='6';
    Out_Board[2][0]='7';
    Out_Board[2][1]='8';
    Out_Board[2][2]='9';
}

int main()
{
    int i=0,n,flag=0,ins=0;
    system("color 5E");
    char ch;
    initialize();
    cout<<"NAME OF FIRST PLAYER : ";
    cin>>pl1;
    cout<<"\n\nNAME OF SECOUND PLAYER : ";
    cin>>pl2;
    do {
    system("CLS");
    i=0;
    cout<<"PLAYER 1("<<pl1<<") --> X";
    cout<<"\n\nPLAYER 2("<<pl2<<") --> O\n\n";
    board_logic();
    while(true)
    {
        ++i;
        top:
        if((i>9)&&(Result==0))
        {
            system("CLS");
            cout<<"\nCONGRATULATION YOU BOTH ARE GENIUS.....\n\n\tTHIS IS A DRAW :(\n\n\n\n";
            board_logic();
            goto down;
        }
        flag=0;
        if(i%2!=0)
        {
            cout<<"\n\nPLAYER 1("<<pl1<<") --> IT'S YOUR TURN\n\n";
            flag=1;
        }
        else
        {
            cout<<"\n\nPLAYER 2("<<pl2<<") --> IT'S YOUR TURN\n\n";
            flag=0;
        }
        J:
        cin>>n;
        if(n==ins)
        {
            goto J;
        }
        ins=n;
        switch(n)
        {
            case 1:
                if(flag==1)
                {
                    system("CLS");
                    Out_Board[0][0]='X';
                    board_logic();
                    Result=arr_logic(n,player1,i);
                    if(Result==50)
                    {
                        score1+=1;
                        system("CLS");
                        cout<<"\n\nCONGRATULATIONS < "<<pl1<<" > WON THIS GAME\n\n";
                        cout<<"YOUR SCORE : "<<score1<<"\n\n";
                        board_logic();
                        goto down;
                    }
                }
                else
                {
                    system("CLS");
                    Out_Board[0][0]='O';
                    board_logic();
                    Result=arr_logic(n,player2,i);
                    if(Result==100)
                    {
                        score2+=1;
                        system("CLS");
                        cout<<"\n\nCONGRATULATIONS < "<<pl2<<" > WON THIS GAME\n\n";
                        cout<<"YOUR SCORE : "<<score2<<endl;
                        board_logic();
                        goto down;
                    }
                }
                break;
            case 2:
                if(flag==1)
                {
                    system("CLS");
                    Out_Board[0][1]='X';
                    board_logic();
                    Result=arr_logic(n,player1,i);
                    if(Result==50)
                    {
                        score1+=1;
                        system("CLS");
                        cout<<"\n\nCONGRATULATIONS < "<<pl1<<" > WON THIS GAME\n\n";
                        cout<<"YOUR SCORE : "<<score1<<"\n\n";
                        board_logic();
                        goto down;
                    }
                }
                else
                {
                    system("CLS");
                    Out_Board[0][1]='O';
                    board_logic();
                    Result=arr_logic(n,player2,i);
                    if(Result==100)
                    {
                        score2+=1;
                        system("CLS");
                        cout<<"\n\nCONGRATULATIONS < "<<pl2<<" > WON THIS GAME\n\n";
                        cout<<"YOUR SCORE : "<<score2<<endl;
                        board_logic();
                        goto down;
                    }
                }
                break;
            case 3:
                if(flag==1)
                {
                    system("CLS");
                    Out_Board[0][2]='X';
                    board_logic();
                    Result=arr_logic(n,player1,i);
                    if(Result==50)
                    {
                        score1+=1;
                        system("CLS");
                        cout<<"\n\nCONGRATULATIONS < "<<pl1<<" > WON THIS GAME\n\n";
                        cout<<"YOUR SCORE : "<<score1<<"\n\n";
                        board_logic();
                        goto down;
                    }
                }
                else
                {
                    system("CLS");
                    Out_Board[0][2]='O';
                    board_logic();
                    Result=arr_logic(n,player2,i);
                    if(Result==100)
                    {
                        score2+=1;
                        system("CLS");
                        cout<<"\n\nCONGRATULATIONS < "<<pl2<<" > WON THIS GAME\n\n";
                        cout<<"YOUR SCORE : "<<score2<<endl;
                        board_logic();
                        goto down;
                    }
                }
                break;
            case 4:
                if(flag==1)
                {
                    system("CLS");
                    Out_Board[1][0]='X';
                    board_logic();
                    Result=arr_logic(n,player1,i);
                    if(Result==50)
                    {
                        score1+=1;
                        system("CLS");
                        cout<<"\n\nCONGRATULATIONS < "<<pl1<<" > WON THIS GAME\n\n";
                        cout<<"YOUR SCORE : "<<score1<<"\n\n";
                        board_logic();
                        goto down;
                    }
                }
                else
                {
                    system("CLS");
                    Out_Board[1][0]='O';
                    board_logic();
                    Result=arr_logic(n,player2,i);
                    if(Result==100)
                    {
                        score2+=1;
                        system("CLS");
                        cout<<"\n\nCONGRATULATIONS < "<<pl2<<" > WON THIS GAME\n\n";
                        cout<<"YOUR SCORE : "<<score2<<endl;
                        board_logic();
                        goto down;
                    }
                }
                break;
            case 5:
                if(flag==1)
                {
                    system("CLS");
                    Out_Board[1][1]='X';
                    board_logic();
                    Result=arr_logic(n,player1,i);
                    if(Result==50)
                    {
                        score1+=1;
                        system("CLS");
                        cout<<"\n\nCONGRATULATIONS < "<<pl1<<" > WON THIS GAME\n\n";
                        cout<<"YOUR SCORE : "<<score1<<"\n\n";
                        board_logic();
                        goto down;
                    }
                }
                else
                {
                    system("CLS");
                    Out_Board[1][1]='O';
                    board_logic();
                    Result=arr_logic(n,player2,i);
                    if(Result==100)
                    {
                        score2+=1;
                        system("CLS");
                        cout<<"\n\nCONGRATULATIONS < "<<pl2<<" > WON THIS GAME\n\n";
                        cout<<"YOUR SCORE : "<<score2<<endl;
                        board_logic();
                        goto down;
                    }
                }
                break;
            case 6:
                if(flag==1)
                {
                    system("CLS");
                    Out_Board[1][2]='X';
                    board_logic();
                    Result=arr_logic(n,player1,i);
                    if(Result==50)
                    {
                        system("CLS");
                        score1+=1;
                        cout<<"\n\nCONGRATULATIONS < "<<pl1<<" > WON THIS GAME\n\n";
                        cout<<"YOUR SCORE : "<<score1<<"\n\n";
                        board_logic();
                        goto down;
                    }
                }
                else
                {
                    system("CLS");
                    Out_Board[1][2]='O';
                    board_logic();
                    Result=arr_logic(n,player2,i);
                    if(Result==100)
                    {
                        score2+=1;
                        system("CLS");
                        cout<<"\n\nCONGRATULATIONS < "<<pl2<<" > WON THIS GAME\n\n";
                        cout<<"YOUR SCORE : "<<score2<<endl;
                        board_logic();
                        goto down;
                    }
                }
                break;
            case 7:
                if(flag==1)
                {
                    system("CLS");
                    Out_Board[2][0]='X';
                    board_logic();
                    Result=arr_logic(n,player1,i);
                    if(Result==50)
                    {
                        score1+=1;
                        system("CLS");
                        cout<<"\n\nCONGRATULATIONS < "<<pl1<<" > WON THIS GAME\n\n";
                        cout<<"YOUR SCORE : "<<score1<<"\n\n";
                        board_logic();
                        goto down;
                    }
                }
                else
                {
                    system("CLS");
                    Out_Board[2][0]='O';
                    board_logic();
                    Result=arr_logic(n,player2,i);
                    if(Result==100)
                    {
                        score2+=1;
                        system("CLS");
                        cout<<"\n\nCONGRATULATIONS < "<<pl2<<" > WON THIS GAME\n\n";
                        cout<<"YOUR SCORE : "<<score2<<endl;
                        board_logic();
                        goto down;
                    }
                }
                break;
            case 8:
                if(flag==1)
                {
                    system("CLS");
                    Out_Board[2][1]='X';
                    board_logic();
                    Result=arr_logic(n,player1,i);
                    if(Result==50)
                    {
                        score1+=1;
                        system("CLS");
                        cout<<"\n\nCONGRATULATIONS < "<<pl1<<" > WON THIS GAME\n\n";
                        cout<<"YOUR SCORE : "<<score1<<"\n\n";
                        board_logic();
                        goto down;
                    }
                }
                else
                {
                    system("CLS");
                    Out_Board[2][1]='O';
                    board_logic();
                    Result=arr_logic(n,player2,i);
                    if(Result==100)
                    {
                        score2+=1;
                        system("CLS");
                        cout<<"\n\nCONGRATULATIONS < "<<pl2<<" > WON THIS GAME\n\n";
                        cout<<"YOUR SCORE : "<<score2<<endl;
                        board_logic();
                        goto down;
                    }
                }
                break;
            case 9:
                if(flag==1)
                {
                    system("CLS");
                    Out_Board[2][2]='X';
                    board_logic();
                    Result=arr_logic(n,player1,i);
                    if(Result==50)
                    {
                        score1+=1;
                        system("CLS");
                        cout<<"\n\nCONGRATULATIONS < "<<pl1<<" > WON THIS GAME\n\n";
                        cout<<"YOUR SCORE : "<<score1<<"\n\n";
                        board_logic();
                        goto down;
                    }
                }
                else
                {
                    system("CLS");
                    Out_Board[2][2]='O';
                    board_logic();
                    Result=arr_logic(n,player2,i);
                    if(Result==100)
                    {
                        score2+=1;
                        system("CLS");
                        cout<<"\n\nCONGRATULATIONS < "<<pl2<<" > WON THIS GAME\n\n";
                        cout<<"YOUR SCORE : "<<score2<<endl;
                        board_logic();
                        goto down;
                    }
                }
                break;
            default:
                cout<<"\n\nWRONG CHOICE ENTERED :(";
                goto top;
        }
    }
    down:
    cout<<"\n\nDO YOU WANT TO CONTINUE THIS RIVALRY <Y/N>\n\n--> ";
    cin>>ch;
    if((ch=='y')||(ch=='Y'))
    {
        i=0;
        reset();
    }
    else
    {
        exit(0);
    }
    }while((ch=='y')||(ch=='Y'));

    return 0;
}
