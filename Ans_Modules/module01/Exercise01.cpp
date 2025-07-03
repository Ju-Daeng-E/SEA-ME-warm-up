#include <iostream>
using namespace std;

class Car{
    protected:
        string make;
        string model;
        int year;
    public:
        Car(string make, string model, int year){
            this->make = make;
            this->model = model;
            this->year = year;
        };
        Car(){};
        void drive(){
            cout << "Drive mode ACTIVATE" << endl;
            cout << "Made by : " << this->make << endl;
            cout << "Model : " << this->model << endl;
            cout << "Year : " << this->year << endl;
        }
        
};

class SportsCar : public Car {
    protected:
        int top_speed;
    public: 
        SportsCar(string make, string model, int year){
            this->make = make;
            this->model = model;
            this->year = year;
        }
        void setTopspeed(int speed){
            this->top_speed = speed;
        }
        void drive(){
            Car::drive();
            cout << endl;
            cout << "Top Speed : " << this->top_speed;
        }
};

int main(){
    Car car("Volkswagen", "Golf", 2014);
    car.drive();

    SportsCar sc("Porche","911", 2018);
    sc.setTopspeed(300);
    sc.drive();
}