#!/bin/bash

./scripts/gi_pull_submodules.sh

declare -a submodules=("xtd.tunit" "xtd.strings" "xtd.console" "xtd.delegates" "xtd.diagnostics" "xtd.drawing" "xtd.environment" "xtd.forms" "xtd.io" "xtd.properties")

for submodule in ${submodules[@]}; do
  cd $submodule
  ./scripts/git_pull_submodules.sh
  cd ..
done
