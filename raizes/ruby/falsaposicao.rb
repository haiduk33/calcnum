# Algoritmo BISSEÇÃO

def falsaposicao xi, xf, &f
  if f.call(xi) * f.call(xf) <= 0 then # Se f(XI)*f(XF) <= 0 então
    k = 0 # K <- 0
    p = f.call(xi) / f.call(xf) # F <- f(XI)/f(XF)
    xm = xi - (xf - xi) * p / (1 - p) # XM <- XI - ( XF - XI ) * F / (1 - F)
    # Enquanto ((|XF-XM| > TOL e |XI-XM| > TOL) ou |f(XM)| > TOL) e K <= NMI executar
    while (((xf - xm).abs > @tol and (xi - xm).abs > @tol) or f.call(xm).abs > @tol) and k <= @nmi do
      p = f.call(xi) / f.call(xf) # F <- f(XI)/f(XF)
      xm = xi - (xf - xi) * p / (1 - p) # XM <- XI - ( XF - XI ) * F / (1 - F)
      if f.call(xm) * f.call(xi) <= 0 # Se f(XM)*f(XI) <= 0
        then xf = xm # então XF <- XM
        else xi = xm # senão XI <- XM
      end # Fim (Se)
      k += 1 # K <- K + 1
    end # Fim (Enquanto)
    if k > @nmi # Se K > NMI
      then puts "Ultrapassou NMI." # então escrever "Ultrapassou NMI"
      else puts "RAIZ = #{xm}" # senão escrever "RAIZ = "; XM
    end # Fim (Se)
  else # Fim (Se)
    # senão Escrever "Não há garantia de existencia de raiz neste intervalo"
    puts "Não há garantia de existencia de raiz neste intervalo"
  end # Fim (Se)
end

@tol = 1.0E-3
@nmi = 100

falsaposicao(0.6, 0.8){|x| x - Math::cos(x)}

