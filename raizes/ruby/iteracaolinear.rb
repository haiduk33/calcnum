# Algoritmo ITERAÇÃO LINEAR

def iteracaolinear x0, &g
  x = g.call(x0)
  k = 0
  while ((x - x0).abs > @tol or (g.call(x) - x).abs > @tol) and k <= @nmi do
    x0 = x
    x = g.call(x0)
    k += 1
  end
  if k > @nmi
    then puts "Ultrapassou NMI"
    else puts "RAIZ = #{x}"
  end
end

@tol = 1.0E-3
@nmi = 100
iteracaolinear(0.6){|x| Math::exp(x) / 3}

