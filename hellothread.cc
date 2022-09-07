#include<iostream>
#include<thread>

using namespace std;

void hello(){
    std::cout<<"Hello Thread\n";
}
int main(){
      thread t{ hello }; // Calling a thread
      cout<<"Doing some work"<<endl;
       t.join(); //Tells the main fucnction to stop til this thread runs
/* When more than one thread runnings at same time there action can "interleave" */ 
      return 0;
}

o/p:
Doing some work
Hello Thread
