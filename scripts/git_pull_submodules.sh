#!/bin/bash

git submodule update --init

declare -a submodules=("xtd.console" "xtd.delegates" "xtd.diagnostics" "xtd.drawing" "xtd.environment" "xtd.forms" "xtd.io" "xtd.properties" "xtd.strings" "xtd.tunit")

for submodule in ${submodules[@]}; do
  cd $submodule
  git pull origin master
  cd ..
done
