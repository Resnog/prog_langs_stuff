teams = ["red", "yellow", "orange", "blue", "purple"]

theHead = head teams -- The first element of the list
theTail = tail teams -- The list without the first element, this includes everything but the head


returnHelloWorld = 'H':'e':'l':'l':'o':' ':'W':'o':'r':'l':'d':[] -- This is how you can build a string from a list of characters

-- Lazy evaluation is a feature of Haskell that allows you to only evaluate what you need to. This is why you can have infinite lists in Haskell
infiniteList = [1..] -- This is an infinite list of numbers starting from 1
reverseInfiniteList = reverse infiniteList -- This is an infinite list of numbers starting from the end of the list


concatenatingString = "adding" ++ " " ++ "elements" -- This is how you can concatenate strings in Haskell
concatList = 1:2:3:4:[] -- This is how you can concatenate elements in a list

-- To access a particular element of a list you can use the !! operator
red = tail teams
yellow = teams !! 1
orange = teams !! 2

numbers = [1 .. 10]
lengthOfNumbers = length numbers -- This is how you can get the length of a list
reverseNumbers = reverse numbers -- This is how you can reverse a list
isThereAFive = elem 5 numbers -- This is how you can check if an element is in a list
isThereAFifteen = elem 15 numbers -- This is how you can check if an element is in a list
isThereAnRInRed = elem 'r' "red" -- This is how you can check if an element is in a list

firstThree = take 3 numbers -- This is how you can take the first n elements of a list
lastThree = drop 7 numbers -- This is how you can drop the first n elements of a list
firstAndLastThree = firstThree ++ lastThree -- This is how you can concatenate lists

takeLast n aList = reverse (take n (reverse aList))
lastFive = takeLast 5 numbers

aString = "Time is running out"
bString = "Life is bleeding out"

twoHorribleConcepts = zip aString bString -- This is how you can zip two lists together

-- Checking if a word is a palindrome
isPalindrome word = word == reverse word

-- Uses of cycle
-- cycle takes a list and cycles it into an infinite list
ones n = take n (cycle [1])
zeros n = take n (cycle [0])

assingToGruops n aList = zip groups aList
    where groups = cycle [1..n]


