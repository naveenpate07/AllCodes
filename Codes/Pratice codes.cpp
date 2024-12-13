// // // // // #include<bits/stdc++.h>
// // // // // using namespace std;
// // // // // class First{
// // // // //   private:
// // // // //   int a=10;
// // // // //   public:
// // // // //   First(){}
// // // // //   friend void func(First obj);
// // // // // };
// // // // // void func(First obj){
// // // // //     cout<<obj.a;
// // // // // }
// // // // // int main(){
// // // // //     First obj;
// // // // //     func( obj);
// // // // //     return 0;
// // // // // }
// // // // #include<bits/stdc++.h>
// // // // using namespace std;
// // // // class First{
// // // //     public:
// // // //     int a=10;
    
// // // //     First(){};
// // // // };
// // // // class Second : public First{
// // // //     private:
// // // //     int b=20;
// // // //     public:
// // // //     Second(){};
// // // //     friend class Third;
// // // // };
// // // // class Third{
// // // //     public:
// // // //     void getTheDataFromFirstAndSecond(Second obj){
// // // //         cout<<obj.a<<" "<<obj.b;
// // // //     }
// // // // };
// // // // int main(){
// // // //     Second obj;
// // // //     Third obj2;
// // // //     obj2.getTheDataFromFirstAndSecond(obj);
// // // //     return 0;
// // // // }

// // // #include<bits/stdc++.h>
// // // using namespace std;
// // // class First{
// // //     private:
// // //     int a=10;
// // //     int b=20;
// // //     public:
// // //     First(){};
// // //     First(int first,int second){
// // //         a=first;
// // //         b=second;
// // //     }
// // //     First(const First&obj){
// // //         a=obj.a;
// // //         b=obj.b;
// // //     }
// // //     void display(){
// // //         cout<<a<<" "<<b<<endl;
// // //     }
// // //     void modify(int a ,int b){
// // //         this->a=a;
// // //         this->b=b;
// // //     }
// // // };
// // // int main(){
// // //     First one;
// // //     one.display();
// // //     First two(20,30);
// // //     two.display();
// // //     First three=two;
// // //     three.display();
// // //     two.modify(40,50);
// // //     three.display();
// // //     two.display();
// // //     cout<<"The adress of the second and third object is : "<<endl<<&two<<endl<<&three<<endl;
// // // }

// // #include<bits/stdc++.h>
// // using namespace std;
// // class First{

    
// //     public:
// //     int*ptr;
// //     First(){}
// //     void getData(int value){
// //         ptr=new int;
// //         *ptr=value;
// //         cout<<"Constructor called and memory declared"<<endl;
// //     }
// //     void getDataForDeep(const First&other){
// //           ptr=new int;
// //           *ptr=*other.ptr;
// //     }
// //   void display(){
// //       cout<<endl<<*ptr;
// //   }
// // };
// // int main(){
// //     First first;
// //     first.getData(5);
// //     First second=first;
// //     cout<<endl<<"The
    
    
    
// //     adress is : "<<endl;
// //     cout<<&first<<endl<<&second;
// //     cout<<endl<<"The adress of first ptr and second ptr is  : ";
// //     cout<<endl<<first.ptr<<endl<<second.ptr;
// //     *first.ptr=10;
// //     first.display();
// //     second.display();
// //     cout<<endl<<"After the shallow copy "<<endl;
// //     First three=second;
// //     three.getDataForDeep(second);
// //     three.display();
// //     three.getData(100);
// //     cout<<endl<<endl;
// //     three.display();
// //     second.display();
// //     return 0;
// // }
// #include<bits/stdc++.h>
// using namespace std;
// class First{
//     public :
//     int *ptr;
//      First(int value){
//         ptr=new int;
//         *ptr=value;
//     }
//     void display(){
//         cout<<*ptr<<endl;
//     }
//     First(First&obj){
//         ptr=new int;
//         *ptr=*obj.ptr;
//     }
// };
// int main(){
//     First first(10);
//     First second=first;
    
//     *second.ptr=20;
//     First &third=second;
//     first.display();
//     second.display();
//     third.display();
//     // First second=first;
//     // first.display();
//     // second.display();
//     cout<<endl<<first.ptr;
//     cout<<endl<<second.ptr;
//     cout<<endl<<third.ptr;
//     *third.ptr=30;
//     cout<<endl<<endl;
//     cout<<endl<<*second.ptr;
//     cout<<endl<<*third.ptr;
//     return 0;
// }
// #include<bits/stdc++.h>
// using namespace std;
// class First{
//     private:
//     int a;
//     public:
//     First(int value){
//         a=value;
//     }
//     void display(){
//         cout<<a<<endl;
//     }
//     void modify(int value){
//         a=value;
//     }
    
// };
// int main(){
//     First first(10);
//     First second=first;
//     first.display();
//     second.display();
//     first.modify(111);
//     first.display();
//     second.display();
// }

// #include<bits/stdc++.h>
// using namespace std;
// int main(){
// int arr[5];
// for(int i=0;i<5;i++){
//     arr[i]=i+2;
//     cout<<&arr[i]<<" ";
// }
// int *a=arr;
// cout<<*a+3;
// cout<<endl;
// int *arsr[6];
// for(int i=0;i<6;i++){
//     cout<<&arsr[i]<<" ";
// }
// return 0;
// }

