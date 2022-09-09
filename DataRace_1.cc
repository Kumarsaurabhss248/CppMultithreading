/* • Write a task function with a loop that prints out the thread's ID and 
sleeps
• Write a program which runs this task function in three threads
• Run the program and explain the output */
//Data Race -A data race is a situation, in which at least two threads access a shared variable at the same time. At least one thread tries to modify the variable.
//Interleaving when a thread is excuting another thread accessing the same function at the same time then data becomes inconsitstent
//This is an example for data race t1,t2 and t3 are doing data race for accessing print_id fun()

#include<iostream>
#include<thread>
#include<chrono>

using namespace std;
using namespace std::literals;
void print_id(){
    for(int i=0;i<5;i++){
    cout<<"I'm a thread with ID"<<std::this_thread::get_id()<<"!"<<endl;
    this_thread::sleep_for(50ms);
    }
}
int main(){

    thread t1{print_id};
    thread t2{print_id};
    thread t3{print_id};

    t1.join();
    t2.join();
    t3.join();

    return 0;
}
/* O/P:
I'm a thread with ID12648!
I'm a thread with ID25532!
I'm a thread with ID11844!
I'm a thread with ID25532!
I'm a thread with ID12648!
I'm a thread with ID11844!
I'm a thread with ID12648!
I'm a thread with ID11844!
I'm a thread with ID25532!
I'm a thread with ID11844!
I'm a thread with ID12648!
I'm a thread with ID25532!
I'm a thread with IDI'm a thread with ID12648!25532!I'm a thread with ID11844! */

/* 
• The output from the threads is interleaved due to a data race
• Multiple threads modify a memory location (the variable cout)
• The modifications are not atomic
• There is no ordering of the modifying threads
*/
