import random

def join(l):
  return str.join(' ', map(str, l))

n = 200000
w = 200
print(n, 100, 50)
print(join([ 1 for _ in range(n) ]))

# # Random strings thingy
# k = 1000
# n = 1000
# for _ in range(n):
#   s = [ chr(random.randint(ord('a'), ord('z'))) for _ in range(k) ]
#   # print(str.join('', s))
#   print(s)