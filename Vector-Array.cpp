#include<iostream>
using namespace std;

class Vector {
    private:
        int *a;
        int size;
        static int numV;
        void set(int s) {
            this->size =s;
            a = new int[size];
        }
    public:
        Vector() {
            numV++;
            set(2);
            setVector();
        }
        Vector(int s) {
            numV++;
            set(s);
            setVector();
        }

        void setVector(){
            int num;
            cout<<"Enter number of vector position"<<endl;
            for (int i=0; i<=size-1; i++) {
                cout<<"Position "<<i+1<<" : ";
                cin>>num;
                a[i] = num;
            }
        }
        void setReSize(int s){
            delete[] a;
            set(s);
        }

        Vector getVector() const {
            return *this;
        }
        void show() const {
            for(int i=0; i<=size-1; i++){
                cout<<"Position "<<i+1<<" : "<<a[i]<<endl;
            }
        }
        
        static int count() {
            return numV;
        }
        ~Vector(){
            numV--;
            delete[] a;
            cout<<"Test Destructor object Vector : "<<count()<<endl;
        }
};

int Vector::numV=0;
int main() {
    cout<<"---- Test function count() ----"<<endl;
    cout<<"Number of Vector object : "<<Vector::count()<<endl;
    cout<<endl;

    Vector v1;
    Vector v2(3);

    cout<<"---- Test Constructor v1 ----"<<endl;
    v1.show();
    cout<<endl;

    cout<<"---- Test Constructor v2(2) ----"<<endl;
    v2.show();
    cout<<endl;

    cout<<"---- Test function count() ----"<<endl;
    cout<<"Number of Vector object : "<<Vector::count()<<endl;
    cout<<endl;

    v1.setReSize(4);
    v1.setVector();
    cout<<endl;
    cout<<"---- Test v1.setReSize(4) ----"<<endl;
    cout<<"---- Test v1.setVector() ----"<<endl;
    v1.show();
    cout<<endl;
}