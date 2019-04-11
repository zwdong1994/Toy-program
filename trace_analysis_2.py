import os
import sys
ref = {}
change = {}
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
                change[add_fin[add]] += 1
                ref[add_fin[add]] -= 1
                fin_add[fin].append(add)
                ref[fin] += 1
                fin_add[add_fin[add]].remove(add)
                if ref[add_fin[add]] == 0:
                    del fin_add[add_fin[add]]
                add_fin[add] = fin
        else:
            change[add_fin[add]] += 1
            ref[add_fin[add]] -= 1
            fin_add[add_fin[add]].remove(add)
            if ref[add_fin[add]] == 0:
                del fin_add[add_fin[add]]
            add_list = []
            add_list.append(add)
            fin_add[fin] = add_list
            change[fin] = 0
            ref[fin] = 1
            add_fin[add] = fin

    else:
        add_fin[add] = fin
        if fin in fin_add:
            if add not in fin_add[fin]:
                fin_add[fin].append(add)
                ref[fin] += 1
        else:
            add_list = []
            add_list.append(add)
            fin_add[fin] = add_list
            change[fin] = 0
            ref[fin] = 1
print "Refrence Change"
for i in ref:
#    print i
    if change[i] > 0:
        print ref[i],change[i]
handle.close()
