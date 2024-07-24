#include <iostream>
#include <cstdlib>  
#include <ctime>    

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0))); 

    int a = rand() % 100 + 1;  
    int n;

    cout<< " *** NUMBER GUESSING GAME *** "<<endl;
    
    cout << "Guess the number (between 1 and 100): ";
    cin >> n;

    while (n != a) {
        if (n < a) {
            cout <<"guess is too low. Guess again: ";
        } else {
            cout << "guess is too high. Guess again: ";
        }
        cin >> n;
    }

    cout <<"You guessed the right number : " << a << endl;

    return 0;
}