import Data.List

-- First-class functions in Haskell

-- Imagine you have these functions that do small things like

ifEvenIncSilly n = if even n
              then n + 1
              else n

ifEvenDoubleSilly n = if even n
                 then n * 2
                 else n

ifEvenSquareSilly n = if even n
                 then n ^ 2
                 else n

-- These are trivial functions of write, but all share a common pattern, you execute
-- some mathametical formulae if the number is even. If you pass a function as your argument
-- you can avoid writing such extensive functions


ifEven myFunction n = if even n
                      then myFunction n
                      else n

-- This behaviour is intended, the extensibility of said arrangement is greater than the 
-- previous one, this sort of pattern will make it trivial to add new functions as above

inc n = n + 1
double n = n * 2
square n = n ^ 2

ifEvenInc n = ifEven inc n 
ifEvenDouble n = ifEven double n
ifEvenSquare n = ifEven square n 

-- Adding new functions such as ifEvenCube and ifEvenNegate, or any other desired behaviour becomes easier

cube n = n ^ 3

ifEvenCube n = ifEven cube n

ifEvenCube2 n = ifEven (\x -> x ^ 3) n

-- A practical way of using first-class functions is for sorting

author = ("Will", "Kurt")

names = [("Ian", "Curtis"), ("Bernard", "Sumner"), ("Peter", "Hook"), ("Stephen", "Morris")]

-- This function sorts the names by last name, if the last names are the same, it sorts by first name
compareLastNames name1 name2 = if lastName1 > lastName2
                               then GT
                               else if lastName1 < lastName2
                                    then LT
                                    else if firstName1 > firstName2
                                        then GT
                                        else if firstName1 < firstName2
                                            then LT
                                            else EQ
    where lastName1 = snd name1
          lastName2 = snd name2
          firstName1 = fst name1
          firstName2 = fst name2

compareLastNames2 name1 name2 = if lastNameComparison == EQ
                                then compare (fst name1) (fst name2)
                                else lastNameComparison
    where lastNameComparison = compare (snd name1) (snd name2)

-- Returning functions from functions
sfAddress = "PO Box 1234, San Francisco, CA, 94111"
nyAddress = "PO Box 789, New York, NY, 10013"
rnAddress = "PO Box 456, Reno, NV, 89523"

addressLetter name location = nameText ++ " - " ++ location
    where nameText = fst name ++ " " ++ snd name

sfSecondAddress = "PO Box 1010, San Francisco, CA, 94109"

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

addressLetterV2 name location = locationFunction name
    where locationFunction = getLocationFunction location


