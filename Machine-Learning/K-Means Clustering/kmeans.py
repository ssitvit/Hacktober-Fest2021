import math
def eucdist(x1, y1, x2, y2):
    return round(math.sqrt((x1-x2)**2 + (y1-y2)**2),2)

def printCluster(cl):
    for i in range(len(cl)):
        print("Cluster " + str(i+1) + " = ")
        print(cl[i])

def printCentroid(cl):
    print("Cluster centres are : ")
    print(cl)

def getClusterCentre(k, cluster, cnew):
    flag = False
    for i in range(k):
        cx, cy = 0, 0
        for j in range(len(cluster[i])):
            cx += x[cluster[i][j]-1]
            cy += y[cluster[i][j]-1]
        cx = round(cx/len(cluster[i]), 2)
        cy = round(cy/len(cluster[i]), 2)
        if (cnew[i] == [cx, cy]):
            flag = True
        else:
            flag = False
        cnew[i] = [cx, cy]

    return flag

x = list(map(float, input().split()))
y = list(map(float, input().split()))
n = len(x)

print ("The given table")
for i in range(n):
    print (i+1, "\t", x[i], "\t", y[i])

k = int(input("Enter number of clusters"))
print("Enter initial centroids")
cl = list(map(int, input().split()))

for i in range(len(cl)):
    cl[i] = [x[cl[i]-1], y[cl[i]-1]]

print()

num = 0

while(True):
    table = []
    num+=1
    print("Table after " + str(num) + " iteration")
    for i in range(n):
        col = []
        for j in range(k):
            col.append(eucdist(x[i], y[i], cl[j][0], cl[j][1]))
        table.append(col)

    for i in range(n):
        for j in range(k):
            print(table[i][j], end = '\t')
        print()

    cluster = [0] * k

    for i in range(n):
        posmx = table[i].index(min(table[i]))
        try:
            cluster[posmx].append(i+1)
        except:
            cluster[posmx] = [i+1]

    print()
    print("Clusters after " + str(num) + " iteration")
    printCluster(cluster)
    print()

    clold = cl
    if (getClusterCentre(k, cluster, cl)):
        printCentroid(cl)
        print()
        print("Final Clusters are")
        printCluster(cluster)
        break

    else:
        printCentroid(cl)
