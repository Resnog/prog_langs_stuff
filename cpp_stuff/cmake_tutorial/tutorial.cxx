#include <iostream>
#include <math.h>
#include <string>
#include <vector>
//#include <TutorialConfig.h.in>

std::vector<int> string2number(std::string str){

    std::vector<int> numbers;
    
    for (int i = str.size(); i >= 0 ;i--){ 
               
        if(str[i]=='0'){
            numbers.push_back(0);
        }
        else if (str[i]=='1')
        {
            numbers.push_back(1);
        }
        else if (str[i]=='2')
        {
            numbers.push_back(2);
        }
        else if (str[i]=='3')
        {
            numbers.push_back(3);
        }
        else if (str[i]=='4')
        {
            numbers.push_back(4);
        }
        else if (str[i]=='5')
        {
            numbers.push_back(5);
        }
        else if (str[i]=='6')
        {
            numbers.push_back(6);
        }
        else if (str[i]=='7')
        {
            numbers.push_back(7);
        }
        else if (str[i]=='8')
        {
            numbers.push_back(8);
        }
        else if (str[i]=='9')
        {
            numbers.push_back(9);
        }
    }

    return numbers;
}

float vec2digit(std::vector<int> numbers){

    int len = numbers.size();
    std::cout << len << std::endl;
    float k = numbers.size() - 1;

    // Number to return
    float res = 0.0;

    for(int i = numbers.size() - 1; i >= 0 ; i--){

    
        // Add digit to the result
        res += numbers[i] * pow(10.0,k);
        k--;

        std::cout << res << std::endl;
        // Remove item from vector
        //numbers.pop_back();
    }

    return res;
}

int main( int argc, char **argv){


  if (argc == 2) {
    
    std::string str = argv[1];

    float num = vec2digit( string2number(str) );

    std::cout << "The square root is: " << num << std::endl;
    
    //End program
    return 0x01;

  } else {

    std::cout << "Please insert just one number." << std::endl;
    //End program
    return 0x00;

  }

}

