import random

def join(l):
  return str.join(' ', map(str, l))

n = 200000
w = 200
print(n)
print(join([ 1000000000 for _ in range(n) ]))