def getWholeNumber(array, row, col):
    n = ""
    n = n + array[row][col]

    i = 1
    while not ((col - i) < 0):
        if (array[row][col - i]).isnumeric():
            n = array[row][col - i] + n
        else:
            break
        i = i + 1

    i = 1
    while not ((col + i) >= len(array[0])):
        if (array[row][col + i]).isnumeric():
                n = n + array[row][col + i] 
        else:
            break
        i = i + 1

    return int(n)
        
def getAdjacent(i):
    x = []
    for xrow, k in enumerate(i):
        for xcol, y in enumerate(k):

            if not (i[xrow][xcol].isnumeric() or i[xrow][xcol] == "."):

                savenum = 0
                num = 0
                line = 0
                y = []
                for l in range(xrow - 1, xrow + 2):
                    for z in range(xcol - 1, xcol + 2):
                        try:
                            if i[l][z].isnumeric():
                                num = getWholeNumber(i, l, z)
                                if not (num == savenum and (line - l in range(0, 2))):
                                    line = l
                                    savenum = num
                                    y.append(num)
                        except:
                            None
                x.append([i[xrow][xcol]] + y)

    return x

def solve1(filepath):
    with open(filepath) as f:
        i = f.read()
        i = i.split("\n")

        i = getAdjacent(i)
        i = list(map(lambda x: sum(x), list(map(lambda x: x[1:], i))))

        return sum(i)

def solve2(filepath):
    with open(filepath) as f:
        i = f.read()
        i = i.split("\n")

        i = getAdjacent(i)
        i = list(filter(lambda x: x[0] == "*", i ))
        i = list(map(lambda x: x[1:], i))
        i = list(filter(lambda x: len(x) == 2, i))
        i = list(map(lambda x: x[0] * x[1], i))

        return sum(i)

def main():
    filepath = "./input.txt"

    print(solve1(filepath))
    print(solve2(filepath))

main()
