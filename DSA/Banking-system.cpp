#include<iostream>

using namespace std;


class BankAccount{

    protected:
        int accountNumber;
        string accountHolderName;
        double balance;

    public:
        BankAccount(){
            accountNumber=0;
            accountHolderName="";
            balance=0;

        }
        void setaccountdetails(int accountNumber, string accountHolderName, double balance){
            this->accountNumber=accountNumber;
            this->accountHolderName=accountHolderName;
            this->balance=balance;
        }  
        void getaccountdetails(){
            cout<<"\n--------------------------------------------------------\n";
            cout<<"The accountHolderName : "<<this->accountHolderName <<endl;
            cout<<"The accountNumber : "<<this->accountNumber <<endl;
            cout<<"Balance in the account : "<<this->balance <<endl;
            cout<<"\n--------------------------------------------------------\n";
        }
        
        void deposit(double amount){
            this->balance=this->balance+amount;
        }
        void withdraw(double amount){
            if(this->balance>amount){
                this->balance=this->balance-amount;
            }
            else{
                cout<<"The value entered for withdraw is invalid";
            }
        }
        int getaccountnumber(){
           return this->accountNumber;
        }
        double getbalance(){
            return this->balance;
        }
};

class SavingAccount : public BankAccount{
    float interest=5.5;
    void calulateinterest(){
        this->balance= this->balance + (( this->balance*interest)/100);
    }
};

class CurrentAccount : public BankAccount{
};
class FixedDepositAccount : public BankAccount{
    float time=6, interest=5.5;
    void calulateinterest(){
        this->balance= this->balance + ((( this->balance*interest)/100)*time);
    }
};


int main(){

    int size;
    cout<<"Enter the size : ";
    cin>>size;
    SavingAccount sa[size];
    CurrentAccount ca[size];
    FixedDepositAccount fd[size];

    int savingaccountindex=0;
    int currentaccountindex=0;
    int fixedtaccountindex=0;

    int choice;

    do{
        cout<<"\n--------------------------------------------------------\n";
        cout<<"1.Press for Creating Saving account...." <<endl;
        cout<<"2.Press for Creating  Current account...." <<endl;
        cout<<"3.Press for Creating Fixed Deposit account...." <<endl;
        cout<<"4.Press for Depositing ...." <<endl;
        cout<<"5.Press for Withdrawing ...." <<endl;
        cout<<"0.Press for exiting the program" <<endl;
        cout<<"\n--------------------------------------------------------\n";
        cout<<"Enter the choice : " <<endl;
        cin>>choice;

        switch(choice){

            case 1:{
                int accountNumber;
                string accountHolderName;
                double balance;

                cin.ignore();

                cout<<"Enter accountholdername : " <<endl;
                getline(cin,accountHolderName);

                cout<<"Enter the accountNumber : " <<endl;
                cin>>accountNumber;

                cout<<"Enter the balance : " <<endl;
                cin>>balance;

                sa[savingaccountindex].setaccountdetails(accountNumber,accountHolderName,balance);
                savingaccountindex++;
                break;
            }
            case 2:{
                int accountNumber;
                string accountHolderName;
                double balance;

                cin.ignore();

                cout<<"Enter accountholdername : " <<endl;
                getline(cin,accountHolderName);

                cout<<"Enter the accountNumber : " <<endl;
                cin>>accountNumber;

                cout<<"Enter the balance : " <<endl;
                cin>>balance;

                ca[currentaccountindex].setaccountdetails(accountNumber,accountHolderName,balance);
                currentaccountindex++;
                break;
            }
            case 3:{
                int accountNumber;
                string accountHolderName;
                double balance;

                cin.ignore();

                cout<<"Enter accountholdername : " <<endl;
                getline(cin,accountHolderName);

                cout<<"Enter the accountNumber : " <<endl;
                cin>>accountNumber;

                cout<<"Enter the balance : " <<endl;
                cin>>balance;

                fd[fixedtaccountindex].setaccountdetails(accountNumber,accountHolderName,balance);
                fixedtaccountindex++;
                break;
            }
            case 4:{
                int accountNumber;
                double amount;
                
                cout<<"Enter the accountNumber : " <<endl;
                cin>>accountNumber;
      
                cout<<"Enter the amount u want to deposit:"<<endl;
                cin>>amount;
             
                
                for(int i=0; i<savingaccountindex; i++){
                    if(sa[i].getaccountnumber()==accountNumber){
                        sa[i].deposit(amount);
                    }
                    cout<<"Updated Balance :"<<sa[i].getbalance();
                }

                for(int i=0; i<currentaccountindex; i++){
                    if(ca[i].getaccountnumber()==accountNumber){
                        ca[i].deposit(amount);
                    }
                    cout<<"Updated Balance :"<<ca[i].getbalance();
                }

                for(int i=0; i<fixedtaccountindex; i++){
                    if(fd[i].getaccountnumber()==accountNumber){
                        fd[i].deposit(amount);
                    }
                    cout<<"Updated Balance :"<<fd[i].getbalance();
                }
                break;
             }
            
            case 5:{
                int accountNumber;
                double amount;
                
                cout<<"Enter the accountNumber : " <<endl;
                cin>>accountNumber;
      
                cout<<"Enter the amount u want to withdraw:"<<endl;
                cin>>amount;
    

                for(int i=0; i<savingaccountindex; i++){
                    if(sa[i].getaccountnumber()==accountNumber){
                        sa[i].withdraw(amount);
                    }
                    cout<<"Updated Balance :"<<sa[i].getbalance();
                }
                for(int i=0; i<currentaccountindex; i++){
                    if(ca[i].getaccountnumber()==accountNumber){
                        ca[i].withdraw(amount);
                    }
                    cout<<"Updated Balance :"<<ca[i].getbalance();
                }
                for(int i=0; i<fixedtaccountindex; i++){
                    if(fd[i].getaccountnumber()==accountNumber){
                        fd[i].withdraw(amount);
                    }
                    cout<<"Updated Balance :"<<fd[i].getbalance();
                }
                break;
            
            }
            case 0:
                cout<<"Thank you foer visiting again...............";
                break;
        }

    }while(choice!=0);


    return 0;
}


