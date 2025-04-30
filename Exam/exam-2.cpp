#include<iostream>

using namespace std;
class Stack{

    private:
        int size;
        string *arr;
        int count;
        int top;

    public:
        Stack(int size){
            this->size=size;
            this->arr= new string[size];
            this->top=-1;
            this->count=0;
        }

        void topush(string data);
        bool isPalindrome(string);
};
void Stack::topush(string data){
    for(int i=0; i<5 ;i++){
       
    }
}
bool isPalindrome(string name){
}
int main(){
    
    Stack s1(5);

    string name;
    cout<<"Enter the string:";
    cin>>name;

    s1.topush(name);

    return 0;
}
