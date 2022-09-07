/*Calling a thread and passing a value */
#include<iostream>
#include<thread>

using namespace std;

void hello(string s){
    std::cout<<s<<endl;
}
int main(){
      thread t{ hello,"Hello Thread!" }; // Starting a thread and passing a value
      
      t.join(); //Tells the main fucnction to stop till this thread finishes

      return 0;
}

O/P:Hello Thread!

/*Calling a thread and passing a reference */
#include<iostream>
#include<thread>
#include<string>
using namespace std;

void hello(string &s){
    s="xyz";
}
int main(){
      string s="abc";
      thread t{ hello, std::ref(s) }; // Starting a thread and passing a reference of string

      t.join(); //Tells the main fucnction to stop till this thread finishes

      cout<<s<<endl;

      return 0;
}

O/P:xyz
