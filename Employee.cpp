#include<iostream>
using namespace std;

class Employee {
    private:
        string fname;
        string lname;
        double salary;
        static int numE;
    public:
        Employee() {
            numE++;
            set("First name","Last name",0.0);
        }
        Employee(string fn) {
            numE++;
            set(fn,"Last name",0.0);
        }
        Employee(string fn, string ln) {
            numE++;
            set(fn,ln,0.0);
        }
        Employee(string fn, string ln, double s) {
            numE++;
            set(fn,ln,s);
        }
        
        void set(string fn, string ln, double s){
            this->fname = fn;
            this->lname = ln;
            this->salary = s;
        }
        void setFirtsName(string fn){
            this->fname = fn;
        }
        void setLastName(string ln){
            this->lname = ln;
        }
        void setSalary(double s){
            this->salary = s;
        }

        string getFirstName() const {
            return fname;
        }
        string getLastName() const {
            return lname;
        }
        double getSalary() const {
            return salary;
        }
        string getFullName() const {
            return fname+" "+lname;
        }
        void show() const {
            cout<<"First name : "<<getFirstName()<<endl;
            cout<<"Last name : "<<getLastName()<<endl;
            cout<<"Full name :"<<getFullName()<<endl;
            cout<<"Salary : "<<getSalary()<<endl;
        }

        static int count() {
            return numE;
        }
        ~Employee() {
            numE--;
            cout<<"Test Destructor of Employee object = "<<count()<<endl;
        }
};

int Employee::numE=0;
int main() {
    cout<<"---- Test function count() ----"<<endl;
    cout<<"Number of Employee object = "<<Employee::count()<<endl;
    cout<<endl;

    Employee e1;
    Employee e2("Minnie");
    Employee e3("John","Farmer");
    Employee e4("Alice","Wonderland",70000);

    cout<<"---- Test Constructor e1 ----"<<endl;
    e1.show();
    cout<<endl;

    cout<<"---- Test Constructor e2(Minnie) ----"<<endl;
    e2.show();
    cout<<endl;

    cout<<"---- Test Constructor e3(John,Farmer) ----"<<endl;
    e3.show();
    cout<<endl;

    cout<<"---- Test Constructor e4(Alice,Wonderland,70000) ----"<<endl;
    e4.show();
    cout<<endl;

    cout<<"---- Test function count() ----"<<endl;
    cout<<"Number of Employee object = "<<Employee::count()<<endl;
    cout<<endl;

    cout<<"---- Test function e1.setFirstName(Anusorn) ----"<<endl;
    e1.setFirtsName("Anusorn");

    cout<<"---- Test function e1.setLastName(Usui) ----"<<endl;
    e1.setLastName("Usui");

    cout<<"---- Test function e1.setSalary(150000) ----"<<endl;
    e1.setSalary(150000);
    e1.show();
    cout<<endl;
}