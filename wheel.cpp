#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

class wheel
{
    string word;

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
        int num_word = rand() % num;
        num = 0;
        while(num < num_word){
            buf.clear();
            getline(tmp, buf);
            num++;
        }
        word = buf;
        cout << word << endl;;
    };


};


int main()
{
    string name;
    cout << "Please, input your name:" << endl;
    cin >> name;
    cout << "Hello, " << name << endl << "Let's play!" << endl;
    wheel game;
}