#!/usr/bin/env python

import subprocess

from sys import argv

def main():
    print "TESTING:", argv[1].upper()

    # test empty
    test_empty()

    # test one element
    test_one_element_zero()
    test_one_element_negative()
    test_one_element_positive()

    # already sorted tests
    test_already_sorted_positive()
    test_alread_sorted_negative()
    test_already_sorted_negative_to_positive()

def test_empty():
    print "test empty.....",
    _run_test([], '')

def test_one_element_zero():
    print "test one element zero.....",
    _run_test([0], '0')

def test_one_element_negative():
    print "test one element negative.....",
    _run_test([-24], '-24')

def test_one_element_positive():
    print "test one element positive.....",
    _run_test([1321], '1321')

def test_already_sorted_positive():
    print "test already sorted positive.....",
    _run_test([2, 3, 4, 8], '2 3 4 8')

def test_alread_sorted_negative():
    print "test already sorted negative.....",
    _run_test([-5, -4, -3, -2, -1], '-5 -4 -3 -2 -1')

def test_already_sorted_negative_to_positive():
    print "test already sorted negative to positive.....",
    _run_test([-6, -4, -2, -1, 0, 3, 5, 90], '-6 -4 -2 -1 0 3 5 90')

def _run_test(testInput, expectedOutput):
    testInput = [str(x) for x in testInput]
    proc = subprocess.Popen([argv[1]] + testInput, stdout=subprocess.PIPE)
    stdout, _ = proc.communicate()
    # import ipdb; ipdb.set_trace()
    assert stdout.strip() == expectedOutput
    print "successs"

main()

