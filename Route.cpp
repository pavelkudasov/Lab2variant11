#include "Route.h"
#include <iostream> 
void Route::setNumber(int number){
    if (number > 0){ 
        routeNumber = number;
    }
}
int Route::getNumber() const {
    return routeNumber;
}
void Route::setStartPoint(string point){
    startPoint = point;
}

string Route::getStartPoint() const{
    return startPoint;
}

void Route::setEndPoint(string point){
    endPoint = point;
}

string Route::getEndPoint() const{
    return endPoint;
}

//работа первого конструктора который является функцией класса
Route::Route(){
    startPoint = "неизвестно";
    endPoint = "Неизвестно";
    routeNumber = 0;
    std::cout << "Вызван конструктор по умолчанию" << std::endl;
}
//второй конструктор с параметрами который 
Route::Route(string start, string end, int number){
    startPoint = start;
    endPoint = end;
    routeNumber = 0;
    setNumber(number);
    std::cout << "Вызван конструктор с параметрами, в наше случае старт конец и номер" << std::endl;
}

Route::Route(const Route& other){
    startPoint = other.startPoint;
    endPoint = other.endPoint;
    routeNumber = other.routeNumber;
    std::cout << "вызван конструктор копирования" << std::endl;
}

Route::~Route(){
    std::cout << "Вызван деструктор роут" << std::endl;
}
//перегрузка вывода
ostream& operator<<(ostream& out, const Route& route){
    out << route.startPoint << " - "
        << route.endPoint << " N "
        << route.routeNumber;
    return out;
}
//перегрузка ввода
istream& operator>>(istream& in, Route& route){
    in >> route.startPoint >> route.endPoint >> route.routeNumber;
    return in;
}