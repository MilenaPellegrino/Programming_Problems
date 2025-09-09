
existeDivisor :: Int -> [Int] -> Bool
existeDivisor n xs = any (esDivisor n) xs

esDivisor :: Int -> Int -> Bool
esDivisor m n = mod m n == 0

esPrimo :: Int -> Bool 
esPrimo n = not( existeDivisor n [2..n-1])