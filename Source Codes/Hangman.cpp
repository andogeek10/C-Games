#include <iostream>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
using namespace std;
char unknown_word[60],user_guess;
const int tries=6;
int again=0,guess=0;
void welcome()
{
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"\t\tWelcome to Hangman. The rules"<<endl;
    cout<<"\t\tare simple. You will be presented with"<<endl;
    cout<<"\t\ta choice of topics. Choose one of them. After that"<<endl;
    cout<<"\t\tyou will need to guess the name of the particular "<<endl;
    cout<<"\t\tthing related to that topic. You will have maximum"<<endl;
    cout<<"\t\t5 chances."<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t- Anmol Chawla"<<endl;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    system("pause");
}
void starfier(char guess_word[],char unknown_word[])
{
    int i;                              //This function assigns stars to an array of the same length as the randomly
    int length_of_word = strlen(guess_word);         //chosen guess word and will take the white spaces into account.
    for (i=0;i<length_of_word;++i)
    {
        if (guess_word[i]==' ')
        {
            unknown_word[i]=' ';
        }
        else
        unknown_word[i]='*';
    }
    unknown_word[i]='\0';
}
int check (char user_guess,char unknown_word[],char guess_word[])
{
    int i,matches=0;                                        //This function checks the entered letter and also check if it has
    for (i=0;guess_word[i]!='\0';++i)                       //already been entered.
    {
        if (user_guess==unknown_word[i])
            {
                return again=1;
            }
            else
        if (user_guess==guess_word[i]||user_guess==tolower(guess_word[i]))
        {
            if (user_guess==tolower(guess_word[i]))
            {
                unknown_word[i]=guess_word[i];
            }
            else
            unknown_word[i]=user_guess;
            matches++;
        }
    }
    return matches;
}
void display()
{
    switch (guess)                                      //This function uses the switch to display guess_word static
    {                                                   //image similar to the Hangman game. It uses the
        case 0 : cout<<" -------------------"<<endl;    //it uses the number of error done by the user as
                 cout<<" |                 |"<<endl;    //the case arguments.
                 cout<<" |                 |"<<endl;
                 cout<<" |                 O"<<endl;
                 cout<<" |"<<endl;
                 cout<<" |"<<endl;
                 cout<<" |"<<endl;
                 cout<<" |"<<endl;
                 cout<<"/ \\"<<endl;
                 break;
        case 1 : cout<<" -------------------"<<endl;
                 cout<<" |                 |"<<endl;
                 cout<<" |                 |"<<endl;
                 cout<<" |                 O"<<endl;
                 cout<<" |                 |"<<endl;
                 cout<<" |"<<endl;
                 cout<<" |"<<endl;
                 cout<<" |"<<endl;
                 cout<<"/ \\"<<endl;
                 break;
        case 2 : cout<<" -------------------"<<endl;
                 cout<<" |                 |"<<endl;
                 cout<<" |                 |"<<endl;
                 cout<<" |                 O"<<endl;
                 cout<<" |                 |"<<endl;
                 cout<<" |                /|"<<endl;
                 cout<<" |"<<endl;
                 cout<<" |"<<endl;
                 cout<<"/ \\"<<endl;
                 break;
        case 3 : cout<<" -------------------"<<endl;
                 cout<<" |                 |"<<endl;
                 cout<<" |                 |"<<endl;
                 cout<<" |                 O"<<endl;
                 cout<<" |                 |"<<endl;
                 cout<<" |                /|\\"<<endl;
                 cout<<" |"<<endl;
                 cout<<" |"<<endl;
                 cout<<"/ \\"<<endl;
                 break;
        case 4 : cout<<" -------------------"<<endl;
                 cout<<" |                 |"<<endl;
                 cout<<" |                 |"<<endl;
                 cout<<" |                 O"<<endl;
                 cout<<" |                 |"<<endl;
                 cout<<" |                /|\\"<<endl;
                 cout<<" |                 |"<<endl;
                 cout<<" |"<<endl;
                 cout<<"/ \\"<<endl;
                 break;
        case 5 : cout<<" -------------------"<<endl;
                 cout<<" |                 |"<<endl;
                 cout<<" |                 |"<<endl;
                 cout<<" |                 O"<<endl;
                 cout<<" |                 |"<<endl;
                 cout<<" |                /|\\"<<endl;
                 cout<<" |                 |"<<endl;
                 cout<<" |                / "<<endl;
                 cout<<"/ \\"<<endl;
                 break;
        case 6 : cout<<" -------------------"<<endl;
                 cout<<" |                 |"<<endl;
                 cout<<" |                 |"<<endl;
                 cout<<" |                 O"<<endl;
                 cout<<" |                 |"<<endl;
                 cout<<" |                /|\\"<<endl;
                 cout<<" |                 |"<<endl;
                 cout<<" |                / \\"<<endl;
                 cout<<"/ \\"<<endl;
                 break;
    }
}
void game (char guess_word[],char word_library[][60])
{
    while (guess<tries)                                     //This function contains the main part of the game.
    {                                                       //It receives the guess word and employs guess_word while
        system("cls");                                      //loop, which run till the time the number
        display();                                          //of wrong guesses are less than the defined
        cout<<"Your progress :"<<unknown_word<<endl;        //number of tries allowed.
        cout<<"Number of tries left :"<<tries-guess<<endl;
        cout<<"\nEnter guess letter :";
        cin>>user_guess;
        if (check (user_guess,unknown_word,guess_word)==0)
        {   cout<<"You guessed wrong"<<endl;
            guess++;
        }
        else
        {
            if(again==1)
            {
                cout<<"You have already entered this letter before";
                again=0;
            }
            else
            cout<<"You guessed correctly"<<endl;
        }
        getch();
        if (strcmp (guess_word,unknown_word) == 0)
        {
            cout<<"\n"<<guess_word;
            cout<<"\nCongratulations!!You have won.";
            break;
        }
    }
    if (guess==tries)
    {
        system("cls");
        display();
        cout<<"\nYou have been Hanged!!";
        cout<<"\n\nThe correct word was :"<<guess_word;
    }
    getch();
}
void countries()
{
    int number_of_the_word;
    char guess_word[60];
    char word_library[][60]={
                                "India",
                                "United States Of America",
                                "Philippines",
                                "Pakistan",
                                "Japan",
                                "United Kingdom",
                                "China",
                                "England",
                                "Australia",
                                "France",
                                "Afghanistan",
                                "Albania",
                                "Angola",
                                "Austria",
                                "Bangladesh",
                                "Barbados",
                                "Belgium",
                                "Bhutan",
                                "Cambodia",
                                "Canada",
                                "Cayman Islands",
                                "Chile",
                                "Cuba",
                                "Djibouti",
                                "Dominican Republic",
                                "Ecuador",
                                "Egypt",
                                "El Salvador",
                                "Estonia",
                                "Finland",
                                "Germany",
                                "Guinea",
                                "Greece",
                                "Jamaica",
                                "Libya",
                                "Mauritius",
                                "Nigeria",
                                "Norway",
                                "Peru",
                                "Serbia",
                                "Spain",
                                "Switzerland",
                                "Turkey",
                                "Uzbekistan",
                                "Vietnam",
                                "Yemen",
                                "Zambia",
                                "Zimbabwe"
                            };
    cout<<"You have chosen the topic : Countries"<<endl;
    system("pause");
    srand (time(NULL));
    number_of_the_word=(rand()%47);
    strcpy (guess_word,word_library[number_of_the_word]);
    starfier(guess_word,unknown_word);
    game(guess_word,word_library);
}
void movies()
{
    int number_of_the_word;
    char guess_word[60];
    char word_library[][60]={
                                "The Shawshank Redemption",
                                "The Godfather",
                                "The Dark Knight",
                                "The Lord of the Rings: The Return of the King",
                                "Fight Club",
                                "Interstellar",
                                "Inception",
                                "The Matrix",
                                "Back to the Future",
                                "Django Unchained"
                            };
    cout<<"You have chosen the topic : Movies"<<endl;
    system("pause");
    srand (time(NULL));
    number_of_the_word=(rand()%10);
    strcpy (guess_word,word_library[number_of_the_word]);
    starfier(guess_word,unknown_word);
    game(guess_word,word_library);
}
void characters()
{
    int number_of_the_word;
    char guess_word[60];
    char word_library[][60]={
                                "The Joker",
                                "Captain Jack Sparrow",
                                "Darth Vader",
                                "Indiana Jones",
                                "Hannibal Lector",
                                "Neo",
                                "Legolas",
                                "Jason Bourne",
                                "Tony Stark",
                                "James Bond"
                            };
    cout<<"You have chosen the topic : Movie Characters"<<endl;
    system("pause");
    srand (time(NULL));
    number_of_the_word=(rand()%10);
    strcpy (guess_word,word_library[number_of_the_word]);
    starfier(guess_word,unknown_word);
    game(guess_word,word_library);
}
void cars()
{
    int number_of_the_word;
    char guess_word[60];
    char word_library[][60]={
                                "Mazda",
                                "Acura",
                                "GMC",
                                "Subaru",
                                "Nissan",
                                "Chevrolet",
                                "Dodge",
                                "Ford",
                                "Honda",
                                "Toyota"
                            };
    cout<<"You have chosen the topic : Car Brands"<<endl;
    system("pause");
    srand (time(NULL));
    number_of_the_word=(rand()%10);
    strcpy (guess_word,word_library[number_of_the_word]);
    starfier(guess_word,unknown_word);
    game(guess_word,word_library);
}
void animals()
{
    int number_of_the_word;
    char guess_word[60];
    char word_library[][60]={
                                "Albatross",
                                "Alligator",
                                "Anteater",
                                "Antelope",
                                "Arctic Fox",
                                "Armadillo",
                                "Baboon",
                                "Badger",
                                "Bat",
                                "Barracuda",
                                "Bear",
                                "Beaver",
                                "Beetle",
                                "Bulldog",
                                "Camel",
                                "Caiman",
                                "Cat",
                                "Cheetah",
                                "Chinook",
                                "Coyote",
                                "Crab",
                                "Coyote",
                                "Eagle",
                                "Echidna",
                                "Emu",
                                "Falcon",
                                "Fish",
                                "Fox",
                                "Gerbil",
                                "Giraffe",
                                "Goat",
                                "Hamster",
                                "Hare",
                                "Heron",
                                "Horse",
                                "Jackal",
                                "Jaguar",
                                "Jellyfish",
                                "Kangaroo",
                                "Kingfisher",
                                "Kiwi",
                                "Koala",
                                "Komodo Dragon",
                                "Lemur",
                                "Leopard",
                                "Liger",
                                "Lion",
                                "Macaw",
                                "Mole",
                                "Possum",
                                "Puma"
                            };
    cout<<"You have chosen the topic : Animals"<<endl;
    system("pause");
    srand (time(NULL));
    number_of_the_word=(rand()%50);
    strcpy (guess_word,word_library[number_of_the_word]);
    starfier(guess_word,unknown_word);
    game(guess_word,word_library);
}
void menu()
{
    cout<<"Choose a topic :"<<endl;
    cout<<"1.Countries"<<endl;
    cout<<"2.Movies"<<endl;
    cout<<"3.Movie Characters"<<endl;
    cout<<"4.Car Brands"<<endl;
    cout<<"5.Animals"<<endl;
    cout<<"Enter the the number corresponding to your choice :";
}
void play()
{
    int choice;
    char retry;
    do{
            X:
            system("cls");
            cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
            cout<<"\t\t\t\t Hangman"<<endl<<endl<<endl;
            cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
            menu();
            cin>>choice;
            switch(choice)
            {
                case 1: countries();
                        break;
                case 2: movies();
                        break;
                case 3: characters();
                        break;
                case 4: cars();
                        break;
                case 5: animals();
                        break;
              default : cout<<"You have entered a wrong choice"<<endl;
                        system("pause");
                        goto X;
                        break;
            }
            cout<<"\n\nDo you want to play again (Y or N)?";
            cin>>retry;
            guess=0;
      }
    while (retry=='y'||retry=='Y');
}
int main()
{
    welcome();
    play();
    cout<<"\nThank you for playing this game."<<endl;
    return 0;
}
