#include <iostream>
#include <string>                             //ni i xgna.. igna using namespace std;

using std::cout;
using std::cin;                                         //nie pn x..mybe bla dh gna nmespce std; so xyah kn..so xde effct..
using std::endl;

class fuel {
private:
    float volume;                  //i wt smua public =p xde private2..
    float price;
public:
    void setPrice(float);
    float getPrice();
    void setVolume(float);
    float getVolume();
    int fueling(float);
};

void fuel::setPrice(float newPrice) {
    price = newPrice;
}

float fuel::getPrice() {                           //cm ner nie ek?float pn blh?i thnk void je..xplain plz..
    return price;                                            //nie mksudnye die akn balik ke price atas 2 kn??
}

void fuel::setVolume(float requestedVolume) {
    volume = requestedVolume;
}

float fuel::getVolume(){
    return volume;
}

int fuel::fueling(float requestedVolume) {
    if (requestedVolume < volume) {//IF ELSE
        volume = volume - requestedVolume;
        return 0;
    } else {
        cout << "Maaf, minyak tidak mencukupi" << endl;
        return 1;
    }
}

class petrol : public fuel {//INHERITANCE
private:                                                        //no private..
    char* petrolName;                                                         //pe fungsi char*??
public:
    void setName(char*);
    void getname();
    int fueling(float);                        //nie nk taw sket npe..dpn int dlm float?mybe die leh tima nilai float gk??
    petrol();//CONSTRUCTOR
    ~petrol();//DESTRUCTOR
};

petrol::petrol() {                  //cm ner lak ngn yg nie?
    setPrice(1.80);
    setVolume(1000);
}

petrol::~petrol() {
    setVolume(0);             //yg nie die akn hlngkn setvolume?
}

void petrol::setName(char* newName) {
    petrolName = newName;
}

void petrol::getname() {
    cout << petrolName;
}

int petrol::fueling(float requestedVolume) {
int enoughVolume = fuel::fueling(requestedVolume);                                  //xplain bhgian nie sket..

    if (enoughVolume == 0)
 {
        float totalPrice = requestedVolume * getPrice();
        //CABUTAN BERTUAH
        if (totalPrice >= 50) {
            cout << "===============CABUTAN BERTUAH!=============" << endl;
            cout << "tahniah!! sila ambil nombor cabutan bertuah di kaunter.." << endl;
            cout << "===============CABUTAN BERTUAH!=============" << endl;
        }
        cout << "Sila bayar di kaunter: RM" << totalPrice << endl;
    }
}

class diesel : public fuel {
private:
    char* dieselName;
public:
    void setName(char*);
    void getName();
    void fueling(float);
    diesel();
    ~diesel();
};

diesel::diesel()
{
    setPrice(1.90);
    setVolume(100);
}

void diesel::setName(char* newName)               //cte sal char* newname..

 {
    dieselName = newName;
}

void diesel::getName() {
    cout << dieselName;
}

void diesel::fueling(float requestedVolume) {
    int enoughVolume = fuel::fueling(requestedVolume);                                 //cm ner nie?y pjg sgt?huhu..
    if (enoughVolume == 0)
 {
        float totalPrice = requestedVolume * getPrice();
        cout << "Sila bayar di kaunter: RM" << totalPrice << endl;
    }
}

diesel::~diesel() {
    setVolume(0);
}

int main() {
    petrol primax95;
    petrol primax97;                                                                                              //POLYMORPHISM 2-2 guna petrol tp harga lain2
    diesel dynamax;
    int running = 1;
    int choice = 0;
    float reqVolume = 0;

    primax95.setName("Primax 95");
    primax97.setName("Primax 97");
    primax97.setPrice(2.00);
    dynamax.setName("Dynamax");

    while (running == 1)
{                                                                                                                                                                 ;    //WHILE LOOP
        cout << "Sila pilih minyak:" << endl;
        cout << "1. ";primax95.getname();cout<<"(RM"<<primax95.getPrice()<<")\tbekalan isipadu: "<<primax95.getVolume()<<"liter";
        cout << endl;
        cout << "2. ";primax97.getname();cout<<"(RM"<<primax97.getPrice()<<")\tbekalan isipadu: "<<primax97.getVolume()<<"liter";                                            //sni sket..da pape yg nk gtaw?
        cout << endl;
        cout << "3. ";dynamax.getName();cout<<"(RM"<<dynamax.getPrice()<<")\tbekalan isipadu: "<<dynamax.getVolume()<<"liter";
        cout << endl;
        cin >> choice;

        switch (choice)
{                                                                                                                                                                 ;             //SWIITCH CASE
            case 1:
            {
                cout << "Sila masukkan isipadu minyak yang diperlukan:" << endl;
                cin >> reqVolume;
                primax95.fueling(reqVolume);                                                                               //sni sket..owh..mybe die rjuk primax95..eh??
                break;
            }
            case 2:
            {
                cout << "Sila masukkan isipadu minyak yang diperlukan:" << endl;
                cin >> reqVolume;
                primax97.fueling(reqVolume);
                break;
            }
            case 3:
            {
                cout << "Sila masukkan isipadu minyak yang diperlukan:" << endl;
                cin >> reqVolume;
                dynamax.fueling(reqVolume);
                break;
            }
            default:
            {
                cout << "Sila berurusniaga di kaunter" << endl;
                running = 0;
                break;
            }
        }
    }
}
