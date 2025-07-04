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
    void setWheelName(string name){
        wName = name;
    }

    //----GETTER
    void getWheelName(){
        cout << "Wheel name : " << wName << endl;
    }
private:
    string wName;
};

class Brake : public Part {
public:
    void print() override {
        cout << "Brake part\n";
    }

    //----GETTER
    void getBrakeTemp(){
        cout << "Brake Disk Temperature : " << Normal_diskTemp << endl;
    }
private:
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
        cout << "GEAR : " << current_Gear << endl;
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
    myCar.printParts();
    
    //-----ENGINE PART
    myCar.engine_->setEngineName("HONDA");
    myCar.engine_->getEngineName();
    return 0;
}