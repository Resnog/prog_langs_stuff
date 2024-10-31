use std::{collections::HashMap, u8};
fn vector_example(){

    let mut v: Vec<i32> = Vec::new();

    v.push(10);
    v.push(11);
    v.push(12);
    v.push(13);

    println!("");
    print_vector(&v);
    println!("");

    // To show how to use enums in vectors
    let row = vec![
        SpreadsheetCell::Int(42),
        SpreadsheetCell::Float(3.1415),
        SpreadsheetCell::Text(String::from("GodEmperor")),
    ];

}

fn print_vector(v:&Vec<i32>){

    // Classic C/C++ element access
    for i in 0..v.len(){

        println!("The element number {} is {} ",i, v[i]);
    }

    // Standard Rust vector element access 
    for i in v{
        println!("The element is {}", i);
    }

}

enum SpreadsheetCell{
    Int(i32),
    Float(f64),
    Text(String),
}

fn string_example(){

    let mut s = "Praise the machine".to_string();
    let s1 = ", the true emperor.";

    s.push_str(s1);

    println!("The two strings, together: {}",s);

    let sliced_s = &s[0..5];
    println!("The sliced string: {}.", sliced_s);

    let added_string = "Blessed".to_string() + "-" + &s[11..];
    println!("The added string: {}.", added_string);

}

fn hash_maps_example(){

    // Create a hash map 
    let mut scores: HashMap<&str, u32> = HashMap::new();
    
    // Insert items into hash map
    scores.insert("Joe", 100);
    scores.insert("Dude", 101);
    scores.insert("The glorious gladious", 999);


    // Creating a hash map from vectors
    let players = vec!["Joe","Dude", "Biggus", "Dickus"];
    let current_score: Vec<u32> = vec![10,12,40,32];

    let mut score_board: HashMap<_,_> = players.into_iter()
                                            .zip(current_score.into_iter())
                                            .collect(); 

    print_hashmap(&score_board);

    // Insert a new key-value pair, new element for the HM

    score_board.insert("Juan", 120);
    score_board.insert("Juda", 125);
    
    print_hashmap(&score_board);

    // Change a key's value in the HM
    score_board.insert("Juan", 200);
    score_board.insert("Juda", 250);

    print_hashmap(&score_board);

    // Insert a value if a key has no value

    score_board.entry("Juan").or_insert(111);
    score_board.entry("Juda").or_insert(111);
    score_board.entry("Jeremy").or_insert(111);

    print_hashmap(&score_board);
}

fn print_hashmap(hm: &HashMap< &str,u32>){

    println!("");
    for (k,v) in hm{
        println!("Key:{} Value:{}",k,v);
    }
    println!("");

}

fn main() {

    vector_example();

    string_example();

    hash_maps_example();

}
