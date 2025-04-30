#include<iostream>

using namespace std;

class Stack{

    private:
        int size;
        int *arr;
        int count;
        int top;

    public:
        Stack(int size){
            this->size=size;
            this->arr= new int[size];
            this->top=-1;
            this->count=0;
        }

        void topush(int data);
        void topop();
        void display();
        bool isEmpty();
        bool isFull();
};

void Stack::topush(int data){
    
    if(this->top==this->size-1){
        cout<<"Stack is full......"<<endl;
        return;
    }
    if(this->count > this->size){
        cout<<"Stack is overflown..."<<endl;
        return;
    }
    else{
        this->top++;
        this->arr[this->top]=data;
        this->count++;
    }
    cout<<"\n-----------------------------------\n";
    cout<<"Element is successfully pushed"<<endl;
    cout<<"-------------------------------------\n";
}
void Stack::topop(){
    
    if(this->top==-1){
        cout<<"Stack is empty or underflown..."<<endl;
        return;
    }
    else{
        this->arr[this->top]=0;
        this->count--;
        this->top++;
    }

    
    cout<<"\n-----------------------------------\n";
    cout<<"Element is successfully popped"<<endl;
    cout<<"-------------------------------------\n";
}
void Stack::display(){

    if(this->top==-1){
        cout<<"Stack is empty..."<<endl;
        return;
    }
    else{
        for(int i=count-1; i>=0 ; i--){
            cout<<"|"<<arr[i]<<"|"<<endl;
        }
    }
}
bool Stack::isEmpty(){
    return this->count==0 ? true : false;
}
bool Stack::isFull(){
    return this->count==this->size ? true : false;
}


int main(){
    
    Stack s1(5);
    int choice;
    
    do{
        cout<<"\n----------------------------------------------\n";
        cout<<"Enter 1: To push the element inside the stack"<<endl;
        cout<<"Enter 2: To pop the element from stack"<<endl;
        cout<<"Enter 3: To check the stack is empty or not"<<endl;
        cout<<"Enter 4: To check the stack is full or not"<<endl;
        cout<<"Enter 5: To display all the elements"<<endl;
        cout<<"Enter 0: To exit from the stack"<<endl;
        cout<<"----------------------------------------------\n";
        
        cout<<"Enter your choice :" ;
        cin>>choice;
        
        switch(choice){
            case 1:{
                int data;
                cout<<"Enter the data u want to push :";
                cin>>data;
                s1.topush(data);
                break;
            }
            case 2:{
                s1.topop();
                break;
            }
            case 3:{
                if(s1.isEmpty()==true){
                    cout<<"\n----------------------------------------------\n";
                    cout<<"Stack is empty....."<<endl;
                    cout<<"\n----------------------------------------------\n";
                }
                else{
                    cout<<"\n----------------------------------------------\n";
                    cout<<"Stack is not empty..."<<endl;
                    cout<<"\n----------------------------------------------\n";
                }
                
            }
            case 4:{
                if(s1.isFull()==true){
                    cout<<"\n----------------------------------------------\n";
                    cout<<"Stack is Full....."<<endl;
                    cout<<"\n----------------------------------------------\n";
                }
                else{
                    cout<<"\n----------------------------------------------\n";
                    cout<<"Stack is Not Full..."<<endl;
                    cout<<"\n----------------------------------------------\n";
                }
                
            }
            case 5:{
                s1.display();
                break;
            }
            case 0:{
                cout<<"\n----------------------------------------------\n";
                cout<<"Thank you for using the stack.."<<endl;
                cout<<"\n----------------------------------------------\n";
                break;
            }

        }
    }while(choice!=0);

    return 0;
 }