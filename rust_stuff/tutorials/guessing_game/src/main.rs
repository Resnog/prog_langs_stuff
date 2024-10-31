use std::io;
use std::cmp::Ordering;
use rand::Rng;

fn main() {

    println!("Guess the number!");

    // The random number 
    let secret_number = rand::thread_rng().gen_range(1, 101);

    // DEBUG - Print secret number
    // println!("The secret number is {}", secret_number);

    // Main guessing loop
    loop {   

    
    // The guess number variable, since the standardIO only takes Strings is defined as a String    
    let mut guess = String::new();
    println!("Please input your guess:");
    io::stdin()
        .read_line(&mut guess)
        .expect("Failed to read line");

    // Convert the string to number

    let guess: u32 = match guess.trim().parse(){
        Ok(num) => num,
        Err(_) => continue,
    };

    println!("You guessed {}", guess);

    // Define arm for multiple behaviours
    match guess.cmp(&secret_number) {

        Ordering::Less => println!("Too small!"),
        Ordering::Greater => println!("Too big!"),
        Ordering::Equal => {
            println!("You win!");
            break;
                            }
    }
} // Loop bracket

}
