import Data.Char(toLower)

aList = [1, 2, 3, 4, 5]

add3ToAll (x:xs) = 3 + x : add3ToAll xs
add3ToAll [] = []

mul3toAll [] = []
mul3toAll (x:xs) = 3 * x : mul3toAll xs

-- An easier way to do this is to use map
mulN n = map (n*)
addN n = map (n+)

-- There is also filter
keepOdds [] = []
keepOdds (x:xs) = if odd x
                  then x : keepOdds xs
                  else keepOdds xs

-- That can be made 
myFilter test [] = []
myFilter test (x:xs) = if test x
                        then x:myFilter test xs
                        else myFilter test xs

-- you can also implement your own quicksort
myQuickSort [] = []
myQuickSort (x:xs) = myQuickSort (filter (<=x) xs) ++ [x] ++ myQuickSort (filter (>x) xs)

-- You can also implement your own remove
myRemove test [] = []
myRemove test (x:xs) = if test x
                        then myRemove test xs
                        else x:myRemove test xs

mySum nums = foldl (+) 0 nums
myProduct nums = foldl (*) 1 nums

--you can concatenate strings with foldl
strList = ["apple", "orange", "banana"]
concatList strs = foldl (++) "" strs

-- my own elem function
myElem x aList = length exists > 0
    where exists = filter (==x) aList

phrase = "A man a plan a canal panama"
isPalindrome word = lower_case_word == reverse lower_case_word
    where lower_case_word = map toLower filtered_word
          filtered_word = filter (/=' ') word

-- Implement a harmonic series function
harmonic n = sum (take n series)
    where series = map (1/) [1..]