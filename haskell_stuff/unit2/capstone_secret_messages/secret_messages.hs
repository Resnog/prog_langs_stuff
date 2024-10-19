message = "Jean-Paul likes Simone"

data FourLetterAlphabet = L1 | L2 | L3 | L4 deriving (Show, Enum, Bounded)

rotN :: (Bounded a, Enum a) => Int -> a -> a
rotN alphabetSize letter = toEnum rotation
    where rotation = offset `mod` alphabetSize
          offset = fromEnum letter + halfAlphabet
          halfAlphabet = alphabetSize `div` 2

rotChar :: Char -> Char
rotChar charToEncrypt = rotN sizeOfAlphabet charToEncrypt
    where sizeOfAlphabet = 1 + fromEnum (maxBound :: Char) -- Enums in Haskell start from 0 to n-1 to we assume that the maxBound goes from 1 to n

message2 :: [FourLetterAlphabet]
message2 = [L1, L3, L4, L1, L4, L2]

fourLetterAlphabetEncoder :: [FourLetterAlphabet] -> [FourLetterAlphabet]
fourLetterAlphabetEncoder vals = map rot4l vals
    where alphaSize = 1 + fromEnum (maxBound :: FourLetterAlphabet)
          rot4l = rotN alphaSize

-- Try a decoder with an odd size alphabet

data ThreeLetterAlphabet = Alpha | Beta | Kappa deriving (Show, Enum, Bounded)

threeLetterMessage :: [ThreeLetterAlphabet]
threeLetterMessage = [Alpha, Alpha, Beta, Alpha, Kappa]

threeLetterEncoder :: [ThreeLetterAlphabet] -> [ThreeLetterAlphabet]
threeLetterEncoder vals = map rot3l vals
    where alphaSize = 1 + fromEnum (maxBound :: ThreeLetterAlphabet)
          rot3l = rotN alphaSize

-- For an odd size alphabet the encoder and decoder are different since the encoder isn't symmetric
-- for this we need to implement a decoder
rotNdecoder :: (Bounded a, Enum a) => Int -> a -> a
rotNdecoder n c = toEnum rotation
    where halfN = n `div` 2
          offset = if even n
                   then fromEnum c + halfN
                   else 1 + fromEnum c + halfN
          rotation = offset `mod` n
    
-- Now we can build a decoder for the threeLetterAlphabet
threeLetterDecoder :: [ThreeLetterAlphabet] -> [ThreeLetterAlphabet]
threeLetterDecoder vals = map rot3ldecoder vals
    where alphaSize = 1 + fromEnum (maxBound :: ThreeLetterAlphabet)
          rot3ldecoder = rotNdecoder alphaSize

-- Rotating string with a ROT-N cipher
rotEncoder :: String -> String
rotEncoder text = map rotChar text
    where alphaSize = 1 + fromEnum (maxBound :: Char)
          rotChar = rotN alphaSize

