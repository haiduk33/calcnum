# encoding: utf-8
include Math
# Base para aplicar metodos

def aplicar metodo, *args, &fun
  case r = method(metodo).call(*args, &fun)
  when :intervalo
    puts "Não há garantia de existencia de raiz neste intervalo"
  when :nmi
    puts "Ultrapassou o NMI."
  when Symbol
    puts "Erro desconhecido."
  else
    p = -log10(@tol).ceil
    p = 0 if p < 0
    puts "Raiz: %.#{p}f" % r
  end
end

def resolver equacao, metodo, *parametros
  aplicar metodo, *parametros, &lambda {|x| eval(equacao)}
end

