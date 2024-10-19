#include <iostream>
#include <thread>

void hello(){
    // Print hello world function
    std::cout << "Hello World:\n" << std::endl;
    std::cout << "  This is a thread.\n" << std::endl;
}

int main(){
    
    // Declare thread
    std::thread t(hello);
    // Call thread from the main thread
    t.join();

    // End process
    return 0x00;
}