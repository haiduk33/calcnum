# encoding: utf-8

def format_num num
  #"% 12.8f" % num rescue "%s" % num
  num.to_s
end

def get_max_width column
  column.collect{|ele| format_num(ele).length}.max
end

def print_table table, header=true
  return if table.empty?
  pads = []
  (0..(table[0].length-1)).each do |i|
    pads << get_max_width(table.collect{|row| row[i]})
  end
  puts "┌─#{pads.map{|pad| '─' * pad}.join('─┬─')}─┐"
  rowify = proc do |row|
    frow = row.zip(pads).map do |line, pad|
      format_num(line).rjust(pad)
    end
    puts "│ #{frow.join(' │ ')} │"
  end
  if header
    rowify.call table[0]
    puts "├─#{pads.map{|pad| '─' * pad}.join('─┼─')}─┤"
    table[1..-1].each &rowify
  else
    table.each &rowify
  end
  puts "└─#{pads.map{|pad| '─' * pad}.join('─┴─')}─┘"
end

