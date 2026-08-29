#include<iostream>
using namespace std;

class Address {
    private:
        string houseNumber;
        string subDistric;
        string distric;
        string province;
        static int numA;
    public:
        Address(){
            numA++;
            set("House number","Sub distric","Distric","Province");
        }
        Address(string hn){
            numA++;
            set(hn,"Sub distric","Distric","Province");
        }
        Address(string hn, string sd){
            numA++;
            set(hn,sd,"Distric","Province");
        }
        Address(string hn, string sd, string d){
            numA++;
            set(hn,sd,d,"Province");
        }
        Address(string hn, string sd, string d, string p){
            numA++;
            set(hn,sd,d,p);
        }

        void set(string hn, string sd, string d, string p){
            this->houseNumber = hn;
            this->subDistric = sd;
            this->distric = d;
            this->province = p;
        }
        void setHouseNumber(string hn){
            this->houseNumber = hn;
        }
        void setSubDistric(string sd){
            this->subDistric = sd;
        }
        void setDistric(string d){
            this->distric = d;
        }
        void setProvince(string p){
            this->province = p;
        }
        
        string getHouseNumber() const {
            return houseNumber;
        }
        string getSubDistric() const {
            return subDistric;
        }
        string getDistric() const {
            return distric;
        }
        string getProvince() const {
            return province;
        }
        void show() const {
            cout<<"House number : "<<getHouseNumber()<<endl;
            cout<<"Sub distric : "<<getSubDistric()<<endl;
            cout<<"Distric : "<<getDistric()<<endl;
            cout<<"Province : "<<getProvince()<<endl;
        }

        static int count(){
            return numA;
        }
        ~Address(){
            numA--;
            cout<<"Destructor test numA-- : "<<count()<<endl;
        }
};

int Address::numA=0;
int main(){
    cout<<"---- Test function count() ----"<<endl;
    cout<<"Number of Address object : "<<Address::count()<<endl;
    cout<<endl;
    
    Address a1;
    Address a2("1/1");
    Address a3("1/2","huamak");
    Address a4("1/3","huamak","bang kapi");
    Address a5("1/4","huamak","bang kapi","bangkok");

    cout<<"---- Test constructor Address a1 ----"<<endl;
    a1.show();
    cout<<endl;

    cout<<"---- Test constructor Address a2 ----"<<endl;
    a2.show();
    cout<<endl;

    cout<<"---- Test constructor Address a3 ----"<<endl;
    a3.show();
    cout<<endl;

    cout<<"---- Test constructor Address a4 ----"<<endl;
    a4.show();
    cout<<endl;

    cout<<"---- Test constructor Address a5 ----"<<endl;
    a5.show();
    cout<<endl;

    cout<<"---- Test function count() ----"<<endl;
    cout<<"Number of Address object : "<<Address::count()<<endl;
    cout<<endl;

    cout<<"---- Test setHouseNumber(2/2)) a1 ----"<<endl;
    a1.setHouseNumber("2/2");

    cout<<"---- Test setSubDistric(Huamak) a1 ----"<<endl;
    a1.setSubDistric("Huamak");

    cout<<"---- Test setDistric(Bangkapi) a1 ----"<<endl;
    a1.setDistric("Bang kapi");

    cout<<"---- Test setProvince(Bangkok) a1 ----"<<endl;
    a1.setProvince("Bangkok");
    a1.show();
    cout<<endl;
}