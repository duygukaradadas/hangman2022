#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main() {

    ifstream take;
    take.open("HANGMANN.txt");

    string word1;
    char* w1;
    int size1;
    while(take>>word1){
        w1=&word1[0];
    }
    take.close();
    size1=word1.length();

    int n=0;
    int counter=0;
    char guessedArray1[size1];

    for(int j=0; j<size1; j++){
        guessedArray1[j]= '-';
    }

    cout << "welcome to hangman. you have 10 tries to find the word. " << endl;
    int lives1=10;
    char guess;
    bool notfound ;

    while(lives1 > 1){
        cout << "lives : " << lives1 << endl;
        cout<< "GUESS: " << endl;
        cin >> guess;


   for (int i=0; i<size1; i++){

            if (guess == *(w1+i) ) {
                guessedArray1[i] = guess;
                n=1;
                counter++;
            }
            else if (guessedArray1[i]== '-') {
                guessedArray1[i]='*';
            }
            cout << guessedArray1[i] ;
        }

        cout << endl;

        if (n==0){
            cout << "wrong guess! " ;
            lives1--;
        }
        if (n==1){
            cout << " nice guess ! " ;
            for (int k = 0; k < size1; ++k) {
                if( guessedArray1[k] == '*' ) {
                    notfound= true;
                    break;
                }
                 notfound= false;
            }
        }

        if (notfound == false) {
            cout << "congratz. you found the word: " << word1 << endl;
            break;
        }
        if (lives1==1){
            cout << "your man is hanged !!! :( " << endl;
            break;
        }
        n=0;
    }

    return 0;
}
