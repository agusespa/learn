portnames = ["PAN", "AMS", "CAS", "NYC", "HEL"]

D = [
        [0,8943,8019,3652,10545],
        [8943,0,2619,6317,2078],
        [8019,2619,0,5836,4939],
        [3652,6317,5836,0,7825],
        [10545,2078,4939,7825,0]
    ]

# assume 20g per km per metric ton (of pineapples)
co2 = 0.020

smallest = 1000000
bestroute = [0, 0, 0, 0, 0]


def permutations(route, ports):
    global smallest, bestroute

    if len(ports) < 1:
        sum = (D[route[0]][route[1]] + D[route[1]][route[2]] + D[route[2]][route[3]] + D[route[3]][route[4]]) * co2

        if sum < smallest:
            smallest = sum
            bestroute = route
    else:
        for i in range(len(ports)):
            permutations(route+[ports[i]], ports[:i]+ports[i+1:])


def main():
    permutations([0], list(range(1, len(portnames))))

    print(' '.join([portnames[i] for i in bestroute]) + " %.1f kg" % smallest)

main()
