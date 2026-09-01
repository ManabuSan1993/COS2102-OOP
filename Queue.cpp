#include<iostream>
using namespace std;

class Queue {
    private:
        int *q;
        int max;
        int front;
        int rear;
        int n;
        static int numQ;
        void set(int max){
            this->max = max;
            this->front = -1;
            this->rear = -1;
            q = new int[max];
        }
    public:
        Queue(){
            numQ++;
            set(10);
        }
        Queue(int max){
            numQ++;
            set(max);
        }
        
        void insert(int item){
            if ((front == 0 && rear == max-1)||(rear+1 == front)){
                cout<<"Queue is full"<<endl;
                return;
            }
            if (front == -1){
                front = 0;
                rear = 0;
            }else{
                rear = (rear + 1) % max;
            }
            q[rear] = item;
        }
        int remove(){
            if (front == -1){
                cout<<"Queue is empty"<<endl;
                return 0;
            }
            int item = q[front];
            if (front == rear){
                front = -1;
                rear = -1;
            }else{
                front = (front + 1) % max;
            }
            return item;
        }
        bool isFull() const {
            if ((front == 0) and (rear == (max-1)) or (rear == (front-1))) {
                return true;
            }else{
                return false;
            }
        }
        bool isEmpty() const {
            if (front == -1){
                return true;
            }else{
                return false;
            }
        }
        void show() const {
            int j=0;
            int i=front;
            if(isEmpty()){
                cout<<"No data (Space : "<<max<<")"<<endl;
                return;
            }
            while (true) {
                j++;
                cout<<"Queue["<<j<<"] = "<<q[i]<<endl;
                if(i == rear){
                    break;
                }
                i = (i + 1) % max;
            }
        }
        static int count(){
            return numQ;
        }
        ~Queue(){
            numQ--;
            cout<<"Test Destructor : "<<count()<<endl;
        }
};

int Queue::numQ = 0;
int main() {
    cout<<"---- Test function count() ----"<<endl;
    cout<<"Number of Queue = "<<Queue::count()<<endl;
    cout<<endl;

    cout<<"---- Test Constructor q1,q2(15) ---" << endl;
    Queue q1;
    Queue q2(15);
    q1.show();
    q2.show();
    cout<<endl;

    cout<<"---- Test q1.isEmpty() and q1.isFull() ----"<<endl;
    string test;
    if (q1.isEmpty()) {
        test = "True";
    }else{
        test = "False";
    }
    cout<<"isEmpty : "<<test<<endl;
    if (q1.isFull()) {
        test = "True";
    }else{
        test = "False";
    }
    cout<<"isFull : "<<test<<endl;
    cout<<endl;

    cout<<"---- Test q1.insert(10) ----"<<endl;
    cout<<"---- Test q1.insert(20) ----"<<endl;
    cout<<"---- Test q1.insert(30) ----"<<endl;
    q1.insert(10);
    q1.insert(20);
    q1.insert(30);
    q1.show();
    cout<<endl;

    cout<<"---- Test q1.remove() ----"<<endl;
    q1.remove();
    q1.show();
    cout<<endl;

    cout<<"---- Test q1.remove() again ----"<<endl;
    q1.remove();
    q1.show();
    cout<<endl;

    cout<<"---- q1.insert to full Queue ----"<<endl;
    q1.insert(40);
    q1.insert(50);
    q1.insert(60);
    q1.insert(70);
    q1.insert(80);
    q1.insert(90);
    q1.insert(100);
    q1.insert(10);
    q1.insert(20);
    q1.show();
    cout<<endl;

    cout<<"---- Test q1.isEmpty() and q1.isFull() ----"<<endl;
    if (q1.isEmpty()) {
        test = "True";
    }else{
        test = "False";
    }
    cout<<"isEmpty : "<<test<<endl;
    if (q1.isFull()) {
        test = "True";
    }else{
        test = "False";
    }
    cout<<"isFull : "<<test<<endl;
    cout<<endl;


}