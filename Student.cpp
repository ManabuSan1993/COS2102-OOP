#include<iostream>
using namespace std;

class Student {
    private:
        string ID;
        string name;
        string birth;
        string studentID;
        string faculty;
        double grade;
        static int numStd;
    public:
        Student() {
            numStd++;
            set("ID","Name","Birth","Student ID","Faculty",0.0);
        }
        Student(string ID) {
            numStd++;
            set(ID,"Name","Birth","Student ID","Faculty",0.0);
        }
        Student(string ID, string n) {
            numStd++;
            set(ID,n,"Birth","Student ID","Faculty",0.0);
        }
        Student(string ID, string n, string b) {
            numStd++;
            set(ID,n,b,"Student ID","Faculty",0.0);
        }
        Student(string ID, string n, string b, string stdId) {
            numStd++;
            set(ID,n,b,stdId,"Faculty",0.0);
        }
        Student(string ID, string n, string b, string stdId, string f) {
            numStd++;
            set(ID,n,b,stdId,f,0.0);
        }
        Student(string ID, string n, string b, string stdId, string f, double g) {
            numStd++;
            set(ID,n,b,stdId,f,g);
        }

        void set(string ID, string n, string b, string stdId, string f, double g){
            this->ID = ID;
            this->name = n;
            this->birth = b;
            this->studentID = stdId;
            this->faculty = f;
            this->grade = g;
        }
        void setID(string ID){
            this->ID = ID;
        }
        void setName(string n){
            this->name = n;
        }
        void setBirth(string b){
            this->birth = b;
        }
        void setStudentID(string stdId){
            this->studentID = stdId;
        }
        void setFaculty(string f){
            this->faculty = f;
        }
        void setGrade(double g){
            this->grade = g;
        }

        string getID() const {
            return ID;
        }
        string getName() const {
            return name;
        }
        string getBirth() const {
            return birth;
        }
        string getStudentID() const {
            return studentID;
        }
        string getFaculty() const {
            return faculty;
        }
        double getGrade() const {
            return grade;
        }
        
        void show() const {
            cout<<"ID : "<<getID()<<endl;
            cout<<"Name : "<<getName()<<endl;
            cout<<"Birth : "<<getBirth()<<endl;
            cout<<"Student ID : "<<getStudentID()<<endl;
            cout<<"Faculty : "<<getFaculty()<<endl;
            cout<<"Grade : "<<getGrade()<<endl;
        }
        static int count() {
            return numStd;
        }

        ~Student(){
            numStd--;
            cout<<"Destructor test num-- : "<<count()<<endl;
        }
};

int Student::numStd=0;
int main() {
    Student s1;
    Student s2("100002");
    Student s3("100003","Alice");
    Student s4("100004","Balloon","01/01/1993");
    Student s5("100005","william","02/02/1994","STD005");
    Student s6("100006","Lemon","03/03/1995","STD006","Science Faculty");
    Student s7("100007","Dazy","04/04/1992","STD007","Science Faculty",3.75);

    cout<<"---- Test function count(); ----"<<endl;
    cout<<"Num of Student object : "<<Student::count()<<endl;
    cout<<endl;

    cout<<"---- Test Constructor s1 ----"<<endl;
    s1.show();
    cout<<endl;

    cout<<"---- Test Constructor s2 ----"<<endl;
    s2.show();
    cout<<endl;

    cout<<"---- Test Constructor s3 ----"<<endl;
    s3.show();
    cout<<endl;

    cout<<"---- Test Constructor s4 ----"<<endl;
    s4.show();
    cout<<endl;

    cout<<"---- Test Constructor s5 ----"<<endl;
    s5.show();
    cout<<endl;

    cout<<"---- Test Constructor s6 ----"<<endl;
    s6.show();
    cout<<endl;

    cout<<"---- Test Constructor s7 ----"<<endl;
    s7.show();
    cout<<endl;

    cout<<"---- Test function count(); ----"<<endl;
    cout<<"Num of Student object : "<<Student::count()<<endl;
    cout<<endl;

    cout<<"---- Test function s1.setID(100001) ----"<<endl;
    s1.setID("100001");

    cout<<"---- Test function s1.setName(John) ----"<<endl;
    s1.setName("John");

    cout<<"---- Test function s1.setBirth(07/03/1993) ----"<<endl;
    s1.setBirth("07/03/1993");

    cout<<"---- Test function s1.setStudentID(STD001) ----"<<endl;
    s1.setStudentID("STD001");

    cout<<"---- Test function s1.setFaculty(Science Faculty) ----"<<endl;
    s1.setFaculty("Science Faculty");

    cout<<"---- Test function s1.setGrade(3.25) ----"<<endl;
    s1.setGrade(3.25);
    s1.show();
    cout<<endl;
}