#include<iostream>
using namespace std;

class heap{
    public:
    int arr[100];
    int size;

    heap(){
        size = 0;
        arr[0] = -1;
    }

    void insert(int val){

        size = size+1;
        int index = size;

        arr[index] = val;

        while(index > 1){
            int parent = index/2;

            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else{
                return;
            }
        }

    }

    void deletefromHeap(){

        if(size == 0){
            cout << "Nothing to delete" << endl;
        }

        // step 1 : place root node at last index (basically we are swapping 1st node with last node)
        arr[1] = arr[size];

        // step 2 : delete last node (that 1st node we placed at last position)
        size = size - 1;

        // step 3 : take root node to its correct position
        int i = 1;

        while(i < size){
            int leftIndex = 2*i;
            int rightIndex = 2*i + 1;

            if(leftIndex < size && arr[i] < arr[leftIndex]){
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }
            else if(rightIndex < size && arr[i] < arr[rightIndex]){
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }
            else{
                return;
            }
        }

    }

    void print(){

        for(int i=1; i<=size; i++){
            cout << arr[i] <<" ";
        }cout << endl;
    }
};

int main(){

    heap h;

    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    h.print();

    h.deletefromHeap();
    h.print();
        
    return 0;
}