#!/bin/bash

git submodule update --init

declare -a submodules=()

for submodule in ${submodules[@]}; do
  cd $submodule
  git pull origin master
  cd ..
done
