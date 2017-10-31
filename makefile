all:
	make isort
	make ssort
	make bsort

isort:
	gcc -Werror isort.c sortutils.c -o isort

ssort:
	gcc -Werror ssort.c sortutils.c -o ssort

bsort:
	gcc -Werror bsort.c sortutils.c -o bsort

clean:
	rm isort
	rm ssort
	rm bsort

test:
	python sortingTests.py ./isort
	python sortingTests.py ./ssort
	python sortingTests.py ./bsort
