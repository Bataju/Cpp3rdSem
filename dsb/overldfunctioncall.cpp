#include <iostream>
#include <cstring>
using namespace std;

class WelcomeUser
{
private:
    string name;
public:
    WelcomeUser():name(" "){}
    WelcomeUser(string nameInput):name(nameInput){}
    void operator()(string welcomeMessage)
    {
        cout<<"Hey, "<<name<<" "<<welcomeMessage<<endl;
    }
};

int main()
{
    WelcomeUser user1("Leia");
    WelcomeUser user2("Bataju");
    user1("where have you been hiding all this time?");
    user2("are you even prepared for this?");
    user1("welcoming you again....");
    return 0;
}