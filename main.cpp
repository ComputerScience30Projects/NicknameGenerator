#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>

int randomInt(const unsigned int min, const unsigned int max)
{
    //Seed random number generator
    std::random_device rd;
    std::mt19937 mt(rd());

    std::uniform_real_distribution<double> dist(min, max + 1);

    return dist(mt);
}
void setName(std::string &firstName, std::string &lastName)
{
    /*Set First Name*/
    std::cout << "Please type your first name: ";
    std::cin >> firstName;

    /*Set Last Name*/
    std::cout << "Please type your last name: ";
    std::cin >> lastName;

    std::cout << "Name set to " + firstName + " " + lastName << std::endl;
}

void displayRandomNickname(const std::string nickname, const std::string &firstName, const std::string &lastName)
{
    /*Print Name*/
    std::cout << std::endl << firstName + " " + nickname + " " + lastName << std::endl;
}

void addNickname(std::vector<std::string> &nicknames)
{   
    /*Add New Nickname*/
    std::string text;
    std::cout << "What nickname should we add?:\n ";
    std::cin >> text;
    nicknames.push_back(text);
}

void removeNickname()
{
    
}

void updateNicknames() //WORK ON THIS RNRNRNRNRN
{
    /* Opening file without append mode to rewrite data*/
    std::ofstream file("nicknames.txt");
}

int main()
{
    unsigned int choice;

    std::string firstName = "John";
    std::string lastName = "Doe";

    std::string line;
    std::vector<std::string> nicknames;

    unsigned int randInt;

    /*Introduction*/
    std::cout << "WELCOME TO NICKNAME GENERATOR:\n";

    /*Mainmenu loop*/
    while (choice != 6)
    {
        /*Read Nickname File*/
        std::fstream nicknameFile("nicknames.txt");
        while (std::getline (nicknameFile, line))
        {
            nicknames.push_back(line);
        }
        
        /*Mainmenu selection*/
        std::cout << "\nMain Menu:\n1.Set Name \n2.Display a Random Nickname \n3.Display All Nicknames \n4.Add a Nickname \n5.Remove a Nickname \n6.Exit\n";
        std::cin >> choice;

        switch(choice)
        {
            /*Set Name*/
            case 1:
                setName(firstName, lastName);
                break;

            /*Display a Random Nickname*/
            case 2:
                randInt = randomInt(0, nicknames.size());
                displayRandomNickname(nicknames[randInt], firstName, lastName);
                break;

            /*Display All Nicknames*/
            case 3:
                updateNicknames();
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
            
            default:
                std::cout << "ERROR: Invalid Menu Selection\n";
                break;
        }
    }
    
    return 0;
}