require "base"
# Algoritmo NEWTON-RAPHSON

def derivada &f
  return lambda {|x| (f.call(x + @tol) - f.call(x - @tol)) / (2 * @tol)}
end

def newtonraphson x0, &f
  df = derivada &f
  @nmi.times do
    x = x0 - f.call(x0) / df.call(x0)
    return x if (x - x0).abs < @tol and f.call(x).abs < @tol
    x0 = x
  end
  return :nmi
end

@tol = 1e-3
@nmi = 100

eq1 = "exp(x) - 3 * x"
puts "Equação: #{eq1} = 0"
resolver eq1, :newtonraphson, 1.0
resolver eq1, :newtonraphson, 2.0

eq2 = "x - cos(x)"
puts "Equação: #{eq2}"
resolver eq2, :newtonraphson, 1.0

