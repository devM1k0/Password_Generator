#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

std::pair<std::string, int> menu(){
    std::string program;
    int znaki;

    std::cout << "Witaj w generatorze haseł, plik z hasłami znajduje sie w lokalizacji pliku wykonywalnego." << '\n';
    std::cout << "Do czego chcesz wygenerowac hasło?" << '\n';
    std::cin >> program;

    std::cout << "Ile znaków ma mieć hasło?" << '\n';
    std::cin >> znaki;
    while (true)
    {
        if (std::cin.good())
        {
            break;
        }
        else
        {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Podaj liczbe!" << '\n';
        std::cin >> znaki;
        }
        
    }
    
    return {program, znaki};
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

    std::ifstream sprawdzenie("hasla.txt");
    
    std::string zawartosc;
    std::vector<std::string> hasla;

    std::srand(std::time(0));

    if (!sprawdzenie)
    {
        std::ofstream stworz("hasla.txt");

        stworz << "Twoje hasła: ";

        stworz.close();

        std::cout << "Utworzono plik z hasłami, uruchom ponownie by wygenerować hasło";
    }
    else
    {

        auto [program, znaki] = menu();

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
    return 0;
}