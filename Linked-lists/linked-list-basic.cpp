#include<iostream>


using namespace std;


class Node{
    public:
        int data;
        Node *next;

        Node(){}
        Node(int data){
            this->data=data;
            this->next=NULL;
        }

};

class Linkedlist : public Node {

    public: 
        int count;
        Node *head;

        Linkedlist(){
            this->head=NULL;
            this->count=0;
        }

        void insertatstart(int data){

            Node *newNode= new Node(data);
            newNode->next=this->head;
            this->head=newNode;

            cout<<"\n------------------------------------------\n";
            cout<<"Insertion successful"<<endl;
            cout<<"\n------------------------------------------\n";
            this->count++;
        }
        void insertatend(int data){
            Node *newNode=new Node(data);

            if(this->count==0 || this->head==NULL){
                newNode->next=this->head;
                this->head=newNode;
            }   
            else{
                Node *temp=this->head;

                while(temp->next!=NULL){
                    temp=temp->next;
                }
                temp->next=newNode;
                newNode->next=NULL;
            }
            cout<<"\n------------------------------------------\n";
            cout<<"Insertion successful"<<endl;
            cout<<"\n------------------------------------------\n";
            this->count++;
        }

        void deleteatany(int pos){

            if(this->count==0 || pos==0){
                cout<<"Linked list is empty.."<<endl;
                return;
            }
           
            else{
                Node *prev=this->head;
                Node *current=this->head;
    
                for(int i=0; i<pos; i++){
                    current=current->next;
                }
                for(int i=0; i<pos-1; i++){
                    prev=prev->next;
                }
    
                prev->next=current->next;
                delete current;
                current=NULL;
    
                prev=NULL;
                delete prev;

                cout<<"\n------------------------------------------\n";
                cout<<"Deletion successful"<<endl;
                cout<<"\n------------------------------------------\n";

                this->count--;
            }
        }
        void searchinglist(int pos){
            
            Node *temp=this->head;

            if(this->count<pos){
                cout<<"Invalid position........"<<endl;
                return;
            }
           else{
                for(int i=0; i<count; i++){
                    if(pos==i){
                        cout<<"Searched data : "<<temp->data<<" "; 
                    }
                    temp=temp->next;
                }
           }
        }
        void viewlist(){
            Node *temp=this->head;

            while(temp!=NULL){
                cout<<temp->data<<"->";
                temp=temp->next;
            }
            cout<<"NULL";
        }
};
    
int main(){
    
    Linkedlist list;
    int choice;
    
    
    do{
        
        cout<<"\n------------------------------------------\n";
        cout<<"Press 1 for Inserting at the start"<<endl;
        cout<<"Press 2 for Inserting at the end"<<endl;
        cout<<"Press 3 for Deleting at any position"<<endl;
        cout<<"Press 4 for Searching the list by the postition"<<endl;
        cout<<"Press 5 for View list"<<endl;
        cout<<"Press 0 for Exit"<<endl;
        cout<<"------------------------------------------\n";
        cout<<"Enter the choice : ";
        cin>>choice;
    

        switch(choice){

            case 1:{
                int data;
                cout<<"Enter the data u want to insert:";
                cin>>data;

                list.insertatstart(data);

                break;
            }
            case 2:{
                int data;
                cout<<"Enter the data u want to insert:";
                cin>>data;

                list.insertatend(data);

                break;
            }

            case 3:{

                int pos;
                cout<<"Enter the position at which u want your data deleted:";
                cin>>pos;

                list.deleteatany(pos);
                break;

            }

            case 4:{
                int pos;
                cout<<"Enter the position u want to data of:";
                cin>>pos;

                list.searchinglist(pos);

                break;
            }
            case 5:{

                list.viewlist();
            }
        }

    }while(choice!=0);



    return 0;
}