use std::io;

fn fibonacci(n:u32) -> u32{

    if (n == 1) || (n == 0) {
        return 0;
    } else if n == 2 {
        return 1;
    } else{
        return fibonacci(n-1) + fibonacci(n-2);
    }

}

fn main() {

    // PROGRAM NOT TESTED

    println!("Fibonacci nth number generator");
    println!("Press q to exit.");
    println!("Enter your desired number:");

    //let mut arr = [0,1,0];
    
    let reader = io::stdin();

    loop {    
        
        let mut a_string = String::new();
        
        reader
        .read_line(&mut a_string)
        .expect("Failed to read.");

        if a_string.trim().eq("q") {
            break;
        } 

        // Read the string input and convert to u32
        let n: u32 = match a_string.trim().parse() {
            Ok(num) => num,
            Err(_) => continue,
        };

      

        let res = fibonacci(n);
        println!("{}",res);    
            


    } //main loop

    print!("Program exiting");
}

