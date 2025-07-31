#include<iostream>
using namespace std;
#define MAX 1000
class Hash{
    int arr[MAX];
    public:
    Hash(){
        for(int i=0;i<MAX;i++){
            arr[i]=-1;// Initialize all elements to -1 (indicating empty slots)
        }
    }
    int hashFunction(int key){
        return key%MAX; // Simple hash function using modulo operator
    // You can replace this with a more complex hash function if needed
    }
    void insert(int key){
        int index = hashFunction(key);
        if (arr[index] != -1) {
            cout << "Collision occurred for key: " << key << " at index: " << index << endl;
        }
        arr[index] = key; // Insert the key into the hash table
        cout << "Inserted key: " << key << " at index: " << index << endl;
        // Display the current state of the hash table
        // in collision resolution, we can use linear probing or chaining
         

        cout << "Current state of hash table:" << endl;
        for (int i = 0; i < MAX; i++) {
            if (arr[i] != -1) {
                cout << "Index " << i << ": " << arr[i] << endl;
            }
        }

    }
    void remove(int key){
        int index = hashFunction(key);
        if(arr[index] == key){
            arr[index] = -1;
            cout << "Removed key: " << key << " from index: " << index << endl;
        }else{
            cout << "Key: " << key << " not found at index: " << index << endl;
        }
    }
    void search(int key){
        int index = hashFunction(key);
        if(arr[index] == key){
            cout << "Key: " << key << " found at index: " << index << endl;
        }else{
            cout << "Key: " << key << " not found at index: " << index << endl;
        }
    }
    void display(){
        cout << "Hash table contents:" << endl;
        for(int i=0;i<MAX;i++){
            if(arr[i] != -1){
                cout << "Index " << i << ": " << arr[i] << endl;
            }
        }
    }
    void clear(){
        for(int i=0;i<MAX;i++){
            arr[i] = -1;
        }
        cout << "Hash table cleared." << endl;
    }
};
int main(){
    Hash h; 
    h.insert(10);
    h.insert(20);
    h.insert(30);
    h.insert(40);
    h.insert(50);
    h.display();
    h.search(20);
    h.remove(20);
    h.display();
    h.clear();
    h.display();
    return 0;
}