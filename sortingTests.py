#!/usr/bin/env python

import subprocess

from sys import argv

def main():
    test_already_sorted()

def test_already_sorted():
    print "test already sorted.....",
    _run_test([2, 3, 4, 8], '2 3 4 8')
    print "successs"

def _run_test(testInput, expectedOutput):
    testInput = [str(x) for x in testInput]
    proc = subprocess.Popen([argv[1]] + testInput, stdout=subprocess.PIPE)
    stdout, _ = proc.communicate()
    assert stdout.strip() == expectedOutput

main()

