marksheet = list()
for _ in range(int(input())):
    name = input()
    score = float(input())
    marksheet.append([name,score])

second_highest = sorted(list(set([marks for name, marks in marksheet])))[1]
print('\n'.join(a for a,b in sorted(marksheet) if b == second_highest ))