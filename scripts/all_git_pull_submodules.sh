#!/bin/bash

./scripts/git_pull_submodules.sh

declare -a submodules=("xtd.tunit" "xtd.properties" "xtd.delegates" "xtd.io" "xtd.strings" "xtd.diagnostics" "xtd.environment" "xtd.console" "xtd.drawing" "xtd.forms")

for submodule in ${submodules[@]}; do
  cd $submodule
  ./scripts/git_pull_submodules.sh
  cd ..
done
