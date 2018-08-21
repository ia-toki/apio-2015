kMaxN = 30000
import random

class DogePrint(object):
  def __init__(self):
    self._n = 0

  def Print(self, doges):
    self._n += 1
    print 'Test case {0} with {1} doges'.format(self._n, len(doges))
    f = open('doge_{0}.in'.format(self._n), 'w')
    f.write('{0} {1}\n'.format(kMaxN, len(doges)))
    for doge in doges:
      f.write('{0} {1}\n'.format(*doge))
    f.close()


def Worst():
  dogeposes = []
  posdog = 0
  touched = [False] * kMaxN
  dogeposes.append((posdog, 1))
  doglocs = [posdog]
  touched[posdog] = 1
  bak = 1
  kMaxPow = 1000
  bads = set()
  def AddLoc(pos):
    for j in range(2, kMaxPow):
      bads.add((j, pos%j))
  while len(dogeposes) < kMaxN / 2:
    found = False
    for j in range(2, kMaxN):
      if j < kMaxPow:
        if (j, posdog%j) in bads:
          continue
      else:
        failed = False
        for k in range(posdog % j, kMaxN, j):
          if touched[k] and k != posdog:
            failed = True
        if failed:
          continue
      found = False
      if bak == 1:
        trang = xrange(kMaxN-1, -1, -1)
      else:
        trang = xrange(kMaxN)
      for k in trang:
        if touched[k] or k%j != posdog%j:
          continue
        found = True
        targ = k
      if found:
        AddLoc(posdog)
        posdog = targ
        dogeposes.append((posdog, j))
        doglocs.append(posdog)
        bak = 1-bak
        touched[posdog] = 1
        break
    if not found:
      break
  middlemen = dogeposes[1:-1]
  for j in range(kMaxN):
    if not touched[j]:
      middlemen.append((j, kMaxN-1))
  random.shuffle(middlemen)
  return dogeposes[-1:] + dogeposes[:1] + middlemen


def LotsOfEdges(alledges=True):
  doges = []
  bads = [False] * kMaxN
  badcnt = 0
  for pw in range(2, kMaxN):
    if len(doges) == kMaxN-2:
      break
    for i in range(pw):
      if len(doges) == kMaxN-2:
        break
      mycnt = 0
      for j in range(i, kMaxN, pw):
          if not bads[j]:
            mycnt += 1
      if mycnt + badcnt == kMaxN:
        continue
      doges.append((i, pw))
      for j in range(i, kMaxN, pw):
          if not bads[j]:
            badcnt += 1
            bads[j] = True

  if alledges:
    targ = [(kMaxN-1, 1)]
  else:
    j = kMaxN-1
    while j >= 0:
      if not bads[j]:
        targ = [(j, 1)]
        break
      j -= 1
  random.shuffle(doges)
  return [(0, 1)] + targ + doges


def SqrtN(minval=100, maxval=400, alledges=False):
  doges = []
  bads = [False] * kMaxN
  badcnt = 0
  values = []
  for i in range(minval, maxval+1):
    for j in range(i):
      values.append((i, j))
  random.shuffle(values)
  for pw, i in values:
    if len(doges) == kMaxN-2:
      break
    mycnt = 0
    for j in range(i, kMaxN, pw):
      if j >= kMaxN/2:
        if not bads[j]:
          mycnt += 1
    if mycnt + badcnt == kMaxN/2:
      continue
    doges.append((i, pw))
    for j in range(i, kMaxN, pw):
      if j >= kMaxN/2:
        if not bads[j]:
          badcnt += 1
          bads[j] = True

  if alledges:
    targ = [(kMaxN-1, 1)]
  else:
    j = kMaxN-1
    while j >= 0:
      if not bads[j]:
        targ = [(j, 1)]
        break
      j -= 1
  random.shuffle(doges)
  return [(0, 1)] + targ + doges


def Gen():
  printer = DogePrint()
  #printer.Print([(i, 1) for i in range(kMaxN)])
  dogepowers = [(i, 1) for i in range(kMaxN)]

  printer.Print(dogepowers[:1] + dogepowers[-1:] + dogepowers[1:-1])
  printer.Print(Worst())
  printer.Print(LotsOfEdges(True))
  printer.Print(LotsOfEdges(False))

  printer.Print(SqrtN())
  printer.Print(SqrtN(200, 600))
  printer.Print(SqrtN(200, 450))
  printer.Print(SqrtN(100, 350))

Gen()
