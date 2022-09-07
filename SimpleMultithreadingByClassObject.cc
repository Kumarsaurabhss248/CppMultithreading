#include<iostream>
#include<thread>
#include<string>
using namespace std;

class greeter {
    public:
      void hello() {
        std::cout<<"Hello Member Function!\n"; 
      }
      void fun() {
        std::cout<<"Hello fun!\n";
      }
};
int main(){
      greeter greet;
      thread t1{ &greeter::fun, &greet };// Calling a class function and passing an object address 
      cout<<"t1 and t2 threads called\n";   
      thread t2{&greeter::hello, &greet};
      t1.join(); //Tells the main fucnction to stop til this thread runs
      t2.join();
      cout<<"Both t1 and t2 threads are finished now main thread can stop";
      return 0;
}
O/P:
t1 and t2 threads called
Hello fun!
Hello Member Function!
Both t1 and t2 threads are finished now main thread can stop
