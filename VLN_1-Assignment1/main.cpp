#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string str;
    ifstream fin;
    char input;

    fin.open("textFile.txt");

    do {
        if (fin.is_open()) {
            for(int i = 0; i < 10; i++){
                getline(fin, str);
                cout << str << endl;
            }
        }
        do {
        cout << "Do you wish to continue (y/n)?" << endl;
        cin >> input;
        }while (input != 'n' && input != 'y');
    }
    while (input != 'n');
    fin.close();

    return 0;
}
