#include <iostream>
#include <ctype.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
using namespace std;
char letter[10][10];
int grid[10][10],assignment_integer=100,f=0;
struct Players
{
    char name[100];
    int pos;
}p1,p2;
void welcome()
{
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"\t\tWelcome to Snakes and Ladders. The rules"<<endl;
    cout<<"\t\tare simple. You will be presented with a board"<<endl;
    cout<<"\t\twith numbers upto 100. After entering the player names"<<endl;
    cout<<"\t\tthe dice will be rolled and the players while evading the"<<endl;
    cout<<"\t\tsnakes (green) and climbing the ladders(red) will"<<endl;
    cout<<"\t\tattempt to be the first one to reach 100."<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t- Anmol Chawla"<<endl;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    system("pause");
}
void board_numbers()
{
    for (int i=0;i<10;++i)                          //This function assigns numbers from 100-1 to the array 'grid'.
    {
        for (int j=0;j<10;++j)
            {
                grid[i][j]=assignment_integer;
                assignment_integer--;
            }
    }
}
void board_letters()
{
    letter[0][1]='R';       //This function contains the assignments to various array objects in the array 'letter'.
    letter[0][2]='S';
    letter[0][4]='S';
    letter[1][2]='E';
    letter[1][3]='N';
    letter[2][2]='A';
    letter[2][3]='D';
    letter[2][4]='A';
    letter[3][1]='K';
    letter[3][4]='D';
    letter[3][5]='K';
    letter[4][0]='E';
    letter[4][3]='R';
    letter[4][5]='A';
    letter[4][6]='E';
    letter[4][9]='R';
    letter[5][3]='S';
    letter[5][4]='E';
    letter[5][5]='S';
    letter[5][6]='L';
    letter[5][8]='E';
    letter[6][4]='N';
    letter[6][5]='D';
    letter[6][7]='D';
    letter[7][3]='A';
    letter[7][5]='A';
    letter[7][6]='D';
    letter[8][2]='K';
    letter[8][5]='A';
    letter[8][6]='K';
    letter[8][7]='A';
    letter[9][1]='E';
    letter[9][4]='L';
    letter[9][7]='E';
    letter[9][8]='L';
}
void board_display()
{
    cout<<"\t\t\t Snakes & Ladders"<<endl;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;    //This function displays the
    for (int i=0;i<10;++i)                                                                             //board of the game by
    {                                                                                                  //displaying the numbers
        cout<<"\n\n";                                                                                  //or characters for the
        for (int j=0;j<10;++j)                                                                         //ladder or snake.
            {
                if (isalpha(letter[i][j]))
                {
                    if (grid[i][j]==99)
                      {
                          cout<<"    ";
                          SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xE4 );
                          cout<<letter[i][j];
                      }
                    else
                      {
                          SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x07 );
                          cout<<"     ";
                          if(letter[i][j]=='S'||letter[i][j]=='N'||letter[i][j]=='A'||letter[i][j]=='K'||letter[i][j]=='E')
                          {
                               SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xA1 );
                               cout<<letter[i][j];
                          }
                          else
                          {
                             SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xE4 );
                             cout<<letter[i][j];
                          }
                    }
                }
                else
                {
                    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x07 );
                    if (grid[i][j]<10)
                      cout<<" ";
                     cout<<"    "<<grid[i][j];
                    if (i==1&&j==9)
                        cout<<"\t"<<"Player Pos. :";
                    if (i==3&&j==9)
                        cout<<"\t"<<p1.name<<" - "<<p1.pos;
                    if (i==5&&j==9)
                        cout<<"\t"<<p2.name<<" - "<<p2.pos;
                }
            }
    }
}
void game_input()
{
        int exit;                                   //This function is used to take in the names of the players.
        system("cls");
        cout<<endl<<"Enter you name player 1 :";
        cin>>p1.name;
        cout<<endl<<"Enter you name player 2 :";
        cin>>p2.name;
        do{
                if (strcmp(p2.name,p1.name)==0)
                {
                    cout<<"Both the players cannot have the same name."<<endl<<"Enter you name player 2 :";
                    cin>>p2.name;
                }
                else
                    exit=0;
          }while(exit!=0);
}
void game_check(int &pos)
{
    if (pos==2)                                                                 //This function is used to check if the user has
    {                                                                           //climbed on a ladder or a snake and modify the
        cout<<endl<<"You just stepped on a ladder and climbed upto 57"<<endl;   //position accordingly.
        pos=57;
        system("pause");
    }
    else
        if (pos==6)
        {
            cout<<endl<<"You just stepped on a ladder and climbed upto 51"<<endl;
            pos=51;
            system("pause");
        }
    else
        if (pos==44)
        {
            cout<<endl<<"You just stepped on a ladder and climbed upto 99"<<endl;
            pos=99;
            system("pause");
        }
    else
        if (pos==47)
        {
            cout<<endl<<"You just stepped on a snake and slipped down to 3"<<endl;
            pos=3;
            system("pause");
        }
    else
        if (pos==45)
        {
            cout<<endl<<"You just stepped on a snake and slipped down to 9"<<endl;
            pos=9;
            system("pause");
        }
    else
        if (pos==98)
        {
            cout<<endl<<"You just stepped on a snake and slipped down to 54"<<endl;
            pos=54;
            system("pause");
        }
    else
        if (pos==95)
        {
            cout<<endl<<"You just stepped on a snake and slipped down to 60"<<endl;
            pos=60;
            system("pause");
        }
}
void game_dice(int &pos)
{
    srand(time(NULL));          //This function is used as dice i.e it generates random numbers between 1 to 6
    f=(rand()%6)+1;             //and increments the position accordingly. It also invokes the game_check function.
    cout<<endl<<"Dice : "<<f;
    getch();
    if (pos+f>100)
    {
        cout<<endl<<"Value exceeds the limit";
        getch();
    }
    else
    pos+=f;
    game_check(pos);
}
void game()
{
    do                                                                          //This function contains a do-while loop
        {                                                                       //which runs till the time one of the player
            system("cls");                                                      //doesn't reach 100.
            board_display();
            cout<<endl<<p1.name<<", press enter to roll the dice ....";
            getch();
            game_dice(p1.pos);
            if (p1.pos==100)
            {
                cout<<endl<<"Congratulations, "<<p1.name<<" you have won.";
                break;
            }
            cout<<endl<<p2.name<<", press enter to roll the dice ....";
            getch();
            game_dice(p2.pos);
            if (p2.pos==100)
            {
                cout<<endl<<"Congratulations, "<<p2.name<<" you have won.";
            }
        }while (p2.pos<100);
}
int main()
{
    welcome();
    char check1,check2;
    board_numbers();
    board_letters();
    game_input();
    do
    {
        p1.pos=0;
        p2.pos=0;
        game();
        cout<<endl<<"Do you want to play again(Y or N)?";
        cin>>check1;
        if (check1=='y'||check1=='Y')
        {
            cout<<"Do want to change your names(Y or N)?";
            cin>>check2;
            if (check2=='y'||check2=='Y')
            {
                game_input();
            }
        }
    }while(check1=='y'||check1=='Y');
    cout<<endl<<"Thanks You for playing this game.Hope you enjoyed.";
    return 0;
}
