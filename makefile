all:
	make isort
	make ssort
	make bsort
	make qsort

isort:
	gcc -Werror isort.c sortutils.c -o isort

ssort:
	gcc -Werror ssort.c sortutils.c -o ssort

bsort:
	gcc -Werror bsort.c sortutils.c -o bsort

qsort:
	gcc -Werror qsort.c sortutils.c -o qsort

clean:
	rm isort
	rm ssort
	rm bsort
	rm qsort

test:
	time python sortingTests.py ./isort
	time python sortingTests.py ./ssort
	time python sortingTests.py ./bsort
	time python sortingTests.py ./qsort
