#!/bin/bash

declare -a submodules=("xtd.console" "xtd.delegates" "xtd.diagnostics" "xtd.drawing" "xtd.environment" "xtd.forms" "xtd.io" "xtd.properties" "xtd.strings" "xtd.tunit")

cd xtd.delegates

for submodule in ${submodules[@]}; do
  cd $submodule
  git pull
  cd ..
done
