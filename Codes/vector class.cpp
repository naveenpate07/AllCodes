// make an own vector class
#include<bits/stdc++.h>
using namespace std;
template <class T>
class myVector{
    private:
    T count=0;
    T size;
    T*arr;
    public:
    myVector(T value) : size(value){
        arr=new T[size];
        count=0;
    }
    void resize(T value){
        T*help=new T[value];
        for(int i=0;i<count;i++){
            help[i]=arr[i];
        }
        delete[]arr;
        arr=help;
        size=value;
    }
    void insert(T value){
        if(size==count){
            resize(size*2);
            arr[count++]=value;
        }else{
            arr[count++]=value;
        }
    }
    void display(){
        for(int i=0;i<count;i++){
            cout<<arr[i]<<" ";
        }
    }
    ~myVector(){
        delete[]arr;
    }
};
int main(){
    myVector<int>vec(3);
    vec.insert(1);
    vec.insert(2);
    vec.insert(3);
    vec.insert(4);
    vec.display();
    return 0;
}