#include<iostream>
#include<cmath>
using namespace std;

class Complex {
    private:
        double x;
        double y;
        static int numC;
    public:
        Complex(){
            numC++;
            set(1,1);
        }
        Complex(double x){
            numC++;
            set(x,1);
        }
        Complex(double x, double y){
            numC++;
            set(x,y);
        }
        
        void set(double x, double y){
            this->x = x;
            this->y = y;
        }
        void setX(double x){
            this->x = x;
        }
        void setY(double y){
            this->y = y;
        }

        double getX() const {
            return x;
        }
        double getY() const {
            return y;
        }
        double getComplex() const {
            return sqrt((x*x)+(y*y));
        }
        
        void show() const {
            cout<<"X = "<<getX()<<endl;
            cout<<"Y = "<<getY()<<endl;
            cout<<"Complex calculate = "<<getComplex()<<endl;
        }
        static int count(){
            return numC;
        }
        ~Complex(){
            numC--;
            cout<<"Destructor test numC-- : "<<count()<<endl;
        }
};

int Complex::numC=0;
int main(){
    cout<<"---- Test function count() ----"<<endl;
    cout<<"Number of Complex object : "<<Complex::count()<<endl;
    cout<<endl;

    Complex c1;
    Complex c2(4.5);
    Complex c3(4.1,4.8);

    cout<<"---- Test Constructor Complex c1() ----"<<endl;
    c1.show();
    cout<<endl;

    cout<<"---- Test Constructor Complex c2(4.5) ----"<<endl;
    c2.show();
    cout<<endl;

    cout<<"---- Test Constructor Complex c3(4.1,4.8) ----"<<endl;
    c3.show();
    cout<<endl;

    cout<<"---- Test function count() ----"<<endl;
    cout<<"Number of Complex object : "<<Complex::count()<<endl;
    cout<<endl;

    cout<<"---- Test c1.setX(14.2) ----"<<endl;
    c1.setX(14.2);

    cout<<"---- Test c1.setY(7.8) ----"<<endl;
    c1.setY(7.8);
    c1.show();
    cout<<endl;
}