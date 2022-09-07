#include<iostream>
#include<thread>

using namespace std;

//Callebale object -> Thread Entry Point
void hello(){
    std::cout<<"Hello Thread\n";
}
int main(){
      thread t{ hello }; // Starting a thread
      cout<<"Doing some work"<<endl;
       t.join(); //Tells the main fucnction to stop till this thread finishes
/* When more than one thread runnings at same time there action can "interleave" */ 
      return 0;
}

o/p:
Doing some work
Hello Thread
