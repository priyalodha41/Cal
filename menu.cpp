#include<iostream>

using namespace std;

int Addition(int,int);
int Subtraction(int,int);
int Multiplication(int,int);
int Division(int,int);
int Modulus(int,int);

int main(){

        cout<<"Press 1 for + " <<endl;
        cout<<"Press 2 for - " <<endl;
        cout<<"Press 3 for * " <<endl;
        cout<<"Press 4 for / " <<endl;
        cout<<"Press 5 for % " <<endl;
        cout<<"Press 0 for exit " <<endl;

        int choice;
        cout<<"Enter a choice:";
        cin>>choice;

        int a,b;
        cout<<"Enter the first number: ";
        cin>>a;
        cout<<"Enter the second number: ";
        cin>>b;

        while(choice!=0){
            switch(choice){
                case 1:
                    cout<<"Addition of "<<a <<" and " << b <<" is : " <<Addition(a,b);
                    break;

                case 2:
                    cout<<"Subtraction of "<<a <<" and " << b <<" is : " <<Subtraction(a,b);
                    break;

                case 3:
                    cout<<"Multiplication of "<<a <<" and " << b <<" is : " <<Multiplication(a,b);
                    break;
                
                case 4:
                    cout<<"Division of "<<a <<" and " << b <<" is : " <<Division(a,b);
                    break;

                case 5:
                    cout<<"Modulus of "<<a <<" and " << b <<" is : " <<Modulus(a,b);
                    break;

                case 0:
                    cout<<"Please visit again!!!";
                    break;
            }
       }
    return 0;
}

int Addition(int a, int b){
    return a+b;
}

int Subtraction(int a,int b){
    if(a>b){
        return a-b;
    }
    else{
        return b-a;
    }
}
int Multiplication(int a,int b){
    return a*b;
}
int Division(int a,int b){
    return a/b;
}

int Modulus(int a,int b){
    return a%b;
}