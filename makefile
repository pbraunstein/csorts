all:
	make isort
	make ssort
	make bsort
	make qsort
	make msort
	make hsort
	make csort
	make rsort

isort:
	gcc -Werror isort.c sortutils.c -o isort

ssort:
	gcc -Werror ssort.c sortutils.c -o ssort

bsort:
	gcc -Werror bsort.c sortutils.c -o bsort

qsort:
	gcc -Werror qsort.c sortutils.c -o qsort

msort:
	gcc -Werror msort.c sortutils.c -o msort

hsort:
	gcc -Werror hsort.c sortutils.c -o hsort

csort:
	gcc -Werror csort.c sortutils.c -o csort

rsort:
	gcc -Werror rsort.c sortutils.c -o rsort

clean:
	rm isort
	rm ssort
	rm bsort
	rm qsort
	rm msort
	rm hsort
	rm csort
	rm rsort

test:
	python sortingTests.py ./isort
	python sortingTests.py ./ssort
	python sortingTests.py ./bsort
	python sortingTests.py ./qsort
	python sortingTests.py ./msort
	python sortingTests.py ./hsort
	python sortingTests.py ./csort
	python sortingTests.py ./rsort

stressTest:
	time python sortingTests.py ./isort --stress
	time python sortingTests.py ./ssort --stress
	time python sortingTests.py ./bsort --stress
	time python sortingTests.py ./qsort --stress
	time python sortingTests.py ./msort --stress
	time python sortingTests.py ./hsort --stress
	time python sortingTests.py ./csort --stress
	time python sortingTests.py ./rsort --stress
