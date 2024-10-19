
fn get_largest_i32(list: &[i32]) -> &i32 {
    let mut largest = &list[0];

    for item in list {
        if item > largest {
            largest = item;
        }
    }

    largest
}

fn get_largest_char(list: &[char]) -> &char {
    let mut largest = &list[0];

    for item in list {
        if item > largest {
            largest = item;
        }
    }

    largest
}

// fn get_largest<T>(list: &[T]) -> &T {
//     let mut largest = &list[0];

//     for item in list {
//         if item > largest {
//             largest = item;
//         }
//     }

//     largest
// }

struct Point<T, U>{
    x: T,
    y: U,
}

impl<T, U> Point<T, U> {
    
}

fn main() {
    let number_list = vec![34, 50, 25, 100, 65];

    let mut largest = get_largest_i32(&number_list);
    println!("The largest number is {}", largest);
    let char_list = vec!['y', 'm', 'a', 'q'];

    let result = get_largest_char(&char_list);
    println!("The largest char is {}", result);

    let both_integer = Point { x: 5, y: 10 };
    let both_float = Point { x: 1.0, y: 4.0 };
    let int_and_float = Point { x: 5, y: 4.0 };
}
