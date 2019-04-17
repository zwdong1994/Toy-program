import os
import sys
ref = {}
Max = {}
fin_add = {}
add_fin = {}


if len(sys.argv) < 2:
    print("Wrong parameter!")
    sys.exit()
handle = open(sys.argv[1], 'rb')
for eachline in handle:
    list = eachline.split(" ")
    fin = list[8]
    add = list[3]
    fin = fin.strip('\n')
    if add in add_fin:
        if fin in fin_add:
            if add not in fin_add[fin]:
                if ref[add_fin[add]] > 0:
                    ref[add_fin[add]] -= 1
                fin_add[fin].append(add)
                ref[fin] += 1
                if ref[fin] > Max[fin]:
                    Max[fin] = ref[fin]
                fin_add[add_fin[add]].remove(add)
                add_fin[add] = fin
        else:
            if ref[add_fin[add]] > 0:
                ref[add_fin[add]] -= 1
                fin_add[add_fin[add]].remove(add)
            add_list = []
            add_list.append(add)
            fin_add[fin] = add_list
            Max[fin] = 1
            ref[fin] = 1
            add_fin[add] = fin

    else:
        add_fin[add] = fin
        if fin in fin_add:
            if add not in fin_add[fin]:
                fin_add[fin].append(add)
                ref[fin] += 1
                if ref[fin] > Max[fin]:
                    Max[fin] = ref[fin]
        else:
            add_list = []
            add_list.append(add)
            fin_add[fin] = add_list
            Max[fin] = 1
            ref[fin] = 1
print 'FIngerprint\t' 'Refrence\t' 'Max\t'
for i in ref:
#    print i
    if Max[i] > 0:
        print '%s\t' % i, '%d\t' % ref[i], '%d\t' % Max[i]
handle.close()
