#include <iostream>
using namespace std;

class Car{
    private:
        string name;
        int speed;
    public:
        Car(){
            this->name = "None";
            this->speed = 0;
        };
        Car(string name, int speed){ //생성자 constructor
            cout <<"Constructor\n";
            this->name = name;
            this->speed = speed;
        }   
        Car(string name){ //위임 생성자 delegating constructor
            Car(name, 0); 
        }
        Car(int speed){   //위임 생성자 delegating constructor
            Car("None", speed);
        }

        void setName(string name){
            this->name = name;
        }   
        void setSpeed(int speed){
            this-> speed = speed;
        }

        void print(){
            cout << "Name : " << this->name << endl;
            cout << "Speed : " << this->speed << endl;
        }

        Car(const Car& original){  //복사 생성자 copy constructor
            cout << "Copy Constructor\n";
            this->name = original.name;
            this->speed = original.speed;
        }
        Car& operator=(const Car &c){   //복사 대입 연산자 Copy assignment operator override
            this->name = c.name;
            this->speed = c.speed;

            cout << "Copy assignment operator\n";
            return *this;
        }


        //----------------------------------------------------------------------------------
        ~Car(){
            cout << "Destructor\n" ;
        }
};   

int main(){
    Car car;
    car.setName("Hyundai");
    car.setSpeed(200);
    car.print();


    Car copy(car);
    Car cp = car;
    cp.print();
    car = cp;

}