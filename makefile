all:
	make isort
	make ssort

isort:
	gcc -Werror isort.c sortutils.c -o isort

ssort:
	gcc -Werror ssort.c sortutils.c -o ssort

clean:
	rm isort
	rm ssort

test:
	python sortingTests.py ./isort
	python sortingTests.py ./ssort