// funciton pointer and pointer to function
// #include<bits/stdc++.h>
// using namespace std;

// // Function 1
// void First() {
//     cout << "Hey, I am the first function!" << endl;
// }

// // Function 2
// void second() {
//     cout << "Hey, I am the second function!" << endl;
// }

// int main() {
//     // Declare a function pointer for a function that takes no arguments and returns void
//     void (*fun)();
    
//     // Assign address of First function to fun
//     fun = First;  
//     fun();  // Call First function using the pointer

//     // Declare another function pointer for a function that takes no arguments and returns void
//     void (*sec)();
    
//     // Assign address of second function to sec
//     sec = &second;
//     sec();  // Call second function using the pointer
    
//     // Printing the addresses of the function pointers and the functions themselves
//     cout << "Address of fun pointer: " << &fun << "   Address of First function: " << (void*)First << endl;
//     cout << "Address of sec pointer: " << &sec << "    Address of second function: " << (void*)second << endl;

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int*arr[6];
//     for(int i=0;i<6;i++){
//         arr[i]=new int(i);
//         *arr[i]=i+2;
//     }
//     for(int i=0;i<6;i++){
//         cout<<arr[i]<<" "<<*arr[i]<<endl;
//     }
// }

// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     int* arr = new int[6];  // Dynamically allocate an array of 6 integers

//     // Assign values to the array
//     for (int i = 0; i < 6; i++) {
//         arr[i] = i + 2;  // Directly assign values to arr[i]
//     }

//     // Print the values stored in the array
//     for (int i = 0; i < 6; i++) {
//         cout << arr[i] << endl;  // Directly print the value at arr[i]
//     }

//     // Free the dynamically allocated memory to avoid memory leak
//     delete[] arr;

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int num,den;
//     cout<<"Enter the num and den : ";
//     cin>>num>>den;
//     try{
//     if(den==0){
//         throw("The den is zero");
//     }
//     }
//     catch(char const* s){
//         cout<<s;
//     }
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     vector<pair<string, int>> arr;
//     int size;
//     string s;
//     int num;

//     cout << "Enter the size: ";
//     cin >> size;

//     // Input data
//     for (int i = 0; i < size; i++) {
//         // Clear the input buffer before using getline after using cin
//         cin.ignore();  // This will clear any leftover newline character
        
//         cout << "Enter the name of account: ";
//         getline(cin, s);  // Use getline to read full string with spaces

//         cout << "Enter the number: ";
//         cin >> num;  // Integer input is still valid with cin

//         arr.push_back({s, num});
//     }

//     // Sorting the vector based on the second element of the pair (num)
//     sort(arr.begin(), arr.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
//         return a.second < b.second; // Compare based on second element (int)
//     });
    

//     // Output the sorted vector
//     cout << "Sorted accounts based on number:" << endl;
//     for (auto it : arr) {
//         cout << it.first << " " << it.second << endl;
//     }

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     set<pair<string,int>>st;
//     st.insert({"Naveen",123});
//     st.insert({"Naveen",234});
//     st.insert({"Mahesh",123});
//     st.insert({"Naveen",123});
//     for(auto it : st){
//         cout<<it.first<<" "<<it.second;
//     }
    
// }

// #include <bits/stdc++.h>
// using namespace std;

// // Custom comparator to ensure uniqueness based on the int value
// struct CompareInt {
//     bool operator()(const pair<string, int>& a, const pair<string, int>& b) const {
//         return a.second != b.second;  // Compare based on the int value (second element)
//     }
// };

// int main() {
//     set<pair<string, int>, CompareInt> mySet;  // Set with custom comparator

//     // Inserting some pairs into the set
//     mySet.insert({"Alice", 10});
//     mySet.insert({"Bob", 20});
//     mySet.insert({"Charlie", 10});  // Duplicate int (10), won't be inserted
//     mySet.insert({"David", 30});
//     mySet.insert({"Eve", 20});  // Duplicate int (20), won't be inserted

//     // Printing the set
//     for (const auto& p : mySet) {
//         cout << p.first << " " << p.second << endl;
//     }

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// class multiply{
//     private:
//     int x;
//     public:
//     multiply(int fac) : x(fac) {}
//     int operator()(int a){
//         return a*x;
//     }
// };
// int main(){
//     vector<int>arr{1,2,3,4,5};
//     multiply mul(10);
//     // transform(arr.begin(),arr.end(),arr.begin(),mul);
//     for(int i=0;i<arr.size();i++){
//         arr[i]=mul(arr[i]);
//     }
//     for(int num : arr){
//         cout<<num<<" ";
//     }
// }

#include<bits/stdc++.h>
using namespace std;
void fun2(int a,int b){
    int c=a-b;
    cout<<c<<endl;
}
void fun(int a , int b,void (*f)(int ,int)){
    int c= a+b;
    cout<<c<<endl;
    f(a,b);
}
int main(){    
   
    fun(5,6,fun2);
}
