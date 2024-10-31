fn main() {
    // Words set
    let words = vec![String::from("first"),
                                String::from("second"),
                                String::from("interesting"),
                                String::from("apple"),
                                String::from("ballsack") ];

    // Show the original words                              
    println!("Original words:");
    for word in &words{
        println!("  {}",word);
    }
    
    let mut piglatinized_words: Vec<String> = Vec::new();

   // Pig latinizator converts the words in plain english to pig-latin
    for word in words{
        piglatinized_words.push(pig_latinizator(word));
    }

    // Show the original words                              
    println!("Piglatinized words:");
    for word in piglatinized_words{
        println!("  {}",word);
    }
}


fn pig_latinizator(s: String) -> String{

    //Get first character
    let mut new_s = String::from(s);
    let first_char = new_s.remove(0);
    // If the word starts with a vowel
    if !is_vowel(first_char){
        
        new_s.push('-');
        new_s.push(first_char);
        new_s.push_str("ay");
    }else{
    // If if doesn't
        new_s.push_str("-hay");
    }

    // Return a String type
    new_s
}

fn is_vowel(c: char) -> bool {

    match c {
        'a' => true,
        'e' => true,
        'i' => true,
        'o' => true,
        'u' => true,
        _ => false
    }
}
