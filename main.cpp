#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>
#include <ctime>

static int randomInt(const size_t max)
{
    /*Seed random number generator*/
    std::srand (time(NULL));

    return std::rand() % max;
}
void setName(std::string &firstName, std::string &lastName)
{
    /*Set First Name*/
    std::cout << "Please type your first name: ";
    std::cin.ignore();
    std::getline(std::cin, firstName);

    /*Set Last Name*/
    std::cout << "Please type your last name: ";
    std::getline(std::cin, lastName);

    std::cout << "Name set to " + firstName + " " + lastName << std::endl;
}

void addNickname(std::vector<std::string> &nicknames)
{   
    /*Add New Nickname*/
    std::string name;
    std::cout << "What nickname should we add: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    nicknames.push_back(name);

    /*Update Nickname File*/
    std::ofstream nicknamesFile("nicknames.txt", std::ios_base::app);//append
    nicknamesFile << std::endl << name;

}

void removeNickname(std::vector<std::string> &nicknames)
{
    /*Remove Nickname*/
    std::string name;
    std::cout << "What nickname should we remove: ";
    std::cin.ignore();
    std::getline(std::cin, name);

    for(size_t i = 0; i < nicknames.size(); i++)
    {
        if (nicknames[i] == name)
        {
            nicknames.erase(nicknames.begin() + i);
        }
    }

    std::ofstream nicknamesFile("nicknames.txt",std::ofstream::trunc);
    for(size_t i = 0; i < nicknames.size(); i++)
    {
        nicknamesFile << nicknames[i] << std::endl;
    }
}


int main()
{
    /* Variables */
    size_t choice;

    std::string firstName = "John";
    std::string lastName = "Doe";

    std::string line;
    std::vector<std::string> nicknames;

    size_t randInt;

    /*Introduction*/
    std::cout << "--------WELCOME TO NICKNAME GENERATOR--------\n";
   
    //*Read Nickname File and Init Nicknames Array*/
    std::fstream nicknamesFile("nicknames.txt");
    while (std::getline (nicknamesFile, line))
    {
        nicknames.push_back(line);
    }

    /*Mainmenu loop*/
    while (choice != 6)
    {
       
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
                randInt = randomInt(nicknames.size());
                std::cout << std::endl << firstName << " " << nicknames[randInt] << " " << lastName << std::endl; //ADDING << " " << lastName  breaks it
                break;

            /*Display All Nicknames*/
            case 3:
                for(size_t i = 0; i < nicknames.size(); i++)
                {
                    std::cout << firstName << " " << nicknames[i] << " " << lastName << std::endl; //ADDING << " " << lastName 
                }
                break;

            /*Add a Nickname*/
            case 4:
                addNickname(nicknames);
                break;
                
            /*Remove a Nickname*/
            case 5:
                removeNickname(nicknames);
                break;

            /*Exit*/
            case 6:
                break;
            
            /*Cath Invalid Selections*/
            default:
                std::cout << "ERROR: Invalid Menu Selection!\n";
                break;
        }
    }
    
    return 0;
}