import System.Environment

collatz :: Int -> Int
collatz n
  | n `mod` 2 == 0   = n `div` 2
  | otherwise        = 3 * n + 1

ccount :: Int -> Int
ccount n
  | n == 1     = 0
  | otherwise  = 1 + ccount (collatz n)

proper_range :: [Int] -> [Int]
proper_range xs
  | length xs  < 1    = [1..1000]
  | length xs == 1    = 1:xs
  | otherwise         = take 2 xs

getIntArgs :: IO Int
getIntArgs = fmap (read . head) getArgs

main = do
    args <- getIntArgs
    print args
--    let range = proper_range args
--        best = fold (\x y -> if ccount x <= ccount y then x else  y) range
--    print best
