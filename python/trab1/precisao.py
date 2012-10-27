# coding=utf-8
from math import log, floor

p = 1.0
while p + 1 > 1:
    p = p / 2
p = 2 * p
d = abs(floor(log(p, 10)))
n = floor(abs(log(p, 2)))
print 'Precisão: %g' % p
print 'Núm. dígitos significativos decimais: %i' % d
print 'Núm. bits da mantissa: %i' % n

