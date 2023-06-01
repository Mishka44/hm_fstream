// hm_fstream.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <clocale>
#include <Windows.h>
#include <string>
#include <vector>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "ru");


    int choice;
    do {
        std::cout << "Меню: " << "\n";
        std::cout << "Выберите в какой файл записать данные: " << "\n";
        std::cout << "1- название товара" << "\n";
        std::cout << "2 - количество товара " << "\n";
        std::cout << "3 -  цена " << "\n";
        std::cout << "4 - миновать заполнение" << "\n";
        std::cout << "5 - закрыть программу";
        std::cout << "Введите ваш выбор: " << "\n";
        std::cin >> choice;

        std::ofstream name;
        std::ofstream number;
        std::ofstream cost;

        
       
        std::string id;
        std::string id2;

      
        if (choice == 1) {
            name.open("name.txt", std::ofstream::app);
            if (!name.is_open()) {
                std::cout << "Error\n";
            }
            else {
                std::cout << "Введите название товара: " << "\n";

                std::cin >> id;
                name << id << '\n';
            }
            name.close();
        }

        else if (choice == 2) {
            number.open("number.txt", std::ofstream::app);
            if (!number.is_open()) {
                std::cout << "Error\n";
            }
            else {
                std::cout << "Введите количество товара: " << "\n";
                int num;
                std::cin >> num;
                number << num << '\n';
            }
            number.close();
        }

        else if (choice == 3) {
            cost.open("cost.txt", std::ofstream::app);
            if (!cost.is_open()) {
                std::cout << "Error\n";
            }
            else {
                std::cout << "Введите цену товара: " << "\n";
                int price;
                std::cin >> price;
                cost << price << '\n';
            }
            cost.close();
        }


        if (choice == 4) {

            std::vector<std::string> names;
            std::vector<std::string> amounts;
            std::vector<std::string> priceVector;

            std::ifstream name1;
            name1.open("name.txt");
            if (!name1.is_open()) {
                std::cout << "Error\n";
            }
            else {
                //std::cout << "file is open!";
                while (!name1.eof()) {
                    std::getline(name1, id2);
                    names.push_back(id2);
                  
                }
            }
            name1.close();


               
            std::ifstream number1;
            number1.open("number.txt");
            if (!number1.is_open()) {
                std::cout << "Error\n";
            }
            else {
                //std::cout << "file is open!";
                std::string tmp;
                while (!number1.eof()) {

                    std::getline(number1, tmp);
                    amounts.push_back(tmp);

                }
                number1.close();


                std::ifstream cost1;
                cost1.open("cost.txt");
                if (!cost1.is_open()) {
                    std::cout << "Error\n";
                }
                else {
                    //std::cout << "file is open!";
                    std::string tmp2;
                    while (!cost1.eof()) {
                        std::getline(cost1, tmp);
                        priceVector.push_back(tmp);
                    }
                    cost1.close();

                    std::cout << "ID Название Кол-во Цена" << "\n";
                    for (int i = 1; i <= names.size(); i++)
                    {
                        std::cout << i  << "  " << names[i] << "  " << amounts[i] << "  " << priceVector[i] << "\n";;
                    }
                    break;
                }
            }
        }
    }while(choice != 5);
    return 0;
}
 
