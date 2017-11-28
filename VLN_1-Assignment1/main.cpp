#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string str;
    ifstream fin;
    int counter = 10;
    char input;


    do {
        fin.open("textFile.txt");
        if (fin.is_open()) {
            while (counter > 0) {
                    counter--;
                getline(fin, str);
                cout << str << endl;
            }
            fin.close();
        }
        cout << "Do you wish to continue (y/n)?" << endl;
        cin >> input;
    }
    while (input != 'n');



    return 0;
}

//cout << "Do you wish to continue (y/n)?" << endl;
/*if (fin.is_open()) {
        while (!fin.eof()) {
            getline(fin, str);
            cout << str << endl;
        }
        fin.close();
    }
    else {
        cout << "Unable to read file" << endl;
    }*/
