import random

def join(l):
  return str.join(' ', map(str, l))

n = 5
w = 200
print(n, w)
print(join([ random.randint(1,w) for _ in range(n*2) ]))