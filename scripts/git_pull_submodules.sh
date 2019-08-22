#!/bin/bash

declare -a submodules=("xtd.delegates" "xtd.diagnostics" "xtd.drawing" "xtd.environment" "xtd.io" "xtd.strings" "xtd.tunit")

cd xtd.delegates

for submodule in ${submodules[@]}; do
  cd $submodule
  git pull
  cd ..
done
