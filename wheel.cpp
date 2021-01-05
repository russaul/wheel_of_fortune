#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

class wheel
{
    string word;
    string tmp_word;

    public:
    
    wheel()
    {
        string buf;
        fstream tmp("words.txt", ios_base::in);
        int num = 0;
        while (!tmp.eof()){
            getline(tmp, buf);
            num++;
            buf.clear();
        }
        tmp.clear();
        tmp.seekg(0);
        srand(time(0));
        int num_word = rand() % num + 1;
        for (num = 0; num < num_word; num++){
            buf.clear();
            getline(tmp, buf);
        }
        word = buf;
        num_word = word.length();
        for (num = 0; num < num_word; num++)
            tmp_word += '_';
    };

    int num_symb(char symb)
    {
        int i, len = tmp_word.length(), num = 0;
        for (i = 0; i < len; i++){
            if (tmp_word[i] == symb){
                num++;
            }
        }
        return num;
    };

    void check(char letter)
    {
        int i, len = word.length();
        for (i = 0; i < len; i++){
            if (word[i] == letter){
                tmp_word[i] = word[i];
            }
        }
    }

    void game_circle()
    {
        char letter;
        while (num_symb('_') != 0){
            cout << endl << tmp_word << endl << "Input letter: ";
            cin >> letter;
            check(letter);
        } 
        cout << endl << endl << "Good!" << endl << "Your word was " << word << endl;
    };

};


int main()
{
    string name;
    cout << "Please, input your name: ";
    cin >> name;
    cout << "Hello, " << name << "\n\nLet's play!" << endl;
    wheel game;
    game.game_circle();
}