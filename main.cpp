#include <windows.h>
#include <iostream>
#include "Route.h"

int main(){
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    Route bus1("Москва", "Казань", 15);
    Route bus2(bus1);
    bus2.setNumber(25);
    std::cout << bus1 << std::endl;
    std::cout << bus2 << std::endl;
    std::cout << "Введите начальную точку, конечную точку и номер: ";
    Route bus3;

    std::cin >> bus3;

    std::cout << "Введенный маршрут: " << bus3 << std::endl;
    return 0;
}