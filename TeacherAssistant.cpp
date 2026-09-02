#include<iostream>
using namespace std;

class Address {
    private:
        string houseNum;
        string subDistrict;
        string district;
        string provinc;
        static int numA;
    public:
        Address(){
            numA++;
            set("houseNum","subDistrict","district","provinc");
        }
        Address(string hn){
            numA++;
            set(hn,"subDistrict","district","provinc");
        }
        Address(string hn, string sd){
            numA++;
            set(hn,sd,"district","provinc");
        }
        Address(string hn, string sd, string d){
            numA++;
            set(hn,sd,d,"provinc");
        }
        Address(string hn, string sd, string d, string p){
            numA++;
            set(hn,sd,d,p);
        }

        void set(string hn, string sd, string d, string p){
            this->houseNum = hn;
            this->subDistrict = sd;
            this->district = d;
            this->provinc = p;
        }
        void setHouseNum(string hn){
            this->houseNum = hn;
        }
        void setSubDistrict(string sd){
            this->subDistrict = sd;
        }
        void setDistrict(string d){
            this->district = d;
        }
        void setProvince(string p){
            this->provinc = p;
        }

        string getHouseNum() const {
            return houseNum;
        }
        string getSubDistrict() const {
            return subDistrict;
        }
        string getDistrict() const {
            return district;
        }
        string getProvince() const {
            return provinc;
        }

        void show() const {
            cout<<"House Number = "<<getHouseNum()<<endl;
            cout<<"Sub District = "<<getSubDistrict()<<endl;
            cout<<"District = "<<getDistrict()<<endl;
            cout<<"Province = "<<getProvince()<<endl;
        }
        static int count() {
            return numA;
        }
        ~Address(){
            numA--;
        }
};
class Date {
    private:
        int day;
        int month;
        int years;
        static int numD;
    public:
        Date(){
            numD++;
            set(0,0,0);
        }
        Date(int d){
            numD++;
            set(d,0,0);
        }
        Date(int d, int m){
            numD++;
            set(d,m,0);
        }
        Date(int d, int m, int y){
            numD++;
            set(d,m,y);
        }

        void set(int d, int m, int y){
            this->day = d;
            this->month = m;
            this->years = y;
        }
        void setDay(int d){
            this->day = d;
        }
        void setMonth(int m){
            this->month = m;
        }
        void setYears(int y){
            this->years = y;
        }

        int getDay() const {
            return day;
        }
        int getMonth() const {
            return month;
        }
        int getYears() const {
            return years;
        }
        void show() const {
            cout<<"Birth Day = "<<getDay()<<"/"<<getMonth()<<"/"<<getYears()<<endl;      
        }
        ~Date() {
            numD--;
        }
};
class Person {
    private:
        string id;
        string name;
        Address address;
        Date birth;
        static int numP;
    public:
        Person(){
            numP++;
            set("ID","Name",{},{});
        }
        Person(string id){
            numP++;
            set(id,"",{},{});
        }
        Person(string id, string name){
            numP++;
            set(id,name,{},{});
        }
        Person(string id, string name, Address ad){
            numP++;
            set(id,name,ad,{});
        }
        Person(string id, string name, Address ad, Date b){
            numP++;
            set(id,name,ad,b);
        }

        void set(string id, string name, Address ad, Date b){
            this->id = id;
            this->name = name;
            this->address = ad;
            this->birth = b;
        }
        void setId(string id){
            this->id = id;
        }
        void setName(string name){
            this->name = name;
        }
        void setAddress(Address ad){
            this->address = ad;
        }
        void setDate(Date b){
            this->birth = b;
        }
        string getId() const {
            return id;
        }
        string getName() const {
            return name;
        }
        Address getAddress() const {
            return address;
        }
        Date getDate() const {
            return birth;
        }
        void show() const {
            cout<<"ID = "<<getId()<<endl;
            cout<<"Name = "<<getName()<<endl;
            address.show();
            birth.show();
        }
        static int count(){
            return numP;
        }
        ~Person(){
            numP--;
        }
};
class Student:virtual public Person {
    private:
        string studentID;
        string faculty;
        string department;
        double grade;
        static int numStd;
    public:
        Student(){
            numStd++;
            set("studentID","faculty","department",0.0);
        }
        Student(string stdId){
            numStd++;
            set(stdId,"faculty","department",0.0);
        }
        Student(string stdId, string f){
            numStd++;
            set(stdId,f,"department",0.0);
        }
        Student(string stdId, string f, string dp){
            numStd++;
            set(stdId,f,dp,0.0);
        }
        Student(string stdId, string f, string dp, double g){
            numStd++;
            set(stdId,f,dp,g);
        }
        Student(string stdId, string f, string dp, double g, string id):Person(id) {
            numStd++;
            set(stdId,f,dp,g);
        }
        Student(string stdId, string f, string dp, double g, string id, string name):Person(id,name) {
            numStd++;
            set(stdId,f,dp,g);
        }
        Student(string stdId, string f, string dp, double g, string id, string name, Address ad):Person(id,name,ad) {
            numStd++;
            set(stdId,f,dp,g);
        }
        Student(string stdId, string f, string dp, double g, string id, string name, Address ad, Date d):Person(id,name,ad,d) {
            numStd++;
            set(stdId,f,dp,g);
        }

