class Describable a where
    describe :: a -> String

data Icecream = Vanilla | Chocolate deriving (Show, Eq, Ord)

-- Using type classes
data NewEngland = ME | NH | VT | MA | RI | CT -- deriving (Show, Eq, Ord)

data SixSidedDie = S1 | S2 | S3 | S4 | S5 | S6 deriving (Eq, Ord)

instance Show SixSidedDie where
    show S1 = "I"
    show S2 = "II"
    show S3 = "III"
    show S4 = "IV"
    show S5 = "V"
    show S6 = "VI"

instance Enum SixSidedDie where
    fromEnum S1 = 1
    fromEnum S2 = 2
    fromEnum S3 = 3
    fromEnum S4 = 4
    fromEnum S5 = 5
    fromEnum S6 = 6

    toEnum 1 = S1
    toEnum 2 = S2
    toEnum 3 = S3
    toEnum 4 = S4
    toEnum 5 = S5
    toEnum 6 = S6
    toEnum _ = error "No such value"

data Name = Name (String, String) deriving (Show, Eq)
names :: [Name]
names = [(Name ("Emil", "Cioran")),
         (Name ("Eugene", "Thacker")),
         (Name ("Friedrich", "Nietzsche"))]

instance Ord Name where
    compare (Name (f1, l1)) (Name (f2, l2)) = compare (l1, f1) (l2, f2)


-- Suppose you have a data type like this
data Number = One | Two | Three deriving (Enum, Show)
-- Now you can make use of fromEnum to convert this into an int
-- This makes easier to implement Eq as well as Ord:
instance Eq Number where
    (==) num1 num2 = fromEnum num1 == fromEnum num2

instance Ord Number where
    compare num1 num2 = compare (fromEnum num1) (fromEnum num2)

--
data FiveSidedDie = Side1 | Side2 | Side3 | Side4 | Side5 deriving (Show, Eq, Ord, Enum)

class (Eq a, Enum a) => Die a where
    roll :: Int -> a

instance Die FiveSidedDie where
    roll n = toEnum (n `mod` 5)