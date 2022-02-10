#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>

static int randomInt(const size_t min, const size_t max)
{
    /*Seed random number generator*/
    std::random_device rd;
    std::mt19937 mt(rd());

    std::uniform_real_distribution<double> dist(min, max + 1);

    return dist(mt);
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
    std::string text;
    std::cout << "What nickname should we add: ";
    std::cin.ignore();
    std::getline(std::cin, text);
    nicknames.push_back(text);

    /*Update Nickname File*/
    std::ofstream nicknamesFile("nicknames.txt", std::ios_base::app);//append
    nicknamesFile << std::endl << text;

}

void removeNickname()
{
    
}


int main()
{
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
                randInt = randomInt(0, nicknames.size());
                std::cout << std::endl << firstName + " " + nicknames[randInt] + " " + lastName << std::endl;
                break;

            /*Display All Nicknames*/
            case 3:
                for(size_t i = 0; i < nicknames.size(); i++) //TEST THIS FOR-LOOP MORE BEFORE MOVING ON
                {
                    std::cout << firstName + " " + nicknames[i] + " " + lastName << std::endl;
                }
                break;

            /*Add a Nickname*/
            case 4:
                addNickname(nicknames);
                break;
                
            /*Remove a Nickname*/
            case 5:
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