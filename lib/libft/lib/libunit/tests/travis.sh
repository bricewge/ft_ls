#!/bin/bash
tmp=`$(dirname $0)/tests`
echo "$tmp"
echo "$tmp" | tail -1 | grep "^1/6 tests checked$" -q
exit $?
