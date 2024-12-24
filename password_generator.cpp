#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

std::tuple<std::string, int, int> menu(){
    std::string program;
    int znaki;
    int jezyk;
    bool wyborJezyka = true;

    std::cout << "Wybierz język / Select your language: " << '\n' << "1. Polski" << '\n' << "2. English" << '\n';
    while (wyborJezyka == true)
    {
        std::cin >> jezyk;
        if (jezyk == 1 or jezyk == 2)
        {
            wyborJezyka = false;
        }
        else
        {
        std::cout << "Wybierz liczbe! / Select number!" << '\n';
        }
        
    }

    if (jezyk == 1)
    {
        std::cout << "Witaj w generatorze haseł, plik z hasłami znajduje sie w lokalizacji pliku wykonywalnego." << '\n';
        std::cout << "Do czego chcesz wygenerowac hasło?" << '\n';
        std::cin >> program;

        std::cout << "Ile znaków ma mieć hasło?" << '\n';
    }
    else
    {
        std::cout << "Welcome in password generator, file with passwords is located with executable file." << '\n';
        std::cout << "For what you want generate password?" << '\n';
        std::cin >> program;

        std::cout << "How many symbols password will have?" << '\n';
    }
    std::cin >> znaki;
    while (true)
    {
        if (std::cin.good() && znaki > 0)
        {
            break;
        }
        else
        {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << (jezyk == 1 ? "Podaj prawidłową liczbę!" : "Insert valid number!") << '\n';
            std::cin >> znaki;
        }
            
    }
    
    
    return {program, znaki, jezyk};
}

char losowyZnak(const std::string& symbole) {
    int index = rand() % symbole.size();
    return symbole[index];
}


std::string generator(int dlugosc){
    std::string symbole = "0123456789!@#$%^&*()-_=+[]{}|;:,.<>?/~";

    std::string losowe;
    for (int i = 0; i < dlugosc; ++i) {
        losowe += losowyZnak(symbole);
    }
    return losowe;
}


int main() {

    auto [program, znaki, jezyk] = menu();
    if (jezyk == 1)
    {
        std::ifstream sprawdzenie("hasla.txt");
    
        std::string zawartosc;
        std::vector<std::string> hasla;

        std::srand(std::time(0));

        if (!sprawdzenie)
        {
            while (getline (sprawdzenie, zawartosc))
            {
                hasla.push_back(zawartosc);
            }

            std::string losowe = generator(znaki);
            hasla.push_back(losowe + " - " + program);

            std::ofstream plikHasla("hasla.txt");
            for (const auto& zawartosc : hasla)
            {
            plikHasla << "Twoje hasła: " << '\n' << zawartosc << '\n'; 
            }
            plikHasla.close();  

            std::cout << "Po wiecej haseł uruchom program ponownie" << '\n';

        }
        else
        {



            while (getline (sprawdzenie, zawartosc))
            {
                hasla.push_back(zawartosc);
            }

            std::string losowe = generator(znaki);
            hasla.push_back(losowe + " - " + program);

            std::ofstream plikHasla("hasla.txt");
            for (const auto& zawartosc : hasla)
            {
            plikHasla << zawartosc << '\n'; 
            }
            plikHasla.close();  


            
        }
    }
    else
    {
        std::ifstream sprawdzenie("passwords.txt");
    
        std::string zawartosc;
        std::vector<std::string> hasla;

        std::srand(std::time(0));

        if (!sprawdzenie)
        {
            while (getline (sprawdzenie, zawartosc))
            {
                hasla.push_back(zawartosc);
            }

            std::string losowe = generator(znaki);
            hasla.push_back(losowe + " - " + program);

            std::ofstream plikHasla("passwords.txt");
            for (const auto& zawartosc : hasla)
            {
            plikHasla << "Your passwords: " << '\n' << zawartosc << '\n'; 
            }
            plikHasla.close();

            std::cout << "For more passwords launch again." << '\n';
        }
        else
        {
            while (getline (sprawdzenie, zawartosc))
            {
                hasla.push_back(zawartosc);
            }

            std::string losowe = generator(znaki);
            hasla.push_back(losowe + " - " + program);

            std::ofstream plikHasla("passwords.txt");
            for (const auto& zawartosc : hasla)
            {
            plikHasla << zawartosc << '\n'; 
            }
            plikHasla.close(); 
        }
    }
    
    
    return 0;
}
