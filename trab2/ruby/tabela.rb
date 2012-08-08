require './pprint'

include Math
PIE = PI / E

module Enumerable
  def mapred; map{|i| @t = yield(i, @t)} end
  def myfold(init) mapred{|i, p| p.nil? ? init : yield(i, p)}.reduce(:+) end
end

def mysin(x) (0..@n).myfold(x){|k, z| -z * x * x / (2.0 * k) / (2.0 * k + 1.0)} end
def mycos(x) (0..@n).myfold(1){|k, z| -z * x * x / (2.0 * k) / (2.0 * k - 1.0)} end
def mytan(x) mysin(x) / mycos(x) end
def mypi; 4 * (0..@n).myfold(1){|k, z| -z * (2.0 * k - 1.0) / (2.0 * k + 1.0)} end
def mye; (0..@n).myfold(1.0){|k, z| z / k} end
def mypie; mypi / mye end

tabela = lambda do |n|
  @n = n
  # calcular valores
  valores =
    ["n=#{@n}", 'Ve', 'Va', 'Eabs', 'Erel'],
    ['pi', PI, mypi],
    ['e', E, mye],
    ['pi/e', PIE, mypie],
    ['sen(pi/e)', sin(PIE), mysin(mypie)],
    ['cos(pi/e)', cos(PIE), mycos(mypie)],
    ['tg(pi/e)', tan(PIE), mytan(mypie)]
  #calcular erros
  for v in valores[1..-1] do
    ve, va = v[1], v[2]
    v << eabs = ve - va
    v << erel = eabs / ve
  end
  # imprimir tabela e uma linha em branco
  print_table valores
  puts
end

[3, 10, 30, 84].map &tabela

