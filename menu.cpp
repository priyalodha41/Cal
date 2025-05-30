#include<iostream>
#include<vector>

using namespace std;


class Sort{
    public:
        void toselectsort(vector<int>&arr){

            for(int i=0; i<arr.size()-1; i++){

                int minidx=i;

                for(int j=i+1; j<arr.size(); j++){

                    if(arr[j]<arr[minidx]){
                        minidx=j;
                    }
                }

                if(minidx!=i){
                    int temp=arr[minidx];
                    arr[minidx]=arr[i];
                    arr[i]=temp;
                }
            }
        }

        void mergesort(vector<int>&arr, int low, int high){ // breaking into two equal halves

            if(low>=high){
                return;
            }


            int mid =(low+high)/2;


            mergesort(arr,low,mid);
            mergesort(arr,mid+1,high);
            merge(arr,low,high,mid);

        }

        void merge(vector<int>&arr, int low, int high,int mid){ // merging of the sort array

            vector<int>temp;

            int left=low;
            int right=mid+1;


            while(left<=mid && right<=high){

                if(arr[left]<arr[right]){
                    temp.push_back(arr[left]);
                    left++;
                }
                else{
                    temp.push_back(arr[right]);
                    right++;
                }
            }

            while(left<=mid){
                temp.push_back(arr[left]);
                left++;
            }
            while(right<=high){
               temp.push_back(arr[right]);
                right++;
            }

            for(int i=low; i<=high ; i++){
                arr[i]=temp[i-low];
            }
        }

        int binarysearch(vector<int>& arr, int start, int end,int key){


            if (start>=end) return -1;
            int mid=(start+end)/2;


            if(arr[mid]==key){
                return mid;
            }
            else if(key<arr[mid]){
                return binarysearch(arr,  start, mid-1, key);
            }
            else{
                return binarysearch(arr,  mid+1, end, key);
            }


        }

        void display(vector<int>&arr){
            for(int val:arr){
                cout<<val<<" ";
            }
            cout<<endl;
        }
};






int main(){

    Sort s1;

    vector<int>arr(5);

    int choice;


    do{ 
        cout<<"\n-------------------------------------\n";
        cout<<"\nPress 1 : For Selection sort\n";
        cout<<"\nPress 2 : For Merge sort\n";
        cout<<"\nPress 3 : For  Binary Search\n";
        cout<<"\nPress 4 : For linear search\n";
        cout<<"\nPress 5 : For Display of all the elements\n";
        cout<<"\nPress 0 : For Exiting the searching and sorting \n";
        cout<<"\n-------------------------------------\n";

        cout<<"Enter a choice : ";
        cin>>choice;

        switch(choice){

            case 1:{
                for(int i=0; i<arr.size(); i++){
                    cout<<"Enter a value : ";
                    cin>>arr[i];
                }
                s1.display(arr);
                s1.toselectsort(arr);
                s1.display(arr);
                break;
            }
            case 2:{
                for(int i=0; i<arr.size()-1; i++){
                    cout<<"Enter a value : ";
                    cin>>arr[i];
                }
                s1.display(arr);
                s1.mergesort(arr,0,arr.size()-1);
                s1.display(arr);
                break;
            }

            case 3:{

                for(int i=0; i<arr.size()-1; i++){
                cout<<"Enter a value : ";
                cin>>arr[i];
                }
                s1.display(arr);
                s1.toselectsort(arr);
                s1.display(arr);


                int key;
                cout<<"Enter a key u want to search : ";
                cin>>key;

                int indx=s1.binarysearch(arr,0, arr.size()-1, key);

                if(indx==-1){
                    cout<<"Element not found...........";
                    break;
                }
                else{
                    cout<<"Yay!!!!Element found at index..........."<<indx<<endl;
                }
                break;

            }
            case 4:{
                  for(int i=0; i<arr.size()-1; i++){
                    cout<<"Enter a value : ";
                    cin>>arr[i];
                }
                s1.display(arr);
                s1.toselectsort(arr);
                s1.display(arr);

                int target;
                cout<<"Enter a data u want to search : ";
                cin>>target;

                for(int i=0; i<arr.size(); i++){
                    if(target==arr[i]){
                        cout<<"Element found..........\n";
                        return 0;
                    }
                }
                cout<<"Element not found................\n";
                break;

            }
            case 5:{
                s1.display(arr);
                break;
            }

            case 0:{
                cout<<"Thank you visit again.........."<<endl;
                break;
            }

        }

    }while(choice!=0);













    return 0;
}