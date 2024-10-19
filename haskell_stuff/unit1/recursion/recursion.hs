-- Greatest common divisor
myGcd a b = if remainder == 0
          then b
          else myGcd b remainder
    where remainder = a `mod` b

-- pattern matching
sayAmount n = case n of
    1 -> "one"
    2 -> "two"
    n -> "a bunch"

-- factorial
myFactorial n = case n of
    0 -> 1
    n -> n * myFactorial (n - 1)

myHead aList = case aList of
    (x:_) -> x
    [] -> []

myTail aList = case aList of
    (_:xs) -> xs
    [] -> []

-- gcd but with pattern matching
myGcdPM a b = case remainder of
    0 -> b
    _ -> myGcdPM b remainder
    where remainder = a `mod` b

-- myLenght is equivalent to this
-- myLength [] = 0
-- myLength (_:xs) = 1 + myLength xs
myLength aList = case aList of
    [] -> 0 
    (_:xs) -> 1 + myLength xs

-- myTake is equivalent to this
-- myTake 0 _ = []
-- myTake _ [] = []
-- myTake n (x:xs) = x:rest
--     where rest = myTake (n - 1) xs
myTake n aList = case (n, aList) of
    (0, _) -> []
    (_, []) -> []
    (n, x:xs) -> x:rest
        where rest = myTake (n - 1) xs

-- ackermann function
ackermann m n = case (m, n) of
    (0, _) -> n + 1
    (_, 0) -> ackermann (m-1) 1
    (m, n) -> ackermann (m-1) (ackermann m (n-1))

-- collatz
collatz 1 = 1
collatz n = if even n 
            then 1 + collatz (n `div` 2)
            else 1 + collatz (n * 3 + 1)

-- fibonacci
fib 0 = 0
fib 1 = 1
fib n = fib (n-1) + fib (n-2)
-- fast fibonacci
fastFib n1 n2 counter = if counter == 0
                        then n1
                        else fastFib n2 (n1 + n2) (counter - 1)