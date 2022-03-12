# Philip Jasionowski, 100751888
# William Robinson, 100751756
# Laith Hasan, 100738896
#Operating Systems Lab 2

fillshell: fillshell.c utility.c fillshell.h
	gcc -o fillshell.c utility.c -o myshell
