#include<iostream>
using namespace std;

class Matrix {
    private:
        int row;
        int column;
        int **m;
        static int numM;
    public:
        Matrix(){
            m = 0;
            numM++;
            set(1,1);
        }
        Matrix(int r){
            m = 0;
            numM++;
            set(r,1);
        }
        Matrix(int r, int c){
            m = 0;
            numM++;
            set(r,c);
        }
        
        void set(int r, int c){
            reset();
            this->row = r;
            this->column = c;
            setM();
        }
        void setRow(int r){
            set(r,column);
        }
        void setColumn(int c){
            set(row,c);
        }
        void setM(){
            m = new int*[row];
            for(int i=0; i<row; i++){
                m[i] = new int[column];
                for(int j=0; j<column; j++){
                    m[i][j] = 0;
                }
            }
        }
        void setMatrix(int r, int c, double item){
            m[r][c] = item;
        }
        void reset(){
            if(m!=0){
                for(int i=0; i<row; i++){
                    delete[] m[i];
                }
                delete[] m;
                m=0;
            }   
        }

        int getRow() const {
            return row;
        }
        int getColumn() const {
            return column;
        }
        int getM(int r, int c) const {
            return m[r][c];
        }
        static int count(){
            return numM;
        }
        void show() const {
            cout<<"--- Size of Matrix---"<<endl;
            cout<<"Row = "<<getRow()<<", Column = "<<getColumn()<<endl;
            for(int i=0; i<row; i++){
                for(int j=0; j<column; j++){
                    cout<<" "<<m[i][j]<<" ";
                }
                cout<<endl;
            }
        }
        ~Matrix(){
            numM--;
            reset();
        }
};
int Matrix::numM=0;

int main(){
    cout<<"---- Test function count() ----"<<endl;
    cout<<"Number of Matrix object = "<<Matrix::count()<<endl;
    cout<<endl;

    cout<<"---- Test Constructor m1 ----"<<endl;
    Matrix m1;
    m1.show();
    cout<<endl;

    cout<<"---- Test Constructor m2(4) ----"<<endl;
    Matrix m2(4);
    m2.show();
    cout<<endl;

    cout<<"---- Test Constructor m3(7,8) ----"<<endl;
    Matrix m3(7,8);
    m3.show();
    cout<<endl;

    cout<<"---- Test m1.setRow(3) ----"<<endl;
    cout<<"---- Test m1.setColumn(3) ----"<<endl;
    m1.setRow(3);
    m1.setColumn(3);
    m1.show();
    cout<<endl;

    cout<<"---- Test m1.setMatrix(0,0,7) ----"<<endl;
    cout<<"---- Test m1.setMatrix(1,1,2) ----"<<endl;
    m1.setMatrix(0,0,7);
    m1.setMatrix(1,1,2);
    m1.show();
}