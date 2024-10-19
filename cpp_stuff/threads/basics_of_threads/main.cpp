#include <iostream>
#include <thread>

void sum(int a,int b){
    // Sum function you will call
    int c = a + b;
    std::cout << "The answer is: " << c << std::endl;
}

int main(){

    // Create sum thread 
    std::thread t(sum,1,2);
    // Call thread
    t.join();
    // Process termination
    return 0x00;
}