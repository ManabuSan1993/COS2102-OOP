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
            set(w,0);
        }
        Rectangle(double w, double l){
            num++;
            set(w,l);
        }

        void set(double w, double l){
            this->width = w;
            this->length =l;
        }
        void setWidht(double w){
            this->width = w;
        }
        void setLenght(double l){
            this->length = l;
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
        double getLong() const {
            return width+length;
        }
        void show() const {
            cout<<"Width = "<<getWidth()<<endl;
            cout<<"Length = "<<getLength()<<endl;
            cout<<"Area = "<<getArea()<<endl;
            cout<<"Long = "<<getLong()<<endl;
            cout<<endl;
        }
        int count(){
            return num;
        }
        ~Rectangle(){
            cout<<"Bye bye "<<endl;
            num--;
        }
};
int Rectangle::num;
int main() {
    Rectangle r1;
    Rectangle r2(2);
    Rectangle r3(5,7);
    r1.show();
    r2.show();
    r3.show();
}
