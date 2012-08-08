# encoding: utf-8
include Math

z = 1.0
while z > 0.0 do
  m = z
  z /= 2.0
end
n = (log((log(m) / log(2.0)).abs + 1.0) / log(2.0)).floor
puts "Magnitude: #{m}"
puts "Número de bits do expoente: #{n}"

