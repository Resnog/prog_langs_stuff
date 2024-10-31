pub struct Breakfast{
    pub toast: String,
    seasonal_fruit: String,
}

impl Breakfast {
    pub fn summer(toast: &str) -> Breakfast{
        Breakfast{
            toast: String::from(toast),
            seasonal_fruit: String::from("peaches"),
        }
    }
}

fn fix_incorrect_order(){
    cook_order();
    serve_order();
}

fn serve_order(){}

fn cook_order(){}

pub enum Appetizer{
    Soup,
    Salad,
}