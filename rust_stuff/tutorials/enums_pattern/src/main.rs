#[derive(Debug)]

enum IpAddVer{
    V4(u8,u8,u8,u8),
    V6(String),
}

enum Message{
    Quit,
    Move { x: u32, y:u32},
    Write(String),
    ChangeColor(i32,i32,i32),
}

enum Coin{
    Penny,
    Nickel,
    Dime,
    Quarter,
}
impl Coin{
    fn value_in_cents(&self) -> u8{
        match self {
            Coin::Penny => 1,
            Coin::Nickel => 5,
            Coin::Dime => 10,
            Coin::Quarter => 25,
        }
    }        
}

fn plus_one(x: Option<i32>) -> Option<i32>{
    match x {
        None => None,
        Some(i) => Some(i+1),
    }
}


fn main() {

    let home = IpAddVer::V4(127,0,0,1);

    let loopback =IpAddVer::V6(String::from("::1"));

    println!("Loopback IPv6 is {:?}", loopback);

    let coin = Coin::Quarter;

    let value = coin.value_in_cents();

    println!("Coin value is {}", value);

    let five = Some(5);
    let six = plus_one(five);
    let none = plus_one(None);

    // Count enums with if let

    let mut count:u32 = 0;

    if let Coin::Penny = coin {
        println!("This coin is a Penny");
        count +=1;
    }else{
        println!("This coin isn't a Penny");
    }

    println!("We have {} coins", count);

}
