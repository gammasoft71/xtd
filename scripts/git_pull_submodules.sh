#!/bin/bash

git submodule update --init

declare -a submodules=("xtd.delegates" "xtd.diagnostics" "xtd.drawing" "xtd.environment" "xtd.io" "xtd.strings" "xtd.tunit")
for submodule in ${submodules[@]}; do
  cd $submodule
  git pull origin master
  cd ..
done
