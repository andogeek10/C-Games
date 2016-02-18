#include <iostream>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
using namespace std;
char letter[10][10],user_input;
int choice,row,column,rand_row,rand_column;
void welcome()
{
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"\t\tWelcome to the Memory Game. The rules"<<endl;
    cout<<"\t\tare simple. You will be presented with"<<endl;
    cout<<"\t\ta grid of letters and in the next screen"<<endl;
    cout<<"\t\tyou will be presented a grid with one "<<endl;
    cout<<"\t\tmissing character. You will need to input"<<endl;
    cout<<"\t\tthat character."<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t- Anmol Chawla"<<endl;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;

}
void menu()
{
    cout<<"Choose the difficulty :"<<endl;                          //This function shows the user the choices of grids he has.
    cout<<"1.Easy (2x2)"<<endl;
    cout<<"2.Normal (3x3)"<<endl;
    cout<<"3.Hard (4x4)"<<endl;
    cout<<"4.Very Hard (5x5)"<<endl;
    cout<<"Enter the the number corresponding to your choice :";
}
void generator()
{
    for (int i=0;i<row;++i)                                  //This function randomly assigns the ASCII code to the array 'letter'.
            {
                for (int j=0;j<column;++j)
                {
                    letter[i][j]=((rand()%26)+65);
                }
            }
}
void display()
{
    for (int i=0;i<row;++i)                                 //This function displays the array 'letter'.
            {
                cout<<"\n\n";
                for (int j=0;j<column;++j)
                {
                    cout<<"\t"<<letter[i][j];
                }
            }
}
void display_with_blank()
{
    for (int i=0;i<row;++i)                                 //This function displays the array 'letter' and leaves a randomly
            {                                               //chosen spot blank.
                cout<<"\n\n";
                for (int j=0;j<column;++j)
                {
                    if (i==rand_row&&j==rand_column)
                    {
                        cout<<"\t";
                    }
                    else
                        cout<<"\t"<<letter[i][j];
                }
            }
}
void check()
{
    cout<<"\n\nEnter the letter which you think is missing :";                                      //This function takes in the user's
            cin>>user_input;                                                                        //guess and checks if it is  correct
            user_input=toupper(user_input);                                                         //or not.
            if (user_input==letter[rand_row][rand_column])
            {
                cout<<"\nCongratulations you guessed it correctly!!";
            }
            else
                cout<<"\nWrong letter. The correct letter is :"<<letter[rand_row][rand_column];
}
int main()
{
    welcome();
    cout<<"Press any key to continue......"<<endl;
    getch();
    do {
            X:
            system("cls");
            menu();
            cin>>choice;
            switch(choice)
            {
                case 1 : row=column=2;
                         break;
                case 2 : row=column=3;
                         break;
                case 3 : row=column=4;
                         break;
                case 4 : row=column=5;
                         break;
                case 5 : cout<<"Kid mode activated";
                         row=column=1;
                         break;
               default : cout<<"You have entered a wrong choice"<<endl;
                         system("pause");
                         goto X;
                         break;
            }
            srand(time(NULL));
            generator();
            display();
            cout<<"\n\n";
            cout<<"When you are ready, press enter......";
            getch();
            system("cls");
            rand_row=(rand()%row);
            rand_column=(rand()%column);
            display_with_blank();
            check();
            cout<<"\n\nDo you want to play again (Y or N)?";
            cin>>user_input;
       } while (user_input=='y'||user_input=='Y');
    cout<<"\nThank you for playing this game."<<endl;
    return 0;
}
