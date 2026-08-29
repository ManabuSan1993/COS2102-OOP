#include<iostream>
using namespace std;

class Person {
    private:
        string id;
        string name;
        string birth;
        static int num;
    public:
        Person(){
            num++;
            set("","","");
        }
        Person(string id){
            num++;
            set(id,"","");
        }
        Person(string id, string name){
            num++;
            set(id,name,"");
        }
        Person(string id, string name, string birth){
            num++;
            set(id,name,birth);
        }
        void set(string id, string name, string birth){
            this->id = id;
            this->name = name;
            this->birth = birth;
        }
        void setId(string id){
            this->id = id;
        }
        void setName(string name){
            this->name = name;
        }
        void setBirth(string birth){
            this->birth = birth;
        }
        string getId() const {
            return id;
        }
        string getName() const {
            return name;
        }
        string getBirth() const {
            return birth;
        }
        void show() const {
            cout<<"ID = "<<getId()<<endl;
            cout<<"Name = "<<getName()<<endl;
            cout<<"Birth = "<<getBirth()<<endl;
            cout<<endl;
        }
        static int count(){
            return num++;
        }
        ~Person(){
            cout<<"Bye Bye "<<name<<endl;
            num--;
        }
};

int Person::num=0;
int main() {

    cout<<"Object of Person class : "<<Person::count()<<endl;
    Person p1;
    Person p2("1244575886125");
    Person p3("1244575886125","Anusorn Usui3");
    Person p4("1244575886125","Anusorn Usui4","07/03/1993");
    p1.show();
    p2.show();
    p3.show();
    p4.show();
}
