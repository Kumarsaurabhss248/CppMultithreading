//Adding  mutex solves the problem of scrambling data, The ordering is still interleaved but each thread's output is seperate from the others.
//By ordering the accesses to the critical region, we have prevented the threads from interfering with each other.

#include<iostream>
#include<thread>
#include<chrono>
#include<string>
#include<mutex>

using namespace std;
using namespace std::literals;

mutex print_mutex;
void print(string str)
{
    for(int i=0;i<5;++i)
    {
        print_mutex.lock();
        cout<< str[0]<<str[1]<<str[2]<<endl;
        print_mutex.unlock();
        std::this_thread::sleep_for(50ms);
    }
}
int main(){
     thread t1{ print,"abc"};
     thread t2{ print,"def"};
     thread t3{ print,"xyz"};
     t1.join();
     t2.join();
     t3.join();
    return 0;
}
O/P:
def
xyz
abc
abc
def
xyz
abc
xyz
def
def
abc
xyz
abc
def
xyz
