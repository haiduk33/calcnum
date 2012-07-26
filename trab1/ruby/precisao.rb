include Math
# Algoritmo PRECISÃO

p = 1.0 # P <- 1
while p + 1.0 > 1.0 do # Enquanto P+1 > 1 executar
  p /= 2.0 # P <- P/2
end # Fim (Enquanto)
p *= 2 # P <- 2*P
d = log10(p).floor.abs # D <- abs(int(log(P)))
n = (log(p)/log(2.0)).abs.floor #  N_2 <- int(abs(log(P))/log(2))
puts "Precisao: #{p}" # Escrever "Precisão:"; P
puts "Numero de digitos significativos decimais: #{d}" # Escrever "Núm. dígitos significativos decimais:"; D
puts "Numero de bits da mantissa: #{n}" # Escrever "Núm. bits da mantissa:"; N_2

