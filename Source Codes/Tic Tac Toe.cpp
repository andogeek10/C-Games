#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
using namespace std;
char grid[3][3];
int row,column,win=0,check_grid=0,values=0;
struct Players
{
    char name[40];
}player1,player2;
void welcome()
{
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"\t\tWelcome to Tic Tac Toe.You will be"<<endl;
    cout<<"\t\tpresented with a grid of 3 rows"<<endl;
    cout<<"\t\tand 3 columns. There are 2 players."<<endl;
    cout<<"\t\tOne uses the character X, while other uses the"<<endl;
    cout<<"\t\tcharacter O. The first one to fill a row/"<<endl;
    cout<<"\t\tcolumn/diagonal wins the game."<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t- Anmol Chawla"<<endl;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    system("pause");
}
void players()
{
    int exit;
    system("cls");
    cout<<"Player 1, enter your name :";
    cin>>player1.name;
    cout<<"Player 2, enter your name :";
    cin>>player2.name;
        do{
                if (strcmp(player2.name,player1.name)==0)
                {
                    cout<<"Both the players cannot have the same name."<<endl<<"Enter you name player 2 :";
                    cin>>player2.name;
                }
                else
                    exit=0;
          }while(exit!=0);
}
void star()
{
    for (int i=0;i<3;++i)           //This function assigns numbers to the array 'grid'.
    {
        for (int j=0;j<3;++j)
        {
            grid[i][j]=values++;
        }
    }
}
void display()
{
    system("cls");
    for (int i=0;i<3;++i)
    {
        cout<<"\n\n";
        for (int j=0;j<3;++j)
        {
            if (grid[i][j]=='X'||grid[i][j]=='O')
                cout<<"\t"<<grid[i][j];
            else
                cout<<"\t"<<"*";
        }
    }
}
void o(int row, int column)
{
    int check=0;
    row--;
    column--;
    do {
         if (row>2||column>2)
         {
           cout<<"The entered value is greater than the number of row/column."<<endl<<"Please choose again :"<<endl;
           cout<<"Row :";
           cin>>row;
           cout<<"Column :";
           cin>>column;
           row--;
           column--;
        }
        else
           check=1;
        } while (check==0);
    do {
         if (grid[row][column]=='X'||grid[row][column]=='O')
         {
           cout<<"This field has already been filled"<<endl<<"Please choose again :"<<endl;
           cout<<"Row :";
           cin>>row;
           cout<<"Column :";
           cin>>column;
           row--;
           column--;
        }
        else
           check=0;
        } while (check==1);
    grid[row][column]='O';
}
void x(int row, int column)
{
    int check=0;
    row--;
    column--;
    do {
         if (row>2||column>2)
         {
           cout<<"The entered value is greater than the number of row/column."<<endl<<"Please choose again :"<<endl;
           cout<<"Row :";
           cin>>row;
           cout<<"Column :";
           cin>>column;
           row--;
           column--;
        }
        else
           check=1;
        } while (check==0);
    do {
         if (grid[row][column]=='X'||grid[row][column]=='O')
         {
           cout<<"This field has already been filled"<<endl<<"Please choose again :"<<endl;
           cout<<"Row :";
           cin>>row;
           cout<<"Column :";
           cin>>column;
           row--;
           column--;
        }
        else
           check=0;
       } while (check==1);
    grid[row][column]='X';
}
void check()
{
    for (int i=0;i<3;++i)                                                                                   //This function checks
    {                                                                                                       //for all the possible
                                                                                                            //winning conditions.
            if (grid[i][0]==grid[i][1]&&grid[i][1]==grid[i][2])
            {
                win++;
                break;
            }
            if (grid[0][i]==grid[1][i]&&grid[1][i]==grid[2][i])
            {
               win++;
               break;
            }
    }
    if (grid[0][0]==grid[1][1]&&grid[1][1]==grid[2][2]||grid[0][2]==grid[1][1]&&grid[1][1]==grid[2][0])
           {
             win++;
           }
    else
        {
            check_grid=0;
            for (int i=0;i<3;++i)
            {
                for (int j=0;j<3;++j)
                {
                    if (grid[i][j]=='X'||grid[i][j]=='O')
                    check_grid++;
                }
            }
        }
}
void game_player()
{
    char retry;
    do{
            star();
            do{
                display();
                cout<<endl<<player1.name<<", its your turn.";
                cout<<"\nRow :";
                cin>>row;
                cout<<"Column :";
                cin>>column;
                o(row,column);
                check();
                if (win>0)
                {
                    display();
                    cout<<endl<<player1.name<<" wins.";
                    break;
                }
                if (check_grid==9)
                    break;
                display();
                cout<<endl<<player2.name<<", its your turn.";
                cout<<"\nRow :";
                cin>>row;
                cout<<"Column :";
                cin>>column;
                x(row,column);
                check();
                if (win>0)
                {
                    display();
                    cout<<endl<<player2.name<<" wins.";
                    break;
                }
              }while (check_grid<9);
            if (check_grid==9)
            {
                display();
                cout<<"\nDraw";
            }
            cout<<"\nDo you want to continue (Y or N)?";
            cin>>retry;
            win=0;
     }while (retry=='Y'||retry=='y');
}
int main()
{
    welcome();
    players();
    cout<<"Commencing the battle.....";
    for(int i=0;i<100000000;++i);
    game_player();
    cout<<endl<<endl<<"Thank you for playing this game.";
    return 0;
}
