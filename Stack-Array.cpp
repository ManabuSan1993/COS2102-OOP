#include<iostream>
using namespace std;

class Stack {
    private:
        string *stk;
        int max;
        int top;
        void set(int m) {
            this->max = m;
            this->top = -1;
            stk = new string[max];
        }
    public:
        Stack(){
            set(10);
        }
        Stack(int m) {
            set(m);
        }
        
        void push(string item){
            if(top == (max-1)){
                cout<<"No space"<<endl;
            }else{
                top++;
                stk[top] = item;
                cout<<"Added ["<<item<<"] complete"<<endl;
            }
        }
        void pop(){
            if (top == -1) {
                cout<<"No data please try again"<<endl;
            }else{
                cout<<"Delete item : "<<stk[top]<<endl;
                stk[top] = "";
                top--;
                cout<<"Delete complete"<<endl;
            }        
        }
        bool isFull() const {
            return top == max-1;
        }
        bool isEmpty() const {
            return top == -1;
        }
        void show() const {
            cout<<"Max of Stack = "<<max<<endl;
            if(top == -1){
                cout<<"No data please try again"<<endl;
            }else{
                for(int i=0; i<=top; i++){
                    cout<<"Stack["<<i+1<<"] = "<<stk[i]<<endl;
                }
            }  
        }
        int count() const {
            return top+1;
        }
        ~Stack(){
            cout<<"Test Destructor Bye Bye"<<endl;
            delete[] stk;
        }
};

int main() {
    cout<<"---- Test Constructor stk1 ----"<<endl;
    Stack stk1;
    stk1.show();
    cout<<"Test function stk1.count() item of Stack : "<<stk1.count()<<endl;
    cout<<endl;

    cout<<"---- Test Constructor stk2(20) ----"<<endl;
    Stack stk2(20);
    stk2.show();
    cout<<endl;

    cout<<"---- Test function stk1.push(Apple) ----"<<endl;
    stk1.push("Apple");
    stk1.show();
    cout<<endl;

    cout<<"---- Test function stk1.push(Apple) ----"<<endl;
    stk1.push("Beer");
    stk1.show();
    cout<<endl;

    cout<<"---- Test function stk1.push(Apple) ----"<<endl;
    stk1.push("Cola");
    stk1.show();
    cout<<endl;

    cout<<"---- Test function stk1.push(Apple) ----"<<endl;
    stk1.push("Ice tea");
    stk1.show();
    cout<<endl;

    cout<<"---- Test function stk1.push(Apple) ----"<<endl;
    stk1.push("Milk");
    stk1.show();
    cout<<endl;

    cout<<"---- Test function stk1.pop() ----"<<endl;
    stk1.pop();
    stk1.show();
    cout<<endl;

    cout<<"---- Test function stk1.pop() ----"<<endl;
    stk1.pop();
    stk1.show();
    cout<<endl;
}