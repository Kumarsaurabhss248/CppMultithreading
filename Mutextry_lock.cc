//Mutex whith lock(), Unlock, and try_lock()
#include<iostream>
#include<thread>
#include<chrono>
#include<string>
#include<mutex>

using namespace std;
using namespace std::literals;

mutex print_mutex;
void task1(){
    cout<<"Task1 is trying to get the lock"<<endl;
    print_mutex.lock();
    cout<<"Task1 has lock"<<endl;
    this_thread::sleep_for(500ms);
    cout<<"Task1 is releasing the lock"<<endl;
    print_mutex.unlock();
}

void task2(){
      this_thread::sleep_for(100ms);
      cout<<"Task2 is trying to get the lock"<<endl;
      while(!print_mutex.try_lock()){
         cout<<"Task2 could not get the lock"<<endl;
         this_thread::sleep_for(100ms);
      }
      cout<<"Task2 gets the lock"<<endl;
      print_mutex.unlock();

}
int main(){
     thread t1{ task1 };
     thread t2{ task2 };
     t1.join();
     t2.join();
     
    return 0;
}
O/P:
Task1 is trying to get the lock
Task1 has lock
Task2 is trying to get the lock
Task2 could not get the lock
Task2 could not get the lock
Task2 could not get the lock
Task2 could not get the lock
Task1 is releasing the lock
Task2 gets the lock
