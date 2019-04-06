import random

def join(l):
  return str.join(' ', map(str, l))

k = 200000
print(k)
print(join([ random.randint(1,1000) for _ in range(k) ]))