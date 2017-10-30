ssort:
	gcc -Werror ssort.c sortutils.c -o ssort

isort:
	gcc -Werror isort.c sortutils.c -o isort

clean:
	rm ssort
	rm isort

test:
	python sortingTests.py ./isort
