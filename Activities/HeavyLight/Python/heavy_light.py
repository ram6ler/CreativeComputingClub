lines, width = (int(x) for x in input().split())
for _ in range(lines):
    seen = set()
    heavy = set()
    line = input()
    for c in line:
        if c in seen:
            heavy.add(c)
        else:
            seen.add(c)
    is_heavy = line[0] in heavy
    for i in range(1, width):
        next_is_heavy = line[i] in heavy
        if next_is_heavy == is_heavy:
            print("F")
            break
        is_heavy = next_is_heavy
    else:
        print("T")
