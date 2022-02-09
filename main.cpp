#include <iostream>
#include <fstream>
#include <string>

void setName(std::string &firstName, std::string &lastName)
{
    std::cout << "Please type your first name: ";

}

void displayNickname()
{

}

void addNickname()
{

}

void removeNickname()
{

}


int main()
{
    unsigned int choice;
    std::string firstName;
    std::string lastName;

    /*Introduction*/
    std::cout << "WELCOME TO NICKNAME GENERATOR:\n";

    /*Mainmenu loop*/
    while (choice != 6)
    {
        /*Mainmenu*/
        std::cout << "Main Menu:\n1.Set Name \n2.Display a Random Nickname \n3.Display All Nicknames \n4.Add a Nickname \n5. Remove a Nickname \n6.Exit\n";
        switch(choice)
        {
            /*Set Name*/
            case 1:
                break;

            /*Display a Random Nickname*/
            case 2:
                break;

            /*Display All Nicknames*/
            case 3:
                break;

            /*Add a Nickname*/
            case 4:
                break;
                
            /*Remove a Nickname*/
            case 5:
                break;

            /*Exit*/
            case 6:
                break;
        }
        return 0;
    }

}