require 'pprint'

include Math
PIE = PI / E

def factorial(n) n.zero? ? 1 : (1..n).reduce(:*) end
def somatorio(&termo) (0..@n).map(&termo).reduce(:+) end
def mysin(x) somatorio {|i| x ** (2 * i + 1) * (-1) ** i / factorial(2 * i + 2)} end
def mycos(x) somatorio {|i| x ** (2 * i) * (-1) ** i / factorial(2 * i)} end
def mytan(x) mysin(x) / mycos(x) end
def mypi; somatorio {|k| 4.0 * (-1) ** k / (2.0 * k + 1.0)} end
def mye; somatorio {|k| 1.0 / factorial(k)} end
def mypie; mypi / mye end

tabela = lambda do |n|
  @n = n
  # calcular valores
  valores =
    ['pi', PI, mypi],
    ['e', E, mye],
    ['pi/e', PIE, mypie],
    ['sen(pi/e)', sin(PIE), mysin(mypie)],
    ['cos(pi/e)', cos(PIE), mycos(mypie)],
    ['tg(pi/e)', tan(PIE), mytan(mypie)]
  #calcular erros
  for v in valores do
    ve, va = v[1], v[2]
    v << eabs = ve - va
    v << erel = eabs / ve
  end
  # imprimir tabela e uma linha em branco
  print_table valores.unshift ["n=#{@n}", 'Ve', 'Va', 'Eabs', 'Erel']
  puts
end

[3, 10, 30, 84].map &tabela

