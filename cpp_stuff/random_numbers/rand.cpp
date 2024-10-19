#include <vector>
#include <iostream>
#include <random>


using namespace std;

vector<int> random_int_array(size_t n, default_random_engine gen, pair<int,int> range){
    
    vector<int> int_array;

    // Declare the distribuition and the int range
    uniform_int_distribution<int> dist(range.first, range.second);

    // Fill vector with random int numbers withing the distribuition range
    for(int i = 0 ;i < n; i++){
        int_array.push_back( dist(gen) );
    }

    return int_array;

}

void print_array(vector<int> arr){

    // Print numbers
    for(int i = 0 ;i < arr.size(); i++){
        cout << "Number " << i << ":" << arr[i] << endl;
    }
    

}

int main(){

    // Declare the random number generator
    default_random_engine generator;
    
    // Generate a random int vector 
    vector<int> random_arr = random_int_array(10, generator, make_pair(0,9));

    // Print array
    print_array(random_arr);


    return 0x00;
}