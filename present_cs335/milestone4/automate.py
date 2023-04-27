import os
os.chdir("src")
os.system('make clean')
os.system('make')
a="./parser"
b=" --input ../tests/test_"
c=".java"
d=" --output ../output/test_"
# e=".dot"
e=".3ac"
f="./conv < ../output/test_"
g=" > ../output/assembly"
h=".s"
l="gcc ../output/assembly"
m=".s -no-pie -o ../output/exec"
# j="xdg-open ..//output/graph"
for i in range(1,11):
    os.system(a+b+str(i)+c+d+str(i)+e)
    os.system(f+str(i)+e+g+str(i)+h)
    os.system(l+str(i)+m+str(i))
    os.system("./../output/exec"+str(i))
    # os.system(j+str(i)+h)