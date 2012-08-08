# encoding: utf-8
include Math

p = 1.0
while p + 1.0 > 1.0 do
  p /= 2.0
end
p *= 2
d = log10(p).floor.abs
n = (log(p)/log(2.0)).abs.floor
puts "Precisao: #{p}"
puts "Núm. digitos significativos decimais: #{d}"
puts "Núm. bits da mantissa: #{n}"

