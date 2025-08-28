pub struct List {
    head: Link,
}

impl List {
    pub fn new(self) -> Self {
        List { head: Link::Empty }
    }

    pub fn push(&mut self, number: i32) {
        let new_node = Node {
            elem: number,
            next: self.head,
        };
    }
}

pub enum Link {
    Empty,
    More(Box<Node>),
}

struct Node {
    elem: i32,
    next: Link,
}
