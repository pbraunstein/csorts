#!/usr/bin/env python

import subprocess
import unittest

class sortingTests(unittest.TestCase):
    pass

def main():
    proc = subprocess.Popen(['./isort', '8', '2', '3', '4'], stdout=subprocess.PIPE)
    stdout, _ = proc.communicate()
    assert stdout.strip() == '2 3 4 8'

main()