        void set(string stdId, string f, string dp, double g){
            this->studentID = stdId;
            this->faculty = f;
            this->department = dp;
            this->grade = g;
        }
        void setStudentID(string stdId){
            this->studentID = stdId;
        }
        void setFaculty(string f){
            this->faculty = f;
        }       
        void setDepartment(string dp){
            this->department = dp;
        }  
        void setGrade(double g){
            this->grade = g;
        }  

        string getStudentID() const {
            return studentID;
        }
        string getFaculty() const {
            return faculty;
        }
        string getDepartment() const {
            return department;
        }
        double getGrade() const {
            return grade;
        }
        void show() const {
            cout<<"StudentID = "<<getStudentID()<<endl;
            cout<<"Faculty = "<<getFaculty()<<endl;
            cout<<"Department = "<<getDepartment()<<endl;
            cout<<"Grade = "<<getGrade()<<endl;
        }
        static int count() {
            return numStd;
        }
        ~Student(){
            numStd--;
        }
};
class Teacher:virtual public Person {
    private:
        string teacherID;
        string faculty;
        string department;
        double salary;
        static int numTch;
    public:
        Teacher(){
            numTch++;
            set("teacherID","faculty","department",0.0);
        }
        Teacher(string tchId){
            numTch++;
            set(tchId,"faculty","department",0.0);
        }
        Teacher(string tchId, string f){
            numTch++;
            set(tchId,f,"department",0.0);
        }
        Teacher(string tchId, string f, string dp){
            numTch++;
            set(tchId,f,dp,0.0);
        }
        Teacher(string tchId, string f, string dp, double s){
            numTch++;
            set(tchId,f,dp,s);
        }
        Teacher(string tchId, string f, string dp, double s, string id) {
            numTch++;
            set(tchId,f,dp,s);
            Person::set(id,"Name",{},{});
        }
        Teacher(string tchId, string f, string dp, double s, string id, string name){
            numTch++;
            set(tchId,f,dp,s);
            Person::set(id,name,{},{});
        }
        Teacher(string tchId, string f, string dp, double s, string id, string name, Address ad){
            numTch++;
            set(tchId,f,dp,s);
            Person::set(id,name,ad,{});
        }
        Teacher(string tchId, string f, string dp, double s, string id, string name, Address ad, Date d):Person(id,name,ad,d) {
            numTch++;
            set(tchId,f,dp,s);
        }
        
        void set(string tchId, string f, string dp, double s){
            this->teacherID = tchId;
            this->faculty = f;
            this->department = dp;
            this->salary = s;
        }
        void setTeacherID(string tchId){
            this->teacherID = tchId;
        }
        void setFaculty(string f){
            this->faculty = f;
        }             
        void setDepartment(string dp){
            this->department = dp;
        }  
        void setSalary(double s){
            this->salary = s;
        }  

        string getTeacherID() const {
            return teacherID;
        }
        string getFaculty() const {
            return faculty;
        }
        string getDepartment() const {
            return department;
        }
        double getSalary() const {
            return salary;
        }
        void show() const {
            cout<<"TeacherID = "<<getTeacherID()<<endl;
            cout<<"Faculty = "<<getFaculty()<<endl;
            cout<<"Department = "<<getDepartment()<<endl;
            cout<<"Salary = "<<getSalary()<<endl;
        }
        static int count(){
            return numTch;
        }
        ~Teacher(){
            numTch--;
        }
};
class TeachingAssistant: public Student, public Teacher {
    private:
        string certificate;
        static int numTA;
    public:
        TeachingAssistant(){
            numTA++;
            set("Certificate");
        }
        TeachingAssistant(string cer, string stdId, string faculty, string department, double grade):Student(stdId,faculty,department,grade){
            numTA++;
            set(cer);
        }
        TeachingAssistant(string cer, string stdId, string faculty, string department, double grade, string id, string name, Address addr, Date dat){
            numTA++;
            set(cer);
            Student::set(stdId,faculty,department,grade);
            Person::set(id,name,addr,dat);
        }
        TeachingAssistant(string cer, string stdId, string faculty, string department, double grade, string id, string name, Address addr, Date dat, string tchId, string facTch, string dpTch, double salary):Student(stdId,faculty,department,grade), Person(id,name,addr,dat),Teacher(tchId,facTch,dpTch,salary) {
            numTA++;
            set(cer);
        }
        
