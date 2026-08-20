#include<iostream>
#include<string.h>
using namespace std;

class Point {
    private:
        double x;
        double y;
        char name1[10];
        string name2;
        int static num;
    public:
        Point(){
            num++;
            set(1,1,"","");
        }
        Point(double x){
            num++;
            set(x,1,"","");
        }
        Point(double x, double y){
            num++;
            set(x,y,"","");
        }
        Point(double x, double y, const char *n1){
            num++;
            set(x,y,n1,"");
        }
        Point(double x, double y, const char *n1, string n2){
            num++;
            set(x,y,n1,n2);
        }

        void set(double x, double y, const char *n1, string n2){
            this->x = x;
            this->y = y;
            strcpy(name1,n1);
            this->name2 = n2;
        }
        void setX(double x){
            this->x = x;
        }
        void setY(double y){
            this->y = y;
        }
        void setName1(const char *n1){
            strcpy(name1, n1);
        }
        void setName2(string n2){
            this->name2 = n2;
        }
        
        double getX() const {
            return x;
        }
        double getY() const {
            return y;
        }
        const char* getName1() const {
            return &name1[0];
        }
        string getName2() const {
            return name2;
        }
        
        void show() const {
            cout<<"X = "<<getX()<<endl;
            cout<<"Y = "<<getY()<<endl;
            cout<<"Name1 = "<<getName1()<<endl;
            cout<<"Name2 = "<<getName2()<<endl;
            cout<<endl;
        }
        static int count() {
            return num;
        }
        
        ~Point(){
            cout<<"Bye bye "<<name2<<endl;
            num--;
        }
};
int Point::num;

