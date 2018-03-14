n = int(input())
arr = list(map(int, input().split()))
nmax = max(arr)
while nmax in arr : 
    arr.remove(nmax)
rup = max(arr)
print(rup)