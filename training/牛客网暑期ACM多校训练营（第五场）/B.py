m = int(input())
p = [0, 2]
q = [0, 6]
while p[1] < m:
    t = p[1]
    p[1] = 6 * p[1] - p[0]
    p[0] = t
while q[1] < m:
    t = q[1]
    q[1] = 14 * q[1] - q[0]
    q[0] = t;
print(min(q[1], p[1]))