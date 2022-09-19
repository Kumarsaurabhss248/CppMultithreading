#include<iostream>
#include<thread>

using namespace std;

//Callebale object -> Thread Entry Point
void hello(){
    std::cout<<"Hello Thread\n";
}
int main(){
    	// Create an instance of std::thread and initialize it with the task
      std::thread t{ hello }; // Starting a thread
      cout<<"Doing some work"<<endl;
       t.join(); //Tells the main fucnction to stop till this thread finishes
/* When you have threads running at the same time actions can "interleave" */ 
      return 0;
}

o/p:
Doing some work
Hello Thread
