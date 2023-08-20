#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

int main()
{
    srand(time(0));
    string name;
    int balance;
    int betAmount;
    cout << "\n\t\t\t--------------------------------------------------------------------------------";
    cout << "\n\t\t\t\t\t\tWelcome to the Casino Game!";
    cout << "\n\t\t\t--------------------------------------------------------------------------------";

    cout << "\n\n\t\t\t\t\t\tRULES OF THE GAME\n";
    cout << "\t1. Choose any number between 1 to 10\n";
    cout << "\t2. If you win you will get 3 times the money you bet\n";
    cout << "\t3. If you bet on wrong you will lose your betting amount\n";
    cout << "\t4. You can play until you run out of your balance money\n\n";

    cout << "\n\nEnter Your Name : ";
    getline(cin, name);

    cout << "\n\nEnter Deposit amount to play game : $";
    cin >> balance;
    while (balance > 0)
    {
        cout << "Your current balance: $" << balance << endl;

        // Get user's bet amount

        while (true)
        {
            cout << "\nEnter your bet amount: $";
            cin >> betAmount;
            if (betAmount <= 0 || betAmount > balance)
            {
                cout << "Invalid bet amount. Please enter a valid amount." << endl;
            }
            else
                break;
        }
        int guess;

        // Get user's guess
        while (true)
        {
            
            cout << "Enter your guess (1-10): ";
            cin >> guess;
            if (guess < 1 || guess > 10)
            {
                cout << "Invalid guess. Please enter a number between 1 and 10." << endl;
            }
            else
                break;
        }

        // Generate a random number between 1 and 6
        int randomNumber = rand() % 10 + 1;
        cout << "The rolled number is: " << randomNumber << endl;

        if (guess == randomNumber)
        {
            cout << "Congratulations! You guessed it right. You win $" << betAmount * 3 << endl;
            balance += betAmount * 3;
            cout << "Your current balance: $" << balance << endl;
        }
        else
        {
            cout << "Sorry, your guess was incorrect. You lose $" << betAmount << endl;
            balance -= betAmount;
            cout << "Your current balance: $" << balance << endl;
        }

        if (balance <= 0)
        {
            cout << "\nYou have run out of money. Game over." << endl;
        }
        else
        {
            char playAgain;
            cout << "\nDo you want to play again? (y/n): ";
            cin >> playAgain;
            if (playAgain != 'y' && playAgain != 'Y')
            {
                break;
            }
        }
    }

    cout << "Thank you for playing!" << endl;

    return 0;
}
