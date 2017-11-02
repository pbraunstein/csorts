#!/usr/bin/env python

import random
import subprocess

from sys import argv

RAND_LEN = 100

def main():
    print "TESTING:", argv[1].upper()

    # test empty
    test_empty()

    # test one element
    test_one_element_zero()
    test_one_element_negative()
    test_one_element_positive()

    # test two elements sorted
    test_two_elements_sorted_positive()
    test_two_elements_sorted_negative()
    test_two_elements_sorted_negative_to_positive()

    # test two elements unsorted
    test_two_elements_unsorted_positive()
    test_two_elements_unsorted_negative()
    test_two_elements_unsorted_positive_to_negative()

    # already sorted tests
    test_already_sorted_positive()
    test_alread_sorted_negative()
    test_already_sorted_negative_to_positive()

    # test reverse order
    test_reverse_order_positive()
    test_reverse_order_negative()
    test_reverse_order_negative_to_positive()

    # test sorted except for edges
    test_sorted_except_zero_element()
    test_sorted_except_last_element()
    test_sorted_except_both_edges()

    # repeated elements
    test_repeated_elements()
    test_only_repeated_elements()

    # random tests
    test_ten_small_range()
    test_ten_medium_range()
    test_ten_long_range()

    # large input tests
    test_one_thousand_element_sort()
    test_twenty_thousand_element_sort()

    print "ALL", argv[1].upper(), "TESTS PASS"
    print

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

def test_reverse_order_positive():
    print "test reverse order positive.....",
    _run_test([4, 3, 2, 1], '1 2 3 4')

def test_reverse_order_negative():
    print "test reverse order negative.....",
    _run_test([-2, -6, -8, -100], '-100 -8 -6 -2')

def test_reverse_order_negative_to_positive():
    print "test reverse order negative to positive.....",
    _run_test([1092, 12, 0, -2, -6, -8, -100], '-100 -8 -6 -2 0 12 1092')

def test_two_elements_sorted_positive():
    print "test two elements sorted positive.....",
    _run_test([3, 6], '3 6')

def test_two_elements_sorted_negative():
    print "test two elements sorted negative.....",
    _run_test([-100, -50], '-100 -50')

def test_two_elements_sorted_negative_to_positive():
    print "test two elements sorted negative to positive.....",
    _run_test([-190, 280], '-190 280')

def test_two_elements_unsorted_positive():
    print "test two elements unsorted positive.....",
    _run_test([90, 20], '20 90')

def test_two_elements_unsorted_negative():
    print "test two elements unsorted negative.....",
    _run_test([-3, -2000], '-2000 -3')

def test_two_elements_unsorted_positive_to_negative():
    print "test two elements unsorted positive to negative.....",
    _run_test([100, -20], '-20 100')

def test_sorted_except_zero_element():
    print "test sorted except zero element.....",
    _run_test([0, -9, -4, -3, -1], '-9 -4 -3 -1 0')

def test_sorted_except_last_element():
    print "test sorted except last element.....",
    _run_test([1, 2, 3, 4, 0], '0 1 2 3 4')

def test_sorted_except_both_edges():
    print "test sorted except both edges.....",
    _run_test([90, 1, 2, 3, 4, 0], '0 1 2 3 4 90')

def test_repeated_elements():
    print "test repeated elements.....",
    _run_test([1, 2, 2, 3, 4, 2, 3, 6], '1 2 2 2 3 3 4 6')

def test_only_repeated_elements():
    print "test only repeated elements.....",
    _run_test([2, 2, 2, 2, 2], '2 2 2 2 2')

def test_ten_small_range():
    print "10 small range tests....."
    for x in range(10):
        inList, outString = _rand_test(-5, 5, RAND_LEN)
        _run_test(inList, outString)

def test_ten_medium_range():
    print "10 medium range tests....."
    for x in range(10):
        inList, outString = _rand_test(-100, 100, RAND_LEN)
        _run_test(inList, outString)

def test_ten_long_range():
    print "10 long range tests....."
    for x in range(10):
        inList, outString = _rand_test(-10000, 10000, RAND_LEN)
        _run_test(inList, outString)

def test_one_thousand_element_sort():
    print "test one thousand element sort.....",
    inList, outString = _rand_test(-1000, 1000, 1000)
    _run_test(inList, outString)

def test_twenty_thousand_element_sort():
    print "test twenty thousand element sort.....",
    inList, outString = _rand_test(-1000, 1000, 20000)
    _run_test(inList, outString)


def _run_test(testInput, expectedOutput):
    testInput = [str(x) for x in testInput]
    proc = subprocess.Popen([argv[1]] + testInput, stdout=subprocess.PIPE)
    stdout, _ = proc.communicate()
    assert stdout.strip() == expectedOutput, '{0} != {1}'.format(stdout.strip(), expectedOutput)
    print "successs"

def _rand_test(lowerBound, upperBound, numElements):
    inputArr = []
    for x in range(numElements):
        inputArr.append(random.randint(lowerBound, upperBound))

    sortedArr = sorted(inputArr)
    sortedStrArr = [str(x) for x in sortedArr]
    outputString = ' '.join(sortedStrArr)

    return inputArr, outputString

main()

