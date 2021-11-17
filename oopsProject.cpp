// Guess the number game
#include <bits/stdc++.h> 
#include <windows.h> // for colors in console output
#include <dos.h> // sleep() function
#include <ctime> // srand() function

using namespace std;

bool flag = true; // global variable to check if num is guessed acurrately or not


/*
secret class to write secret of game 
seperate class is made so that in future if we want to explain binary search technique we can use this class
*/
class secret
{
public:

    void explain_the_secret(int num)
    {
        system("color B");
        Sleep(1200);
        cout << "\nThe secret is : HALF-INTERVAL SEARCH\n\n";
        Sleep(3000);
        cout << setw(84) << "         ----------------------------------------         \n";
        cout << setw(84) << "                 LeTs TRy It                      \n";
        cout << setw(84) << "           ----------------------------------------         \n\n";

        cout << "First choose end and start point of your range i.e 0 and 1000\n";
        int a = 0;
        int b = 1000;
        int x;
        while (1)
        {
            x = (a + b) / 2;
            cout << "\tGuess the middle number of your given range i.e : " << x << "\n";
            cout << "         ----------------------------------------         \n";
            Sleep(5000);

            if (x < num)
            {
                a = (a + b) / 2;
                system("color B");
                cout << "\nYour guess is smaller than actual number.";
                Sleep(750);
                cout << "\n\tAll the number below this number are not your answer \n";
                Sleep(750);
                cout << "\t\tNow, Range become " << a << " to " << b << endl;
                Sleep(750);
            }
            else if (x > num)
            {
                b = (a + b) / 2;
                system("color B");
                cout << "\nYour guess is greater than actual number.";
                Sleep(750);
                cout << "\n\tAll the number above this number are not your answer \n";
                Sleep(750);
                cout << "\t\tNow, Range become " << a << " to " << b << endl;
                Sleep(750);
            }
            else
            {
                break;
            }
        }

        cout << "\nIn this way you can guess the number in less than 10 guesses\n";
    }

};


//Inheritance of secret class
class Game : public secret
{
private:

    int actual_num;
    int guessed_num;
    static int no_of_guess; /*Static member*/

public:

    //Static member function
    static void set_no_of_guess(int x)
    {
        no_of_guess = 0;
    }


    /*
    -> constructor
    -> default arguments
    -> constructor overloading
    */
    Game(int num1 = 0, int num2 = 0)
    {
        actual_num = num1;
        guessed_num = num2;
    }


    /*
    -> guess_num() function to input guessed number
    -> if input number between 1 to 1000, then guessed_num = input number
    -> else re-run function for that object
    -> this pointer
    */
    void guess_num()
    {
        int guessNum;
        system("color E"); // light yellow color
        cout << " Enter the guessed number : ";
        cin >> guessNum;

        if (guessNum > 0 && guessNum <= 1000)
        {

            no_of_guess++;
            guessed_num = guessNum;
        }
        else
        {
            system("color 4"); // red color
            cout << " !!!! Wrong Input !!!!\n";
            cout << " You select the number out of range.\n Select number between 1 to 1000\n";
            Sleep(1000);
            (*this).guess_num();
        }
    }

    
    /*
    -> help() function to check either number is low and high
    -> display text according to condition
    */
    void help()
    {
        if (guessed_num < actual_num)
        {
            system("color 4");
            cout << "\tOh, Wrong Guess\n";
            cout << "\tActual Number is greater than guessed number.\n" << setw(22) << "Retry\n\n";
            Sleep(1000);
            (*this).guess_num();
        }
        else
        {
            system("color 4");
            cout << "\tOh, Wrong Guess\n";
            cout << "\tActual Number is lower than guessed number.\n" << setw(22) << "Retry\n\n";
            Sleep(1000);
            (*this).guess_num();
        }
    }


    /*
    -> message() function print the accurate message
    -> message is displayed according to number of guesses
    */
    void message()
    {
        if (no_of_guess < 10)
        {
            system("color 2");
            cout << " Number of Guess = " << no_of_guess << endl;
            cout << " Either you know the secret or you got lucky\n\n";
        }
        else if (no_of_guess == 10)
        {
            system("color 2");
            cout << " Number of Guess = " << no_of_guess << endl;
            cout << " Ha Ha Ha... You know the secret\n\n";
        }
        else
        {
            system("color B");
            cout << " Number of Guess = " << no_of_guess << endl;
            cout << " You should be able to do better.\n Why should it take no more than 10 guesses\n\n";

            // explation of secret of game
            cout << "Are you excited to Know the secret of finding number in less than 10 guesses : ";
            cout << "YES\n";
            cout << setw(84) << " NO\n\n";
            cout << "Enter the choice : ";
            string s;
            cin >> s;
            if (s == "YES" || s == "Yes" || s == "yes")
            {
                explain_the_secret(actual_num); //is-a relation (Class game has a object of class secret)//class inherited
            }
        }
    }


    /*
    -> check() function to check guessed number is low, high or correct
    -> this pointer
    -> if guessed number = actual number run message function
    -> else run help function
    -> defining the function out the class
    */
    void check();


    /*
    Declaration of friend function begin()
   */
    friend void begin(Game &);


    ~Game() {} //Destructor
};


// set static member function to zero
int Game ::no_of_guess = 0;


/* This function is defined outside the class using scope resolution operator ::  */
void Game ::check()
{
    if (guessed_num == actual_num)
    {
        system("color 2"); // green color
        flag = false;
        cout << "\n\t\t\t -----------------------------------";
        cout << "\n\t\t\t Congratulations ^^  ^^ \n \t\t\t You guessed the number correctly.\n";
        cout << "\t\t\t -----------------------------------\n\n";
        Sleep(1000);
        (*this).message();
    }
    else
    {
        (*this).help();
    }
}


/* ->Friend function of class Game
   ->Used it to intialize the actual_number
   -> rand() function to get random number
   -> rand()%1000 + 1 to get number between 1 to 1000
 */
void begin(Game &g)
{
    int num = rand() % 1000 + 1;

    g.actual_num = num;
}


int main()
{
    srand(time(NULL)); // makes use of the computer's internal clock to control the choice of the seed so that we get different seed for rand function
    system("color 3"); // aqua color
    // setw() function use to set width
    cout << setw(84) << "         ----------------------------------------         \n";
    cout << setw(84) << "                    GUESS THE NUMBER                      \n";
    cout << setw(84) << "           ----------------------------------------         \n\n";
    cout << setw(72) << " Welcome to Guess The Number Game, \n\n";

    string name;
    cout << "Enter your name : ";
    cin >> name;

    cout << "\n\tHello " << name << "\n\n";

    while (1)
    {

        Game ::set_no_of_guess(0); //Call to static member function

        flag = true;

        system("color c"); // light red color
        int choice;
        // sleep function delay for specified amount of time
        Sleep(1200);
        cout << "\n *Press 1 to enter * \n";
        cout << " *Press 0 to exit * \n";
        Sleep(1000);
        cout << "\n Enter choice : ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "\t\t\tAll THe BeSt\n\n";

            Game G;

            cout << " Lets Begin ......\n\n";

            begin(G);

            cout << " I have a number between 1 to 1000. Can you guess my number?\n\n";

            G.guess_num();

            while (flag)
            {
                G.check();
            }
        }
        else if (choice == 0)
        {
            break;
        }
        else
        {
            cout << " Press Correct Choice \n";
        }
        Sleep(2000);
        cout << setw(84) << "           -------------------ThAnX FoR PlAyInG------------------         \n\n";
        system("Pause"); 
    }

    return 0;
}