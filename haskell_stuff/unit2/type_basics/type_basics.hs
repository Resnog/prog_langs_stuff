-- myAverage aList = sum aList / length aList

x :: Int
x = 5

y :: Integer
y = 6

letter :: Char
letter = 'a'

interestRate :: Double
interestRate = 0.375

isFun :: Bool
isFun = True

-- List types 

numbers :: [Int]
numbers = [1,2,3,4,5]

testScores :: [Double]
testScores = [98.5, 99.0, 85.5]

letters :: [Char]
letters = ['a', 'b', 'c']

aListOfCharsIsAString :: [Char]
aListOfCharsIsAString = "Hello"

alsoAString :: String
alsoAString = "H3ll0"

-- Tuple types
ageAndHeight ::(Int,Int)
ageAndHeight = (34,74)

firstLastMiddle :: (String,String,Char)
firstLastMiddle = ("Oscar","Grouch",'D')

streetAddress :: (Int,String)
streetAddress = (123,"Happy St.")

-- Function types
half :: Int -> Double
half n = (fromIntegral n) / 2

halve :: Integer -> Integer
halve n = n `div` 2

printDouble :: Int -> String
printDouble n = show (n * 2)

makeAddress :: Int -> String -> String -> (Int,String,String)
makeAddress number street town = (number, street, town)

-- Types can also be generic
something :: a -> a
something x = x

somethingElse :: a -> b
somethingElse x = x