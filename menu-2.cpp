#include<iostream>

#include<vector>

using namespace std;


class sorting{
    public:
        void quicksort(vector<int>&arr,int start,int end){

            if(start>=end) return;


            int part=partition(arr,start,end);

            quicksort(arr,start,part-1);
            quicksort(arr,part+1,end);

        }
        int partition(vector<int>& arr, int start, int end) {
            int pivot = arr[start];
            int count = 0;


            for (int i = start + 1; i <= end; i++) {
            if (arr[i] <= pivot) {
                count++;
                 }
            }

            int pindx = start + count;

            int temp = arr[pindx];
            arr[pindx] = arr[start];
            arr[start] = temp;

            int i = start, j = end;

            while (i < pindx && j > pindx) {
            while (arr[i] <= pivot) i++;
            while (arr[j] > pivot) j--;

            if (i < pindx && j > pindx) {
                int t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;

                i++;
                j--;
        }
    }

    return pindx;
}

        void display(vector<int>&arr){
            for(int val:arr){
                cout<<val<<" ";
            }
            cout<<endl;
        }

};

class Node{

    public:
        int data;
        Node* next;

        Node(){};

        Node(int data){
            this->data=data;
            this->next=NULL;
        };
};

class Linkedlist :public Node{

   public:
        Node *head;
        int count;

        Linkedlist(){
            this->head=NULL;
            this->count=0;
        };

        void toinsertatstart(int data){

            Node* newnode = new Node(data);
            newnode->next = this->head;
            this->head = newnode;
            count++;
            
            cout<<"\nSuccessfully inserted......."<<endl;
            
        }
        void todeleteatstart(){
            
            Node* temp = this->head;
            
            if (head == NULL) {
                cout << "Linked list is empty..............\n";
                return;
            }
            
            this->head = head->next;
            delete temp;
            count--;
            
            cout<<"\nSuccessfully Deleted at start......."<<endl;
        }
        void todeleterandom(int pos) {
            if (pos < 0 || pos >= count) {
                cout << "Invalid position.........."<<endl;
                return;
            }
            if (pos == 0) {
                todeleteatstart();
                return;
            }
            Node* temp = this->head;
            for (int i = 0; i < pos - 1; i++) {
                temp = temp->next;
            }
            Node* Delete = temp->next;
            temp->next = Delete->next;
            delete Delete;
            count--;

            cout<<"\nSuccessfully Deleted at  " << pos <<"......."<<endl;

        }
        void todeleteend() {
            if (this->head == NULL) {
                cout << "Linked list is empty......."<<endl;
                return;
            }
            if (head->next == NULL) {
                delete this->head;
                this->head = NULL;
            } else {
                Node* temp = this->head;
                while (temp->next->next != NULL) {
                    temp = temp->next;
                }
                delete temp->next;
                temp->next = NULL;
            }
            count--;
                      
            cout<<"\nSuccessfully Deleted at end......."<<endl;
        }

        void todisplay() {
            
            Node* temp = this->head;

            if (this->head == NULL) {
                cout << "Linked list is empty............."<<endl;
                return;
            }
            while (temp != NULL ) {
            cout << temp->data << " -> ";
            temp = temp->next;
            }
            cout << "NULL"<<endl;
            }

        };


class Queue{



};
int main(){

    int choice;
    sorting s1;

    vector<int>arr(5);

    do{
        cout<<"\n-------------------------------------\n";
        cout<<"\nPress 1 : For Queue\n";
        cout<<"\nPress 2 : For Linked list\n";
        cout<<"\nPress 3 : For Quick Sort\n";
        cout<<"\nPress 0 : For Exiting\n";
        cout<<"\n-------------------------------------\n";
        cout<<"Enter a choice : ";
        cin>>choice;


        switch(choice){


            case 1:{
                int choice;
                Queue q1;

                do{
                    cout<<"\n-------------------------------------\n";
                    cout<<"\n Press 1: To enqueue the element into the queue \n";
                    cout<<"\n Press 2: To dequeue the element from the queue \n";
                    cout<<"\n Press 3: To display the elements of the queue \n";
                    cout<<"\n Press 4: To check the size of the queue\n";
                    cout<<"\n Press 0 : For Exiting\n";
                    cout<<"\n-------------------------------------\n";
                    cout<<"Enter a choice : ";
                    cin>>choice;

                    switch(choice){
                        case 1:{

                        }
                        case 0:{
                        cout<<"Thank you for visting the queue........"<<endl;
                        break;
                        }
                    }
                }while(choice!=0);

                
                break;
            }
            case 2:{
                int choice;
                Linkedlist l1;
                
                do{
                cout<<"\n-------------------------------------\n";
                cout<<"\n Press 1: To insert at start element\n";
                cout<<"\n Press 2: To delete at start element\n";
                cout<<"\n Press 3 : To delete at end element\n";
                cout<<"\n Press 4: To delete at random position element\n";
                cout<<"\n Press 5: To display all the elements\n";
                cout<<"\nPress 0 : For Exiting\n";
                cout<<"\n-------------------------------------\n";
                cout<<"Enter a choice : ";
                cin>>choice;

                switch(choice){

                    case 1:{
                        int data;
                        cout<<"Enter the data u want to insert at start : ";
                        cin>>data;
                        l1.toinsertatstart(data);
                        break;
                    }
                    case 2:{
                        l1.todeleteatstart();
                        break;
                    }
                    case 3:{
                        l1.todeleteend();
                        break;
                    }
                    case 4:{
                        int pos;
                        cout<<"Enter a position u want to delete at : ";
                        cin>>pos;
                        l1.todeleterandom(pos);
                        break;
                    }
                    case 5:{
                        l1.todisplay();
                        break;
                    }
                    case 0:{
                        cout<<"Thank you for visting the linked list........"<<endl;
                        break;
                    }
                }

                }while(choice!=0);

                break;
            }
            case 3:{
                for(int i=0; i<arr.size(); i++){
                    cout<<"Enter a value : ";
                    cin>>arr[i];

                }
                s1.display(arr);
                s1.quicksort(arr,0,arr.size()-1);
                s1.display(arr);
                break;
            }

            case 0:{
                cout<<"Thank you for visting........"<<endl;
                break;
            }

        }

    }while(choice!=0);


    return 0;
}


