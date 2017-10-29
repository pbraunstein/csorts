isort:
	gcc -Werror isort.c -o isort
clean:
	rm isort

test:
	python sortingTests.py ./isort
