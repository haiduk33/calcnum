# coding=utf-8
from math import log, floor

z = 1.0
while z > 0:
    m = z
    z = z / 2
n = floor(log(abs(log(m, 2) + 1), 2))
print 'Magnitude: %g' % m
print 'Número de bits do expoente: %i' % n

