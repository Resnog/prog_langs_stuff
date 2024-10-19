
areaOfCircle :: Double -> Double
areaOfCircle r = 3.14 * r * r


type Radius = Double
type Area = Double
areaOfCircleV2 :: Radius -> Area
areaOfCircleV2 r = 3.14 * r * r

patientInfo :: String -> String -> Int -> Int -> String
patientInfo fname lname age height = name ++ " " ++ ageAndHeight
    where name = lname ++ ", " ++ fname
          ageAndHeight = "( " ++ show age ++ "yrs." ++ " " ++ show height ++ ".cm)"

type FirstName = String
type LastName = String
type Age = Int
type Height = Int
patientInfoV2 :: FirstName -> LastName -> Age -> Height -> String
patientInfoV2 fname lname age height = name ++ " " ++ ageAndHeight
    where name = lname ++ ", " ++ fname
          ageAndHeight = "( " ++ show age ++ "yrs." ++ " " ++ show height ++ ".cm)"

type PatientName = (String,String)

lastName :: PatientName -> String
lastName patientName = snd patientName

firstName :: PatientName -> String
firstName patientName = fst patientName

patientInfoV3 :: PatientName -> Age -> Height -> String
patientInfoV3 patientName age height = name ++ " " ++ ageAndHeight
    where name = lastName patientName ++ ", " ++ firstName patientName
          ageAndHeight = "( " ++ show age ++ "yrs." ++ " " ++ show height ++ ".cm)"

data Sex = Male | Female
sexInitial :: Sex -> Char
sexInitial Male = 'M'
sexInitial Female = 'F'

data RhType = Pos | Neg
data ABOType = A | B | AB | O

data BloodType = BloodType ABOType RhType

patient1BT :: BloodType
patient1BT = BloodType A Pos

patient2BT :: BloodType
patient2BT = BloodType O Neg

patient3BT :: BloodType
patient3BT = BloodType AB Pos

showRh :: RhType -> String
showRh Pos = "+"
showRh Neg = "-"
showABO :: ABOType -> String
showABO A = "A"
showABO B = "B"
showABO AB = "AB"
showABO O = "O"

showBloodType :: BloodType -> String
showBloodType (BloodType abo rh) = showABO abo ++ showRh rh 

canDonateTo :: BloodType -> BloodType -> Bool
canDonateTo (BloodType O _ ) _ = True    -- Universal donor
canDonateTo _ (BloodType AB _ ) = True   -- Universal recipient
canDonateTo (BloodType A _ ) (BloodType A _ ) = True
canDonateTo (BloodType B _ ) (BloodType B _ ) = True
canDonateTo _ _ = False

type MiddleName = String
data Name = Name FirstName LastName
            | NameWithMiddle FirstName MiddleName LastName

showName :: Name -> String
showName (Name f l) = f ++ " " ++ l
showName (NameWithMiddle f m l) = f ++ " " ++ m ++ " " ++ l

name1 = Name "Juan" "Perez"
name2 = NameWithMiddle "Juan" "Carlos" "Perez"

data Patient = Patient Name Sex Int Int Int BloodType

johnDoe :: Patient
johnDoe = Patient (Name "John" "Doe") Male 30 74 200 (BloodType AB Pos)
janeElizabethSmith :: Patient
janeElizabethSmith = Patient (NameWithMiddle "Jane" "Elizabeth" "Smith") Female 24 62 140 (BloodType O Neg)

data PatientV2 = PatientV2 { name :: Name
                       , sex :: Sex
                       , age :: Int
                       , height :: Int
                       , weight :: Int
                       , bloodType :: BloodType }

jackieSmith :: PatientV2
jackieSmith = PatientV2 {name = Name "Jackie" "Smith"
                        , age = 43
                        , sex = Female
                        , height = 62
                        , weight = 115
                        , bloodType = BloodType O Neg}

johnSmith :: PatientV2
johnSmith = PatientV2 {name = Name "John" "Smith"
                        , age = 46
                        , sex = Male
                        , height = 72
                        , weight = 220
                        , bloodType = BloodType AB Pos}


showAge age = show age ++ "yrs."
showHeight height = show height ++ "in."
showWeight weight = show weight ++ "pns"

patientSummary :: PatientV2 -> String
patientSummary patient = show ("**************") ++ "\n" ++
                      "Patient Name: " ++ showPatientName ++ "\n" ++
                      "Sex: " ++ showPatientSex ++ "\n" ++
                      "Age: " ++ showPatientAge ++ "\n" ++
                      "Height: " ++ showPatientHeight ++ "\n" ++
                      "Weight: " ++ showPatientWeight ++ "\n" ++
                      "Blood Type: " ++ showPatientBloodType ++ "\n" ++
                      show ("**************") ++ "\n"
    where showPatientName = showName (name patient)
          showPatientSex = show (sexInitial (sex patient))
          showPatientAge = showAge (age patient)
          showPatientHeight = showHeight (height patient)
          showPatientWeight = showWeight (weight patient)
          showPatientBloodType = showBloodType (bloodType patient)

printPatientSummary patient = putStr (showPatient patient)