#include <iostream>
using namespace std;

// Abstract Base Class
class Car {
private:
    string make;
    string model;
    int year;
public:
    Car(string make, string model, int year) : make(make), model(model), year(year) {}
    Car() : make("Unknown"), model("Unknown"), year(0) {}

    // Setters
    void setMake(const string& m) { make = m; }
    void setModel(const string& m) { model = m; }
    void setYear(int y) { year = y; }

    // Getters
    string getMake() const { return make; }
    string getModel() const { return model; }
    int getYear() const { return year; }

    // Virtual method for Polymorphism
    virtual void drive() const {
        cout << "Drive mode ACTIVATE" << endl;
        cout << "Made by: " << make << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
    }

    // Virtual destructor for proper cleanup
    virtual ~Car() {}
};

// Derived class
class SportsCar : public Car {
private:
    int top_speed;
public:
    SportsCar(string make, string model, int year, int speed = 0) : Car(make, model, year), top_speed(speed) {}

    void setTopSpeed(int speed) { top_speed = speed; }
    int getTopSpeed() const { return top_speed; }

    void drive() const override {
        Car::drive();
        cout << "Top Speed: " << top_speed << " km/h" << endl;
    }
};

int main() {
    Car* car = new Car("Volkswagen", "Golf", 2014);
    car->drive();
    cout << "--------------------------" << endl;

    Car* sportsCar = new SportsCar("Porsche", "911", 2018, 300);
    sportsCar->drive();

    delete car;
    delete sportsCar;

    return 0;
}
