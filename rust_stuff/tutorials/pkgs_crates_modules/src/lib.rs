fn serve_order(){}



mod front_of_house;
pub use crate::front_of_house::hosting;

mod back_of_house;
pub use crate::back_of_house::Breakfast;

pub fn eat_at_restaurant(){


    // Order breakfasts
    let mut meal = back_of_house::Breakfast::summer("Rye");
    // Change order
    meal.toast = String::from("Wheat");
    // Show order
    println!("I'd like {} toast please", meal.toast);

    let order1 = back_of_house::Appetizer::Soup;
    let order2 = back_of_house::Appetizer::Salad;

    hosting::add_to_waitlist();

}