        void set(string c) {
            this->certificate = c;
        }
        void setCertificate(string c) {
            this->certificate = c;
        }
        void setStudentFaculty(string sf){
            Student::setFaculty(sf);
        }
        void setStudentDepartment(string sd){
            Student::setDepartment(sd);
        }
        void setTeacherFaculty(string tf){
            Teacher::setFaculty(tf);
        }
        void setTeacherDepartment(string td){
            Teacher::setDepartment(td);
        }

        string getCertificate() const {
            return certificate;
        }
        string getStudentFaculty() const {
            return Student::getFaculty();
        }
        string getStudentDepartment() const {
            return Student::getDepartment();
        }
        string getTeacherFaculty() const {
            return Teacher::getFaculty();
        }
        string getTeacherDepartment() const {
            return Teacher::getDepartment();
        }
        
        void show() const {
            cout<<"---- Teaching assistant information ----"<<endl;
            Person::show();
            cout<<"Certificate = "<<getCertificate()<<endl;
            cout<<"   --     Part of Student    --"<<endl;
            Student::show();
            cout<<"   --     Part of Teacher    --"<<endl;
            Teacher::show();
        }
        static int count() {
            return numTA;
        }
        ~TeachingAssistant(){
            numTA--;
            cout<<"Test Destructor = "<<TeachingAssistant::count()<<endl;
        }
};

int Person::numP=0;
int Address::numA=0;
int Date::numD=0;
int Student::numStd=0;
int Teacher::numTch=0;
int TeachingAssistant::numTA=0;

int main() {
    Address a1("1/2","Huamak","Bang kapi","Bangkok");
    cout<<"Test constructor Address(1/2,Huamak,Bang kapi,Bangkok)"<<endl;
    cout<<"----- address -----"<<endl;
    a1.show();
    cout<<endl;
    cout<<endl;

    Date d1(7,3,1993);
    cout<<"Test constructor Date(7,3,1993)"<<endl;
    cout<<"----- Date -----"<<endl;
    d1.show();
    cout<<endl;
    cout<<endl;

    cout<<"---- Test function count() ----"<<endl;
    cout<<"Number of TeachingAssistant object = "<<TeachingAssistant::count()<<endl;
    cout<<endl;
    cout<<endl;

    TeachingAssistant ta1;
    cout<<"Test constructor ta1()"<<endl;
    cout<<"------------------ TeachingAssistant 1 ---------------------"<<endl;
    ta1.show();
    cout<<endl;
    cout<<endl;

    TeachingAssistant ta2("Toeic 700 Point","680003","Science","Computer",3.75);
    cout<<"Test constructor ta2(1,2,3,4,5)"<<endl;
    cout<<"------------------ TeachingAssistant 2 ---------------------"<<endl;
    ta2.show();
    cout<<endl;
    cout<<endl;

    TeachingAssistant ta3("Toeic 700 Point","680003","Science","Computer",3.75,"1509901297102","Anusorn Usui",a1,d1);
    cout<<"Test constructor ta3(1,2,3,4,5,6,7,8,9)"<<endl;
    cout<<"------------------ TeachingAssistant 3 ---------------------"<<endl;
    ta3.show();
    cout<<endl;
    cout<<endl;

    TeachingAssistant ta4("Toeic 700 Point","680003","Science","Computer",3.75,"1509901297102","Anusorn Usui",a1,d1,"theacher680","Science","Computer",7250.75);
    cout<<"Test constructor ta4.(1,2,3,4,5,6,7,8,9,10,11,12,13))"<<endl;
    cout<<"------------------ TeachingAssistant 4 ---------------------"<<endl;
    ta4.show();
    cout<<endl;
    cout<<endl;

    cout<<"----Test ta4.setStudentFaculty(Science Fac)----"<<endl;
    cout<<"----Test ta4.setStudentDepartment(Computer sci)----"<<endl;
    cout<<"----Test ta4.setTeacherFaculty(Business Administration)----"<<endl;
    cout<<"----Test ta4.setTeacherDepartment(Accounting)----"<<endl;
    cout<<endl;
    cout<<endl;
    ta4.setStudentFaculty("Science Fac");
    ta4.setStudentDepartment("Computer sci");
    ta4.setTeacherFaculty("Business Administration");
    ta4.setTeacherDepartment("Accounting");
    ta4.show();
    cout<<endl;
    cout<<endl;

    cout<<"---- Test function count() ----"<<endl;
    cout<<"Number of TeachingAssistant object = "<<TeachingAssistant::count()<<endl;
    cout<<endl;

}
