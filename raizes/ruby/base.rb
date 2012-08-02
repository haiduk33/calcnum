# encoding: utf-8
# Base para aplicar metodos
include Math

def algoritmo &f
  @nmi.times &f
  return :nmi
end

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

class String
  def to_eq
    begin
      eq = self
      [%w(^   **),
       %w(sen sin),
       %w(tg  tan)
      ].each {|a| eq = eq.gsub(*a)}
      eq = eq.split("=")
      eq = "(#{eq[0]}) - (#{eq[1]})"
      f = eval("lambda {|x| #{eq}}")
      f.call(0.0) # testar se essa função pode ser chamada
      return f
    rescue
      raise ArgumentError.new "Equação inválida."
    end
  end
end

def resolver equacao, metodo, *parametros
  aplicar metodo, *parametros, &equacao.to_fun
end

