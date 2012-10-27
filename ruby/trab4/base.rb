# encoding: utf-8
# Base para aplicar metodos
require './pprint'

include Math

def convert_to_lambda &block
  obj = Object.new
  obj.define_singleton_method(:_, &block)
  return obj.method(:_).to_proc
end

module Calcnum
  def self.algoritmo metodo, &rotina
    define_method metodo do |*args, &fun|
      @tabela = []
      if @fun = fun
        def f(x) @fun.call(x) end
      else
        def f(x) raise "Esse método recebe uma equação." end
      end
      #rotina.bind(self)
      def tol; @tol end
      rotina.call(*args)
    end
  end
  def tabela *vals
    @tabela << vals.map{|v| fmt(v) rescue v}
  end
  def iterar &passo
    @nmi.times &passo
    return :erro_nmi
  end
  def fmt val
    case val
    when 0.0
      0
    when Array
      val.map {|v| fmt(v)}
    when Integer
      val
    when Complex
      p = -log10(@tol).ceil
      return fmt(val.real) if val.imag.abs < tol
      return "#{fmt(val.imag)}i" if val.real.abs < tol
      "%.#{p}f%+.#{p}fi" % [val.real, val.imag]
    else
      p = -log10(@tol).ceil
      p = 0 if p < 0
      "%.#{p}f" % val
    end
  end
  def aplicar metodo, *args, &fun
    case r = method(metodo).call(*args, &fun)
    when :erro_intervalo
      puts "Não há garantia de existencia de raiz neste intervalo"
    when :erro_nmi
      puts "Ultrapassou o NMI."
    when Symbol
      puts "Erro desconhecido."
    else
      if @tabelar
        print_table @tabela
      end
      puts "Raiz: #{fmt(r)}"
    end
  end
  def resolver equacao, metodo, *parametros
    aplicar metodo, *parametros, &equacao.to_fun
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

