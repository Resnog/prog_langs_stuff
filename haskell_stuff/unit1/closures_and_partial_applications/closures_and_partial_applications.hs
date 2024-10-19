
inc n = n + 1
double n = n * 2
square n = n ^ 2

ifEven f x = if even x
                then f x
                else x

getIfEven f = (\x -> ifEven f x)

getIfXEven x = (\f -> ifEven f x)

getRequestURL host apiKey resource id = host ++ "/" ++ resource ++ "/" ++ id ++ "?token=" ++ apiKey

getHostRequestBuilder host = (\apiKey resource id -> getRequestURL host apiKey resource id)

exampleURLBuilder = getHostRequestBuilder "http://example.com"

-- More closures stuff

add4 a b c d = a + b + c + d

addXto3 = add4 3

flipBinaryArgs binaryFunction = (\x y -> binaryFunction y x)

-- Instead of using closures you can use partial application
-- Like the address example on the previous lesson, you can use partial 
-- application to create a function that will always use the same host
-- This is a more idiomatic way of doing things in Haskell

sfAddress = "PO Box 1234, San Francisco, CA, 94111"
nyAddress = "PO Box 789, New York, NY, 10013"
rnAddress = "PO Box 456, Reno, NV, 89523"

sfOffice name = if lastName1 < "L2"
                then nameText ++ " - " ++ sfAddress
                else nameText ++ " - " ++ sfSecondAddress
    where nameText = fst name ++ " " ++ snd name
          lastName1 = snd name

nyOffice name = nameText ++ " : " ++ nyAddress
    where nameText = fst name ++ " " ++ snd name

rnOffice name = nameText ++ " - " ++ rnAddress
    where nameText = fst name ++ " " ++ snd name

getLocationFunction location = case location of
    "ny" -> nyOffice
    "sf" -> sfOffice
    "rn" -> rnOffice
    _ -> \name -> fst name ++ " " ++ snd name

addressLetter name location = locationFunction name
    where locationFunction = getLocationFunction location

addressLetterV2 = flipBinaryArgs addressLetter

addressLetterNY = addressLetterV2 "ny"
addressLetterSF = addressLetterV2 "sf"
addressLetterRN = addressLetterV2 "rn"