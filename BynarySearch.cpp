#include <iostream>
#include <vector>
using namespace std;



int BynarySearchRecursive(int low, int high, int key, vector<int>* array){
    int m= low + (high-low)/2;
    if(key==(*array)[m]){
        return m;
    }
    if((*array)[m] < key){
        return BynarySearchRecursive(m+1, high, key, array);
    }
    else{
        return BynarySearchRecursive(low, m-1, key, array);
    }
    return -1;
}

int BynarySearch(int low, int high, int key, vector<int>* array){
    while(low<=high){
        int mid= low+(high-low)/2;
        if((*array)[mid]==key){
            return mid;
        }
        if((*array)[mid]<key){
            low=mid+1;
    }
        else{
            high=mid-1;
            }

}
}


int main(){
    vector<int>  array{6,7,8,9,10,11,12,13,14,15};
    vector<int>* arr = &array;
    int key= 13;
    cout<<BynarySearch(0, array.front(), key, arr);
    
    return 1;
}   