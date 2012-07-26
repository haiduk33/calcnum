include Math
# Algoritmo MAGNITUDE

z = 1.0 # Z <- 1
while z > 0 do # Enquanto Z > 0 executar
  m = z # M <- Z
  z /= 2 # Z <- Z/2
end # Fim (Enquanto)
n = (log((log(m) / log(2)).abs + 1) / log(2)).floor # N_1 <- int(log(abs(log(M)/log(2))+1))
puts "Magnitude: #{m}" # Escrever "Magnitude:"; M
puts "Numero de bits do expoente: #{n}" # Escrever "Número de bits do expoente:"; N_1

