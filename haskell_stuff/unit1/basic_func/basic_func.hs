-- Basic functions to do trivial mathamatical things

inc x = x + 1

double x = 2 * x

square x = x * x 

evenOrOdd n = if even n
                then n  - 2
                else 3 * n +1

sumSquareOrSquareSum x y = if sumSquare > squareSum
                           then sumSquare
                           else squareSum
                where sumSquare = x^2 + y^2
                      squareSum = (x + y)^2
