import System.Environment
import Data.List


main = do args <- getArgs
          let [x,y] =  (map rInt args)
              range = [x..y + 1]
              winner = maximumBy bigger_ccount range
          putStr . show $ winner
          putChar ' '
          print (ccount winner)
          collatz_spy winner


-- Halving a number.
halve :: Int -> Int
halve n = n `div` 2

-- Multiplying a number by three and adding one.
triple_plus_one :: Int -> Int
triple_plus_one n = 3 * n + 1

-- The Collatz function halves if the number is even.
-- If the number is odd, it multiples by three and adds one.
collatz :: Int -> Int
collatz n
  | even n     = halve n
  | otherwise  = triple_plus_one n

-- The Collatz count function determinses how often the Collatz funtion must be
-- called on a number to get to the result '1'.
ccount :: Int -> Int
ccount n
  | n == 1     = 0
  | otherwise  = 1 + ccount (collatz n)

-- Return the number with the biggest Collatz count.
bigger_ccount :: Int -> Int -> Ordering
bigger_ccount x y
  | xc  > yc   = GT
  | xc == yc   = EQ
  | otherwise  = LT
    where xc = ccount x
          yc = ccount y

-- Find the sequence of Collatz numbers starting at x.
collatz_spy :: Int -> IO ()
collatz_spy n =
  do putStr . show $ n
     putChar ' '
     if n == 1 then
       return ()
     else
       collatz_spy (collatz n)


-- Convert String to Int.
rInt :: String -> Int
rInt = read
