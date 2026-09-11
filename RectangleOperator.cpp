#include<iostream>
using namespace std;

class Rectangle {
    private:
        double width;
        double length;
        static int num;
    public:
        Rectangle(){
            num++;
            set(1,1);
        }
        Rectangle(double w){
            num++;
            set(w,1);
        }
        Rectangle(double w, double l){
            num++;
            set(w,l);
        }
        void set(double w, double l){
            this->width = w;
            this->length = l;
        }
        void setWidth(double w){
            this->width = w;
            if(length == 0){
                setLength(1);
            }
        }
        void setLength(double l){
            this->length = l;
            if(width == 0){
                setWidth(1);
            }
        }
        double getWidth() const {
            return width;
        }
        double getLength() const {
            return length;
        }
        double getArea() const {
            return width*length;
        }
        void show() const {
            cout<<"Width = "<<getWidth()<<endl;
            cout<<"Length = "<<getLength()<<endl;
            cout<<"Area = "<<getArea()<<endl;
        }
        Rectangle operator +(Rectangle &a){
            return Rectangle(width+a.width,length+a.length);
        }
        Rectangle operator -(Rectangle &a){
            return Rectangle(width-a.width,length-a.length);
        }
        Rectangle operator ++(){
            ++width;
            return *this;
        }
        Rectangle operator ++(int){
            return Rectangle(width,++length);
        }
        friend Rectangle operator --(Rectangle &a){
            a.width--;
            if(a.width<1){
                cout<<"Error if width <= 0 auto set 1"<<endl;
                a.width = 1;
            }
            return a;
        }
        friend Rectangle operator --(Rectangle &a, int){
            a.length--;
            if(a.length<1){
                cout<<"Error if length <= 0 auto set 1"<<endl;
                a.length = 1;
            }
            return a;
        }
        operator double(){
            return getArea();
        }
        double operator [] (int number){
            if(number<1 || number>5){
                cout<<"Invalid number set 0"<<endl;
                return 0.0;
            }
            return getArea()*number;
        }
        double operator () (string word){
            if(word == "a"){
                return getArea()+10;
            }else if(word == "b"){
                return getArea()+20;
            }else if(word == "c"){
                return getArea()+30;
            }else{
                cout<<"Invalid word set 0"<<endl;
                return 0.0;
            }
        }
        double operator () (int number){
            return getArea()+number;
        }
        double operator () (double d){
            return getArea()+d;
        }
        ~Rectangle(){
            num--;
        }
};

int Rectangle::num=0;
int main(){
    cout<<"---- Test Operator+ r3 = r1(12,8) + r2(8,4) ----"<<endl;
    Rectangle r1(12,8);
    Rectangle r2(8,4);
    Rectangle r3 = r1+r2;
    cout<<"---- r1 ----"<<endl;
    r1.show();
    cout<<"---- r2 ----"<<endl;
    r2.show();
    cout<<"---- r3 ----"<<endl;
    r3.show();
    cout<<endl;

    cout<<"---- Test Operator- r3 = r1(12,8) - r2(8,4) ----"<<endl;
    r3 = r1-r2;
    cout<<"---- r1 ----"<<endl;
    r1.show();
    cout<<"---- r2 ----"<<endl;
    r2.show();
    cout<<"---- r3 ----"<<endl;
    r3.show();
    cout<<endl;

    cout<<"---- Test Operator r2 = ++r1; ----"<<endl;
    cout<<"---- Test Operator ++r1; ----"<<endl;
    r2=++r1;
    ++r1;
    cout<<"---- r1 ----"<<endl;
    r1.show();
    cout<<"---- r2 ----"<<endl;
    r2.show();
    cout<<endl;

    cout<<"---- Test Operator r2 = r1++; ----"<<endl;
    cout<<"---- Test Operator r1++; ----"<<endl;
    r2=r1++;
    r1++;
    cout<<"---- r1 ----"<<endl;
    r1.show();
    cout<<"---- r2 ----"<<endl;
    r2.show();
    cout<<endl;

    cout<<"---- Test Operator r2 = --r1; ----"<<endl;
    cout<<"---- Test Operator --r1; ----"<<endl;
    r2=--r1;
    --r1;
    cout<<"---- r1 ----"<<endl;
    r1.show();
    cout<<"---- r2 ----"<<endl;
    r2.show();
    cout<<endl;

    cout<<"---- Test Operator r2 = r1--; ----"<<endl;
    cout<<"---- Test Operator r1--; ----"<<endl;
    r2=r1--;   
    r1--;
    cout<<"---- r1 ----"<<endl;
    r1.show();
    cout<<"---- r2 ----"<<endl;
    r2.show();
    cout<<endl;

    cout<<"---- Test Operator r1.set(12,1); ----"<<endl;
    r1.set(12,1);
    cout<<"---- Test Operator r1--; ----"<<endl;
    r1--;
    r1.show();
    cout<<"---- Test Operator r1.set(1,8); ----"<<endl;
    r1.set(1,8);
    cout<<"---- Test Operator --r1; ----"<<endl;
    --r1;
    r1.show();
    cout<<endl;
    
    cout<<"---- Test Operator r1.set(12,8); ----"<<endl;
    r1.set(12,8);
    cout<<"---- Test operator a = double(r1); ----"<<endl;
    cout<<"---- Test operator b = r1; ----"<<endl;
    cout<<"---- Test operator c = ++r1; ----"<<endl;
    double a,b,c;
    a = double(r1);
    b = r1;
    c = ++r1;
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;
    cout<<"c = "<<c<<endl;

    cout<<"---- Test subscript operator r1[int] ----"<<endl;
    int j;
    for(int i=0; i<=6; i++){
        j=r1[i];
        cout<<"r1["<<i<<"] = "<<j<<endl;
    }
    cout<<endl;

    cout<<"---- Test function call operator r1(string) ----"<<endl;
    int w,x,y,z;
    w = r1("a");
    cout<<"r1(a) = "<<w<<endl;
    x = r1("b");
    cout<<"r1(b) = "<<x<<endl;
    y = r1("c");
    cout<<"r1(c) = "<<y<<endl;
    z = r1("d");
    cout<<"r1(d) = "<<z<<endl;
    cout<<endl;

    cout<<"---- Test function call operator overload r1(int) ----"<<endl;
    for(int i=0; i<=6; i++){
        j=r1(i);
        cout<<"r1("<<i<<") = "<<j<<endl;
    }
    cout<<endl;

    cout<<"---- Test function call operator overload r1(double) ----"<<endl;
    double k = 0.4,o;
    while(k <= 2){
        o=r1(k);
        cout<<"r1("<<k<<") = "<<o<<endl;
        k = k+0.4;
    }
    cout<<endl;
}