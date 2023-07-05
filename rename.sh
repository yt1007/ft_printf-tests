#!/bin/bash

if [[ -e diff.out && diff.ret ]]; then
	mkdir -p diffs;
	mv -f diff.out diffs/${1}.out;
	mv -f diff.ret diffs/${1}.ret;
fi;

exit;
