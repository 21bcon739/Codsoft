#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {

    srand(time(0));

    int randomNumber = rand() % 100 + 1;
    int guessnum = 0;

    cout << "Hello There Welocome to game " << endl;
    cout << "We have Generated a random Number " << endl;
    cout << "Do you able to guess " << endl;

    while (guessnum != randomNumber) {
        cout << "Please Enter your guess: ";
        cin >> guessnum;

        if (guessnum < randomNumber) {
            cout << "Very small number , Please Guess again" << endl;
        } else if (guessnum > randomNumber) {
            cout << "Very High number , Please Guess again" << endl;
        } else {
            cout << "Congratulations! You guessed correctly" << endl;
        }
    }

    return 0;
}
