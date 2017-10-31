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

def _run_test(testInput, expectedOutput):
    testInput = [str(x) for x in testInput]
    proc = subprocess.Popen([argv[1]] + testInput, stdout=subprocess.PIPE)
    stdout, _ = proc.communicate()
    # import ipdb; ipdb.set_trace()
    assert stdout.strip() == expectedOutput, '{0} != {1}'.format(stdout.strip(), expectedOutput)
    print "successs"

main()

