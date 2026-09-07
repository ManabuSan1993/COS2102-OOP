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
            set(1,1,"Name");
        }
        Point(double x){
            numP++;
            set(x,1,"Name");
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
        double getX() const {
            return this->x;
        }
        double getY() const {
            return this->y;
        }
        string getName() const {
            return this->name;
        }
        void show() const {
            cout<<"Point name = "<<getName()<<endl;
            cout<<"X = "<<getX()<<endl;
            cout<<"Y = "<<getY()<<endl;
        }
        static int count() {
            return numP;
        }
        ~Point(){
            numP--;
        }
};
class MyPoint {
    private:
        int size;
        Point *point;
        static int numMP;
    public:
        MyPoint(){
            size = 0;
            point = 0;
            numMP++;
        }
        MyPoint(Point &p){
            size = 0;
            point = 0;
            numMP++;
            setSize(1);
            setPoint(0,p);
        }
        void reset(){
            if(size!=0){
                delete[] point;
            }
            point = 0;
        }
        void setSize(int size){
            reset();
            this->size = size;
            point = new Point[size];
        }
        void setPoint(int index, Point &p){
            if(size==0){
                cout<<"Please set size of array first"<<endl;
            }else{
                point[index] = p;
            }
        }
        Point getPoint(int index) const {
            return point[index];
        }
        int getSize() const {
            return size;
        }
        void show() const {
            cout<<"Size of Mypoint = "<<getSize()<<endl;
            if (size == 0){
                cout<<"No data"<<endl;
            }
            for(int i=0; i<size; i++){
                cout<<"---- point["<<i<<"] ----"<<endl; 
                point[i].show();
                cout<<endl;
            }
        }
        static int count() {
            return numMP;
        }
        ~MyPoint(){
            numMP--;
            reset();
        }
};
int Point::numP=0;
int MyPoint::numMP=0;

int main(){
    cout<<"---- Test function Point::count() ----"<<endl;
    cout<<"number of Point object = "<<Point::count()<<endl;
    cout<<endl;

    cout<<"---- Test function MyPoint::count() ----"<<endl;
    cout<<"number of MyPoint object = "<<MyPoint::count()<<endl;
    cout<<endl;

    cout<<"---- Make Point p1(1,2,Point1) p2(3,4,Point2) p3(5,6.5,Point3) ----"<<endl;
    Point p1(1,2,"Point1");
    Point p2(3,4,"Point2");
    Point p3(5,6.5,"Point3");
    p1.show();
    cout<<endl;
    p2.show();
    cout<<endl;
    p3.show();
    cout<<endl;

    cout<<"---- Test Constructor MyPoint mp1 ----"<<endl;
    MyPoint mp1;
    mp1.show();
    cout<<endl;

    cout<<"---- Test Constructor MyPoint mp2(p3) ----"<<endl;
    MyPoint mp2(p3);
    mp2.show();
    cout<<endl;

    cout<<"---- Test mp1.setSize(2) ----"<<endl;
    mp1.setSize(2);
    mp1.show();
    cout<<endl;

    cout<<"---- Test mp1.setPoint(0,p2) ----"<<endl;
    cout<<"---- Test mp1.setPoint(1,p1) ----"<<endl;
    mp1.setPoint(0,p2);
    mp1.setPoint(1,p1);
    mp1.show();
    cout<<endl;
}