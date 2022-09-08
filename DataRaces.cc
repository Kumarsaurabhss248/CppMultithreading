/* Example of Interleaving when a thread is excuting another thread accessing the function at the same time and data becomes inconsitstent
Race Condition-A race condition occurs when two threads access a shared variable at the same time. The first thread reads the variable, and the second thread reads the same value from the variable.

Data Race -A data race is a situation, in which at least two threads access a shared variable at the same time. At least one thread tries to modify the variable. */

#include<iostream>
#include<thread>
#include<chrono>
#include<string>

using namespace std;
using namespace std::literals;

void print(string str)
{
    for(int i=0;i<3;++i)
    {
        cout<< str[0]<<str[1]<<str[2]<<endl;
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
abc
xyz
def
def
xyabc
z
abc
xyz
def

