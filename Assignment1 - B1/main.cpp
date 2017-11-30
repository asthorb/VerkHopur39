#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Superhero{
private:
    string name;
    int age;
    char power;

public:
    Superhero(){
        name = " ";
        age = 0;
        power = 'n';
    }

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

    friend istream& operator >> (istream& in, Superhero& superhero);
    friend ostream& operator << (ostream& out, Superhero& superhero);

};
void WelcomeMessage ()
{
    cout << "Please enter your name, age and superpower," << endl;
    cout << "For the superpower of Flying, write f"<< endl;
    cout << "For the superpower of Giant, write g"<< endl;
    cout << "For the superpower of Hacker, write h"<< endl;
    cout << "If you do not want any superpowers, write n"<< endl;
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
    char power;

    WelcomeMessage();

    Superhero hero;
    hero.setName(name);
    hero.setAge(age);
    hero.setPower(power);
    cout << hero.getName()  << " (";
    cout << hero.getAge()   << "): ";

    ofstream fout;
    fout.open("SuperFile.txt", ios::app);
    if(fout.is_open()){
        fout << hero.getName()  << " (";
        fout << hero.getAge()   << "): ";
        fout << hero.getPower() << " \n";
    }
    else{
        cout << "the file is closed" << endl;
    }
    fout.close();

    // Reads the superpower:
    Superpower(hero.getPower());

    return 0;
}

istream& operator >> (istream& in, Superhero& superhero){
    in >> superhero.name >> superhero.age >> superhero.power;
    return in;
}
ostream& operator << (ostream& out, Superhero& superhero){
    out << superhero.name << superhero.age << superhero.power;
    return out;
}
