
#include <windows.h>
#include <iostream>
#include "Route.h"


void sortRoutes(Route* routes, int size){
    // Сортировка по номеру маршрута
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (routes[j].getNumber() > routes[j + 1].getNumber()) {
                Route temp = routes[j];
                routes[j] = routes[j + 1];
                routes[j + 1] = temp;
            }
        }
    }
    

}


int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int size = 8;
    Route* routes = new Route[size];

    // Ввод маршрутов
    std::cout << "Введите 8 маршрутов (начало конец номер):" << std::endl;

    for (int i = 0; i < size; i++) {
        try {
            cout << "Маршрут " << i + 1 << ": ";
            cin >> routes[i];
            if (!cin) {
                cin.clear();// сбрасываем флаг ошибки позволяя читать данные сноваобе 
                cin.ignore(1000, '\n'); // очищаем поток ввода
                i--;
                cout << "Ошибка ввода! Попробуйте ещё раз." << endl;
            }
        }
        catch (const invalid_argument& error) {
            cout << error.what() << endl;
            i--;
        }
    }
    sortRoutes(routes, size);
    
    int choice = -1;
    
    while (choice != 0) {
        std::cout << "1. Показать маршруты" << std::endl;
        std::cout << "2. Найти маршрут" << std::endl;
        std::cout << "3. Изменить маршрут" << std::endl;
        std::cout << "4. Удаление марщрута" << std::endl;
        std::cout << "5. Добавить маршрут" << std::endl;
        std::cout << "0. Выход" << std::endl;
        std::cout << "Выберите действие: ";
        
        
        if (!(cin >> choice)) {
                break;
            }
        switch (choice) {
            case 1: {
                std::cout << "\nСписок маршрутов:" << std::endl;

                for (int i = 0; i < size; i++) {
                     cout << i + 1 << ". " << routes[i] << endl;
                }
                break;
            }

            case 2: {
                std::string city;
                bool found = false;

                std::cout << "Введите город: ";
                std::cin >> city;

                for (int i = 0; i < size; i++) {
                    if (routes[i].getStartPoint() == city ||
                        routes[i].getEndPoint() == city) {

                        found = true;
                        std::cout << routes[i] << std::endl;
                    }
                }

                if (found == false) {
                    std::cout << "Маршруты не найдены :(" << std::endl;
                }
                break;
            }
            case 3:{
                int nob;
                int nnob;
                std::cout << "Введите порядковый номер маршрута: ";
                std::cin >> nob;
                if(nob < 1){
                    cout << "Вы ввели слишком маленький номер" << endl;
                    break;
                } else if (nob > size){ 
                    cout << "Вы ввели слишком большой номер" << endl;
                    break;
                }
                std::cout << "На какой номер вы хотите поменять?";
                std::cin >> nnob;
                if (nnob <= 0) {
                    cout << "Номер маршрута должен быть положительным!" << endl;
                    break;
                }

                routes[nob - 1].setNumber(nnob);
                std::cout << "Номер маршрута изменен!" << std::endl;
                string sp;

                std::cout << "Введите новый начальный пункт: ";
                std::cin >> sp;

                routes[nob - 1].setStartPoint(sp);
                string nep;

                std::cout << "Введите новый конечный пункт: ";
                std::cin >> nep;

                routes[nob - 1].setEndPoint(nep);
                sortRoutes(routes, size);
                break;
                
            }
            case 4:{
                int nob;
                int j = 0;

                cout << "Введите порядковый номер маршрута для удаления: ";
                cin >> nob;
                if(nob < 1){
                    cout << "Вы ввели слишком маленький номер" << endl;
                    break;
                } else if (nob > size){ 
                    cout << "Вы ввели слишком большой номер" << endl;
                    break;
                }
                Route* newRoutes = new Route[size - 1];
                for(int i = 0; i < size; i++){
                    if(i != nob - 1){
                        newRoutes[j] = routes[i];
                        j++;
                    }
                }
                delete[] routes;
                routes = newRoutes;
                size--;

                cout << "Маршрут успешно удален!" << endl;

                break;
            }
            case 5: {
                int pos;

                cout << "Введите позицию нового маршрута" << endl;
                cin >> pos;

                if (pos < 1 || pos > size + 1) {
                    cout << "Некорректная позиция!" << endl;
                    break;
                }

                Route* newRoutes = new Route[size + 1];
                
                for (int i = 0; i < pos - 1; i++) {
                    newRoutes[i] = routes[i];
                }

                for (int i = pos - 1; i < size; i++) {
                    newRoutes[i + 1] = routes[i];
                }

                                
                try {
                    cin >> newRoutes[pos - 1];
                }
                catch (const invalid_argument& error) {
                    cout << error.what() << endl;
                    delete[] newRoutes;
                    break;
                }

                delete[] routes;
                routes = newRoutes;
                size++;

                sortRoutes(routes, size);

                break;
            }
            case 0:
                std::cout << "Выход из программы" << std::endl;
                break;

            default:
                std::cout << "Такого пункта меню нет!" << std::endl;
                break;
        }
    }

    // Освобождение динамической памяти
    delete[] routes;

    return 0;
}
