use std::{collections::HashMap, io};

fn main(){

    // Create the main "database" where we will store our departments and employees
    let mut workforce:HashMap<String,Vec<String>> = HashMap::new();

 
    // Create reader to handle user input
    let reader = io::stdin();

    loop {

        // Clear terminal 
        print!("{esc}c", esc = 27 as char);

        // Buffer string
        let mut input = String::new();
        
        // Options display
        display_options();
        
        // User input selection
        reader
        .read_line(&mut input)
        .expect("Failed to read");

        // Convert string to number
        let option: u32 = match input.trim().parse() {
            Ok(option) => option,
            Err(_) => continue
        };

        match option {
            1 => enter_employee(&mut workforce),      // Add employee to database
            2 => display_workforce(&workforce),   // Show the worforce in an ordely manner
            3 => break,                 // Break loop and exit program
            _ => println!(""),
        }

        // Show to user
        println!("Press any key to continue.");
        //Press a key to continue   
         reader
         .read_line(&mut input)
         .expect("Failed to read");

        }

        println!("");
        println!("Thank you for using the workforce database");
        println!("");
    }

  
    


fn display_options(){
    println!("Welcome to the workforce database");
    println!("");
    println!("(1) Enter employee in department.");
    println!("(2) Display workforce ordered list.");
    println!("(3) Exit database.");
    println!("");
}

fn enter_employee(database: &mut HashMap<String,Vec<String>>) {
    
    // Display example to user
    println!("");
    println!("Enter employee's name and department.");
    println!("Example:");
    println!("  Add John to Sales.");
    println!("");

    // Read input
    let mut line= String::new();

    io::stdin()
        .read_line(&mut line)
        .expect("Invalid input, please look at example.");
    
    // Read line and add to vector 
    let new_entry: Vec<&str> = line.split_whitespace().collect();
    
    for s in &new_entry {
        print!(" {} ",s);
    }


    // Order input taking into account the given example "add" and "to"  
    if new_entry[0] == "Add" && new_entry[2] == "to" {  
        
        // Create a new entry if it isn't in the database already
        database.entry(new_entry[3].to_string())
                .or_insert(Vec::new());

        // Add employee's name to the database
        database.get_mut(new_entry[3]).unwrap().push(new_entry[1].to_string());
        // Order employee's vector alphabetically
        database.get_mut(new_entry[3]).unwrap().sort();

        println!("{} added to {}",new_entry[1], new_entry[3]);
    }else{ // Print to console the error
        println!("Wrong command to insert new employee.");
    }

}

fn display_workforce(database: &HashMap<String,Vec<String>>){
    println!("");
    println!("Display stuff");
    println!("");

    for (k,v) in database{
        println!("{}:",k);
        for element in v{
            println!("      {}",element);
        }
    }
}
