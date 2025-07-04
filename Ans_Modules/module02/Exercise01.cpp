#include <iostream>
using namespace std;

class Part {
public:
    virtual void print() = 0; // Pure virtual function to be overridden by derived classes
};

class Engine : public Part {
public:
    void print() override {
        cout << "Engine part\n";
    }

    //----SETTER
    void setEngineName(string name){
        eName = name;
    }   
    
    //----GETTER
    void getEngineName(){
        cout << "Engine Name : " << eName << endl;
    }
private:    
    string eName;
};

class Wheel : public Part {
public:
    void print() override {
        cout << "Wheel part\n";
    }

    //----SETTER
    void setWheelName(int no){
        wNo = no;
    }

    //----GETTER
    void getWheelName(){
        switch (wNo)
        {
        case 1:
            cout << "Wheel Name : FL" << endl;
            break;
        case 2:
            cout << "Wheel Name : FR" << endl;
            break;
        case 3:
            cout << "Wheel Name : RL" << endl;
            break;
        case 4:
            cout << "Wheel Name : RR" << endl;
            break;
        default:
            break;
        }
        
    }
private:
    int wNo;
};

class Brake : public Part {
public:
    void print() override {
        cout << "Brake part\n";
    }

    //----SETTER
    void setBrakeNumber(int no){
        Brake_num = no;
    }
    //----GETTER
    void getBrakeTemp(){
        switch(Brake_num){
            case 0:
                cout << "Brake Disk Temperature FL : " << Normal_diskTemp << endl;
                break;
            case 1:
                cout << "Brake Disk Temperature FR : " << Normal_diskTemp << endl;
                break;
            case 2:
                cout << "Brake Disk Temperature RL : " << Normal_diskTemp << endl;
                break;
            case 3:
                cout << "Brake Disk Temperature RR : " << Normal_diskTemp << endl;
                break;
        }
        
    }
private:
    int Brake_num;
    int Normal_diskTemp = 50;
};

class Transmission : public Part {
public:
    int current_Gear = 0;
    
    void print() override {
        cout << "Transmission part\n";
    }

    void GearUP(){
        current_Gear++;
    }

    void GearDown(){
        current_Gear--;
    }

    void printGear(){
        if(current_Gear == 0){
            cout << "GEAR : N" << endl;
        }else{
        cout << "GEAR : " << current_Gear << endl;
        }
    }
};

class Car {
public:
    Car() {
        engine_ = new Engine();
        wheels_ = new Wheel[4];
        brakes_ = new Brake[4];
        transmission_ = new Transmission();
    }
    
    void printParts() {
        engine_->print();
        for (int i = 0; i < 4; ++i) {
            wheels_[i].print();
            brakes_[i].print();
        }
        transmission_->print();
    }
    
    ~Car() {
        delete engine_;
        delete [] wheels_;
        delete [] brakes_;
        delete transmission_;
    }
    

    Engine* engine_;
    Wheel* wheels_;
    Brake* brakes_;
    Transmission* transmission_;
};

int main() {
    Car myCar;
    //myCar.printParts();
    
    //-----ENGINE PART
    myCar.engine_->print();
    myCar.engine_->setEngineName("HONDA Engine");
    myCar.engine_->getEngineName();

    //-----Wheel PART
    for(int i = 1 ; i < 5 ; i++){
        myCar.wheels_[i].setWheelName(i);
    }
    for(int i = 1 ; i < 5 ; i++){
        myCar.wheels_[i].getWheelName();
    }

    //-----Brake PART
    myCar.brakes_->print();

    for(int i = 0 ; i < 4 ; i++){
        myCar.brakes_[i].setBrakeNumber(i);
    }

    for(int i = 0 ; i < 4 ; i++){
        myCar.brakes_[i].getBrakeTemp();
    }

    //-----Transmission
    myCar.transmission_->print();
    myCar.transmission_->printGear();  //Gear N
    myCar.transmission_->GearUP();

    myCar.transmission_->printGear(); //Gear 1
    myCar.transmission_->GearUP();
    
    myCar.transmission_->printGear(); //Gear 2
    myCar.transmission_->GearUP();

    myCar.transmission_->printGear(); //Gear 3
    myCar.transmission_->GearDown();

    myCar.transmission_->printGear(); //Gear 2
    myCar.transmission_->GearDown();

    myCar.transmission_->printGear(); //Gear 1
    myCar.transmission_->GearDown();

    myCar.transmission_->printGear(); //Gear N
    return 0;
}