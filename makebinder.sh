#!/usr/bin/env bash
#
# bash script that converts the C++ algorithms code into a pretty-printed PDF
# named binder.pdf. This expects to be run in a Linux/BSD environment with the
# "a2ps" command installed. On .deb and .rpm based Linux systems that command
# is in a package called "a2ps".
#
# Kevin Wortman <kwortman@fullerton.edu>
# November 2013

# This is rather quick and dirty but it works.

# check that a2ps is installed
a2ps --help >/dev/null 2>&1 || { echo >2& "error: a2ps not installed"; exit 1; }

# convert all files in algorithms/ and algorithms/floyd/ to postscript
a2ps algorithms/* algorithms/floyd/* -o binder.ps

# convert postscript to PDF
ps2pdf binder.ps

# delete postscript
rm -f binder.ps
