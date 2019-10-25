#!/bin/bash

git submodule update --init

declare -a submodules=("xtd_delegates" "xtd_diagnostics" "xtd_drawing" "xtd_core" "xtd_io" "xtd_strings" "xtd_tunit")
for submodule in ${submodules[@]}; do
  cd src/$submodule
  git pull origin master
  cd ../..
done
