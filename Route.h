#pragma once // предотвращаем повторное включение 2 раза одного заг.файла в пределах трансляции.
#include <string>
using namespace std;
#include <iostream>

class Route{
    private:
        string startPoint;
        string endPoint;
        int routeNumber;
    public:
        void setNumber(int number);
        int getNumber() const;
        //номер маршрутки 
        void setStartPoint(string point);
        string getStartPoint() const;
        //начало ее движения, ну типо первый пункт
        void setEndPoint(string point);
        string getEndPoint() const;
        //конец движения маршрутки(ну или речного такси)
        //создаем конструктор первый
        Route();
        //Конструктор - функция класса!!!ЗАПОМНИТЬ
        //конструктор с параметрами - типо функции с параметрами, только создается при объявлении класса сразу с заданными параметрами
        Route(string start, string end, int number);
        //конструктор копирования
        Route(const Route& other);//исходный объект не меняется, передаем объект по ссылке, без создания копии, и азер это имя параметра, его придумал я сам, можно что то другое поставить
        ~Route();//деструктор
        friend ostream& operator<<(ostream& out, const Route& route);//перегрузка <<, что бы выводить сообщения
        friend istream& operator>>(istream& in, Route& route);
};

