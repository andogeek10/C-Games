#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
using namespace std;
void loading()
{
        cout<<endl<<"Loading"<<endl;            //This function is used to display the loading screen.
        for (int i=0;i<80;++i)
        {
            for (int j=0;j<10000000;++j);
            cout<<"_";
        }
}
void show()
{
        system("cls");
        cout<<endl<<endl<<endl<<endl;
        cout<<"\t\t     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
        cout<<"\t\t     ~                                     ~"<<endl;
        cout<<"\t\t     ~                                     ~"<<endl;
        cout<<"\t\t     ~      Computer Science Project       ~"<<endl;
        cout<<"\t\t     ~      Made By : Anmol Chawla         ~"<<endl;
        cout<<"\t\t     ~      Class : XI-A                   ~"<<endl;
        cout<<"\t\t     ~      Roll No. : 05                  ~"<<endl;
        cout<<"\t\t     ~                                     ~"<<endl;
        cout<<"\t\t     ~                                     ~"<<endl;
        cout<<"\t\t     ~                                     ~"<<endl;
        cout<<"\t\t     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
        loading();
}
void welcome()
{
    system("cls");
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"\t\t\tFrom here you'll be able to choose"<<endl;
    cout<<"\t\t\twhich game you want to play"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t- Anmol Chawla"<<endl;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"Press any key to continue......"<<endl;
    getch();
}
void menu()
{
    cout<<"\n\nChoose a game :"<<endl;
    cout<<"1.Memory Game"<<endl;
    cout<<"2.Hangman"<<endl;
    cout<<"3.Tic Tac Toe"<<endl;
    cout<<"4.Snakes and Ladders"<<endl;
    cout<<"Enter the the number corresponding to your choice :";
}
void open()
{
    int a;                                                                                                    //This function uses the
    X:                                                                                                        //ShellExecute() command
            system("cls");                                                                                    //to start a new process
            menu();                                                                                           //by invoking the respective
            cin>>a;                                                                                           // executable file.
            switch (a)
            {
                case 1 : system("cls");
                         loading();
                         ShellExecute( NULL, "open", "res\\Memory Game.exe", NULL, NULL, SW_MAXIMIZE );
                         break;
                case 2 : system("cls");
                         loading();
                         ShellExecute( NULL, "open", "res\\Hangman.exe", NULL, NULL, SW_MAXIMIZE );
                         break;
                case 3 : system("cls");
                         loading();
                         ShellExecute( NULL, "open", "res\\Tic Tac Toe.exe", NULL, NULL, SW_MAXIMIZE );
                         break;
                case 4 : system("cls");
                         loading();
                         ShellExecute( NULL, "open", "res\\Snakes and Ladder.exe", NULL, NULL, SW_MAXIMIZE );
                         break;
               default : cout<<"A wrong choice has been entered"<<endl;
                         system("pause");
                         goto X;
                         break;
            }
}
int main()
{
    char b;
    show();
    welcome();
    do {
            open();
            cout<<"\n\nDo you want to play another game (Y or N)?";
            cin>>b;
       } while (b=='y'||b=='Y');
    cout<<"\n\nHope you enjoyed the games. Thank You"<<endl;
    system("pause");
    return 0;
}
