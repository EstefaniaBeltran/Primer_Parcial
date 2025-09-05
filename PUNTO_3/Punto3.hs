promedio :: [Double] -> Double
promedio = \xs -> realToFrac (foldr (+) 0 xs) / fromIntegral (length xs)

main :: IO ()
main = do
  putStrLn "Ingrese una lista de números separados por espacios:"
  entrada <- getLine
  let numeros = map read (words entrada) :: [Double]
  if null numeros
    then putStrLn "La lista está vacía, no se puede calcular el promedio."
    else putStrLn $ "El promedio es: " ++ show (promedio numeros)