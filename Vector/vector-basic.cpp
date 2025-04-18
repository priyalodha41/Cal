#include<iostream>

#include<vector>

using namespace std;



class MemoryCalculate{
    public:
        int Id;
        string Name;

        MemoryCalculate(int Id, string Name){
            this->Id=Id;
            this->Name=Name; 
        }

        void display(){
            cout<<"\n----------------------------------------------------\n";
            cout<<"The id of the student is : "<<this->Id <<endl;
            cout<<"The name of the student is : "<<this->Name <<endl;
            cout<<"----------------------------------------------------\n";
        }

        int togetID(){
            return this->Id;
        }
};

int main(){

    vector <MemoryCalculate> list;

    int choice;

    do{
        cout<<"\n----------------------------------------------------\n";
        cout<<"Press 1 To add the student in the list" <<endl;
        cout<<"Press 2 To display all the student in the list" <<endl;
        cout<<"Press 3 To remove the student from the list from Id" <<endl;
        cout<<"Press 4 To search a student by ID" <<endl;
        cout<<"Press 0 To exit the list of students" <<endl;
        cout<<"----------------------------------------------------\n";

        cout<<"Enter the choice : ";
        cin>>choice;

        switch(choice){

            case 1:{
                int Id;
                string Name;
                cout<<"Enter the Id :";
                cin>>Id;
                cin.ignore();
                cout<<"Enter your name :";
                getline(cin,Name);

                list.push_back(MemoryCalculate(Id,Name));

                cout<<"\n----------------------------------------------------\n";
                cout<<"Successfully added to the list..";
                cout<<"\n----------------------------------------------------\n";
                break;
            }
            case 2:{
                
                for(int i=0; i<list.size(); i++){
                    list[i].display();
                }
                break;
            }
            
            case 3:{
                int Id;
                cout<<"Enter the Id :";
                cin>>Id;
                bool flag=false;
                for(int i=0; i<list.size(); i++){
                    if(list[i].togetID()==Id){
                        flag=true;
                        list.erase(list.begin()+i);
                        cout<<"Id has been deleted successfully......."<<endl;
                    }
                }
                if(flag==false){
                    cout<<"Id is not found in the list";
                }
                break;
            }
            case 4:{

                int Id;
                cout<<"Enter the Id :";
                cin>>Id;
                bool flag=false;

                for(int i=0; i<list.size(); i++){
                    if(list[i].togetID()==Id){
                        flag=1;
                        list[i].display();
                    }
                }
                if(flag==false){
                    cout<<"Id is not found in the list";
                }
                break;
            }

            case 0:{
                cout<<"Thank you visit again......."<<endl;
                break;
            }
        }

    }while(choice!=0);




    return 0;
}