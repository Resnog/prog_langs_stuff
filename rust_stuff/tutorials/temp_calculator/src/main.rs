use std::io;

fn fah2cel(){

    let n : f64 = 0.0;

    let res : f64 = (5.0)*(n-32.0)/9.0;

    println!("In Celcius is: {}",res);
}

fn cel2fah(){
    let n : f64 = 0.0;

    let res : f64 = (9.0)*(n)/5.0 + 32.0;

    println!("In Fahrenheit is: {}",res);
} 

fn main() {

    println!("Welcome to the Temperature Calculator:");

    loop{

        let mut sel = String::new();

        println!("Fahrenheit to Celcius(f)");
        println!("Celcius to Fahrenheit(c)");
        println!("Exit calculator(x)");

        io::stdin()
            .read_line(&mut sel)
            .expect("Option invalid");

        
        if sel.trim().eq("f"){
            fah2cel();
        }
        else if sel.trim().eq("c"){
            cel2fah();
        }
        else if sel.trim().eq("x"){
            println!("Exiting program.");
            break;
        }
        else{
            println!("Option invalid");
        } 

    }
}
