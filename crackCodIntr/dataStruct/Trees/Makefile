all: tree

tree:	treeMain.o tree.o
		gcc treeMain.o tree.o -o tree
treeMain.o: treeMain.c
			gcc -c  treeMain.c
tree.o:		tree.c
			gcc -c tree.c
clear :
		rm -rf *.o  

