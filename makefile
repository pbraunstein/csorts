isort:
	gcc -Werror isort.c sortutils.c -o isort
clean:
	rm isort

test:
	python sortingTests.py ./isort
