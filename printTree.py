def printTree(root):
    tree = [[root]]
    i = 0
    finished = False
    while not finished:
        tree.append([])
        finished = True
        for j in range(len(tree[i])):
            if tree[i][j] is not None:
                finished = False
                tree[i+1].append(tree[i][j].left)
                tree[i+1].append(tree[i][j].right)
                continue

            tree[i+1].append(None)
            tree[i+1].append(None)
        i += 1

    size = len(tree[-2])
    sep = "\t"

    for i in range(len(tree)-2):
        pad = pow(2, len(tree) - i - 3)
        # print("Pad f")
        print( (pad-1)*sep, end='' )
        for j in range(len(tree[i])):
            elem = str(tree[i][j].val) if tree[i][j] is not None else "-"
            print( elem, end = pad*sep*2 )
        print()
