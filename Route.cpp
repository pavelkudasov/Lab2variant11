#include "Route.h"
#include <iostream> 
#include <stdexcept>
#include <string>
using namespace std;
void Route::setNumber(int number){
    if (number > 0){ 
        routeNumber = number;
    } else{
        throw invalid_argument("Номер маршрута должен быть положительным");
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
    cout << "Конструктор по умолчанию: " << this << endl;
}
//второй конструктор с параметрами который 
Route::Route(string start, string end, int number){
    startPoint = start;
    endPoint = end;
    routeNumber = 0;
    setNumber(number);
    cout << "Конструктор с параметрами: " << this << endl;
}

Route::Route(const Route& other){
    startPoint = other.startPoint;
    endPoint = other.endPoint;
    routeNumber = other.routeNumber;
    cout << "Конструктор копирования: " << this << endl;
}

Route::~Route() {
    cout << "Деструктор объекта по адресу " << this << endl;
}
//перегрузка вывода
ostream& operator<<(ostream& out, const Route& route){
    out << route.startPoint << " - "
        << route.endPoint << " N "
        << route.routeNumber;
    return out;
}

istream& operator>>(istream& in, Route& route){
    int number;

    in >> route.startPoint >> route.endPoint >> number;
    
    if(in){
        route.setNumber(number);
    }
    
    return in;
}