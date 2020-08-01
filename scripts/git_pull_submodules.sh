#!/bin/bash

git submodule update --init

declare -a submodules=("xtd_io xtd_strings xtd_delegates xtd_tunit")

for submodule in ${submodules[@]}; do
  cd src/$submodule
  git pull origin master
  cd ../..
done
