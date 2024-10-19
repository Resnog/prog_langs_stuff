-- This is a simple exersice on how to describe a type class for a genetic programming problem.
-- A simple function will be taken as an example. 
-- The function is: f(x) = (x)^2*sin(x) - (x)^2*cos(x)

testFunction :: Double -> Double
testFunction x = (x^2) * sin(x) - (x^2) * cos(x)

createRandomNumber :: Double
createRandomNumber = 1.0
