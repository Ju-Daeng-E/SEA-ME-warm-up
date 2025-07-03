#include <iostream>
#include <vector>
using namespace std;


struct Personal{
    string name;
    string number;
    string nickname;
    bool bookmark;
};

vector<Personal> PB;
bool isUnique(string num){
    for(int i = 0 ; i < PB.size() ; i++){
        if(PB[i].number == num) return false;
    }
    return true;
};

int main(){
    string cmd, name, num, nick;

    int sChoose;
    while(1){
        Personal p;
        cout << "Enter Command"<<endl;
        cout << "ADD, SEARCH, REMOVE, BOOKMARK, EXIT" << endl << endl;

        cin >> cmd;

        if(cmd == "ADD"){
            cout << "Name : " ; 
            cin >> name;
            
            cout << "Phone Number : ";
            cin >> num;
            while(isUnique(num) == 0){
                cout << "Not Unique Number" << endl; 
                cout << "Enter again Phone Number : ";
                cin >> num;
            };
            cout << "Nickname : ";
            cin >> nick;

            p.name = name;
            p.number = num;
            p.nickname = nick;
            p.bookmark = false;
            PB.push_back(p);
            cout << endl;
        }

        else if(cmd == "SEARCH"){
            cout << "Name list with index" << endl <<endl;

            for(int i = 0 ; i < PB.size(); i++){
                cout << i << "  " ;
                cout << PB[i].name << endl;
            }
            cout << endl;
            cout << "Enter 1 to display details of the contact" << endl;
            cout << "Enter 2 to bookmark" << endl;
            
            
            cin >> sChoose;

            if(sChoose == 1){
                int select;
                cout << "Enter index number to see details : ";
                cin >> select;
                
                cout << "Name : " << PB[select].name << endl;
                cout << "Phone Number : " << PB[select].number << endl;
                cout << "Nickname : " << PB[select].nickname << endl << endl;
            }else if(sChoose == 2){
                int select;
                cout << "Enter index number to bookmark : ";
                cin >> select;

                PB[select].bookmark = true;
                cout << "Successfully Bookmarked!" << endl << endl; 
            }else{
                cout << "Invalid Number" << endl;
            }

        }
        else if(cmd == "REMOVE"){
            int idx;
            cout << "Enter index to remove : ";

            cin >> idx;

            PB.erase(PB.begin() + idx);
            cout << endl;
        }
        else if(cmd == "BOOKMARK"){
            int cnt = 0;
            cout << "List up Bookmarked Name" << endl << endl;
            for(int i = 0 ; i < PB.size() ; i++){
                if(PB[i].bookmark == true){
                    cout << "Name : " << PB[i].name << endl;
                }
            }
            if(cnt == 0){
                cout << "There is no BookMark" << endl;
            }
            cout << endl;
        }else if(cmd == "EXIT"){
            return 0;
        }
        else{
            cerr << "INVALID COMMAND !!" << endl;
        }

    }
}

