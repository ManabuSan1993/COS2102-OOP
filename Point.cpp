#include<iostream>
using namespace std;

class Point {
    private:
        double x;
        double y;
        string name;
        static int numP;
    public:
        Point(){
            numP++;
            set(0,0,"Name");
        }
        Point(double x){
            numP++;
            set(x,0,"Name");
        }
        Point(double x, double y){
            numP++;
            set(x,y,"Name");
        }
        Point(double x, double y, string name){
            numP++;
            set(x,y,name);
        }

        void set(double x, double y, string name){
            this->x = x;
            this->y = y;
            this->name = name;
        }
        void setX(double x){
            this->x = x;
        }
        void setY(double y){
            this->y = y;
        }
        void setName(string name){
            this->name = name;
        }
        void midpoint(Point& p1, Point& p2) {
            this->x = (p1.x + p2.x)/2;
            this->y = (p1.y + p2.y)/2;
        }

        double getX() const {
            return x;
        }
        double getY() const {
            return y;
        }
        string getName() const {
            return name;
        }
        double dot(Point& d) const {
            int x = this->x*d.x;
            int y = this->y*d.y;
            return x+y;
        }
        
        void show() const {
            cout<<"X = "<<getX()<<endl;
            cout<<"Y = "<<getY()<<endl;
            cout<<"Name = "<<getName()<<endl;
        }
        static int count(){
            return numP;
        }

        ~Point(){
            numP--;
            cout<<"Test Destructor = "<<count()<<endl;
        }
};

int Point::numP=0;

int main(){
    cout<<"---- Test function count() ----"<<endl;
    cout<<"Number of object Point = "<<Point::count()<<endl;
    cout<<endl;

    Point p1;
    Point p2(2.1);
    Point p3(2.4,2.2);
    Point p4(4,7,"Point 4");
    cout<<"---- Test counstructor ----"<<endl;
    cout<<"---- Point p1 ----"<<endl;
    p1.show();
    cout<<endl;

    cout<<"---- Point p2(2.1) ----"<<endl;
    p2.show();
    cout<<endl;

    cout<<"---- Point p3(2.4, 2.2) ----"<<endl;
    p3.show();
    cout<<endl;

    cout<<"---- Point p4(4, 7, Point 4) ----"<<endl;
    p4.show();
    cout<<endl;

    cout<<"---- Test function p1.set(4, 3, Point 1) ----"<<endl;
    p1.set(4,3,"Point 1");
    p1.show();
    cout<<endl;

    cout<<"---- Test function p2.setX(5) ----"<<endl;
    p2.setX(5);
    p2.show();
    cout<<endl;

    cout<<"---- Test function p2.setY(4) ----"<<endl;
    p2.setY(4);
    p2.show();
    cout<<endl;

    cout<<"---- Test function p2.setName(Point 2) ----"<<endl;
    p2.setName("Poiint 2");
    p2.show();
    cout<<endl;

    cout<<"---- Test function p3.midpoint(p1, p2) ----"<<endl;
    p3.midpoint(p1,p2);
    p3.show();
    cout<<endl;

    cout<<"---- Test function p4.dot(p1) ----"<<endl;
    p4.dot(p1);
    p4.show();
    cout<<endl;
    
    cout<<"---- Test function count() ----"<<endl;
    cout<<"Number of object Point = "<<Point::count()<<endl;
    cout<<endl;
}