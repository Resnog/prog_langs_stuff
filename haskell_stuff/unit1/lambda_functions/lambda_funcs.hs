-- Lambda functions in Haskell 

squareSumOrSumSquare x y = (\sumSquare squareSum -> if sumSquare > squareSum then sumSquare else squareSum) ((x+y)^2)  (x^2 + y^2)


doubleDouble1 x = dubs * 2
    where dubs = x * 2

doubleDouble2 x = (\dubs -> dubs *2 ) (x*2)

sumSquareOrSquareSum x y = let sumSquare = (x+y)^2
                               squareSum = x^2 + y^2
                            in 
                            if sumSquare > squareSum
                            then sumSquare
                            else squareSum

overwrite1 x = let x = 2
                in
                 let x = 3
                  in 
                   let x = 4
                    in
                      x

overwrite2 x =  (\x -> (\x -> (\x -> x) 4) 3 ) 2


a = 10

addOne b = a + b

addTwo b = (\b -> a + b) 3

addThree b =  (\b -> (\a -> a + b) 1 ) 2
