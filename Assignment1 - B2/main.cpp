#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Superhero{
private:
    //char name[20];
    string name;
    int age;
    char power;

public:
    Superhero(){
        //name[0] = '\0';
        name = " ";
        age = 0;
        power = 'n';
    }
//Fallið sem átti að nota fyrir char array
/*    void setName(char a){
        cin >> a;
        name[0] = a;
    }
*/
      void setName(string x){
        cin >> x;
        name = x;
    }
    string getName(){
        return name;
    }
    void setAge(int y){
        cin >> y;
        age = y;
    }
    int getAge(){
        return age;
    }
    void setPower(char b){
        cin >> b;
        power = b;
    }
    char getPower(){
        return power;
    }
friend ostream& operator << (ostream& out, Superhero& superhero);
};
void WelcomeMessage ()
{
    cout << "Please enter your name, age and superpower." << endl;
    cout << "For the superpower of Flying, write f"<< endl;
    cout << "For the superpower of Giant, write g"<< endl;
    cout << "For the superpower of Hacker, write h"<< endl;
    cout << "If you do not want any superpowers, write n"<< endl;
    //cout << "If you want to see what superheroes are on the list, write r"<< endl;
}
void Superpower (char a)
{
    switch (a)
    {
        case 'f':
            cout << "Flying";
            break;

        case 'g':
            cout << "Giant";
            break;

        case 'h':
            cout << "Hacker";
            break;

        case 'n':
            cout << "None";
            break;

        default:
            cout << "Weakling";

    }

    cout << endl;

}

int main()
{
    string name;
    int age;
    char power, input;

    do{
    WelcomeMessage();

    Superhero hero;
    hero.setName(name);
    hero.setAge(age);
    hero.setPower(power);
    cout << hero.getName()  << " (";
    cout << hero.getAge()   << "): ";

    ofstream fout;
    fout.open("SuperFile.dat", ios::binary|ios::app);
    if(fout.is_open()){
            fout.write((char*)(&hero), sizeof(Superhero));
    }
    else{
        cout << "the file is closed" << endl;
    }
    // Reads the superpower:
    Superpower(hero.getPower());
    fout.close();
/*
    Superhero hero2;

    ifstream fin;
    fin.open("SuperFile.dat", ios::binary);
    if(fin.is_open()){

            fin.seekg(0, fin.end);
            int recordCount = fin.tellg() / sizeof(Superhero);
            fin.seekg(0, fin.beg);

            for(int i = 0; i < recordCount; i++){
                fin.read((char*)(&hero2), sizeof(Superhero));
                cout << hero2;
                }
            }
        else{
            cout << "The file is not open" << endl;
        }
        fin.close();
*/
        do {
        cout << "Do you wish to enter a new superhero? (y/n)" << endl;
        cin >> input;
       // cout << "To see the list of superheroes? write r" << endl;
        //cin >> inputHero;
        cout << endl;
        }while (input != 'n' && input != 'y');
    }
    while (input != 'n');

    return 0;
}
