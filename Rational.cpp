#include<iostream>
using namespace std;

class Rational {
    private:
        int numerator;
        int denominator;
        static int numR;
    public:
        Rational(){
            numR++;
            set(1,1);
        }
        Rational(int n){
            numR++;
            set(n,1);
        }
        Rational(int n, int d){
            numR++;
            set(n,d);
        }

        void set(int n, int d){
            this->numerator = n;
            this->denominator = d;
        }
        void setNumerator(int n){
            this->numerator = n;
        }
        void setDenominator(int d){
            this->denominator = d;
        }

        int getNumerator() const {
            return numerator;
        }
        int getDenominator() const {
            return denominator;
        }
        double getQuotient() const {
            return (float)numerator/denominator;
        }
        void show() const {
            cout<<"Numerator = "<<getNumerator()<<endl;
            cout<<"Denominator = "<<getDenominator()<<endl;
            cout<<"Quotient = "<<getQuotient()<<endl;
        }
        static int count() {
            return numR;
        }

        ~Rational(){
            numR--;
            cout<<"Test count() of Rational object : "<<count()<<endl;
        }
};

int Rational::numR=0;
int main() {
    cout<<"---- Test Rational function count() ----"<<endl;
    cout<<"---- count() Object of class Rational = "<<Rational::count()<<endl;
    cout<<endl;

    Rational r1;
    Rational r2(7);
    Rational r3(12,3);

    cout<<"---- Test Constructor r1 ----"<<endl;
    r1.show();
    cout<<endl;

    cout<<"---- Test Constructor r2(7) ----"<<endl;
    r2.show();
    cout<<endl;

    cout<<"---- Test Constructor r3(12,3) ----"<<endl;
    r3.show();
    cout<<endl;

    cout<<"---- Test Rational function count() ----"<<endl;
    cout<<"---- count() Object of class Rational = "<<Rational::count()<<endl;
    cout<<endl;

    cout<<"---- Test r1.setNumerator(15) ----"<<endl;
    r1.setNumerator(15);

    cout<<"---- Test r1.setDenominator(4) ----"<<endl;
    r1.setDenominator(4);
    r1.show();
    cout<<endl;

}