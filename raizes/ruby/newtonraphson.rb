require "base"
# Algoritmo NEWTON-RAPHSON

def derivative &f
  return lambda {|x| (f.call(x + @tol) - f.call(x - @tol)) / (2 * @tol)}
end

def newtonraphson x0, &f
  df = derivative &f
  @nmi.times do
    x = x0 - f.call(x0) / df.call(x0)
    return x if (x - x0).abs < @tol and f.call(x).abs < @tol
    x0 = x
  end
  return :nmi
end

include Math

@tol = 1e-3
@nmi = 100

f1 = lambda {|x| exp(x) - 3 * x}
puts "Equação: exp(x) - 3 * x = 0"
aplicar :newtonraphson, 1.0, &f1
aplicar :newtonraphson, 2.0, &f1

f2 = lambda {|x| x - cos(x)}
puts "Equação: x - cos(x) = 0"
aplicar :newtonraphson, 1.0, &f2

