#!/bin/bash

./scripts/gi_pull_submodules.sh

declare -a submodules=("xtd.tunit" "xtd.delegates" "xtd.io" "xtd.strings" "xtd.console" "xtd.diagnostics" "xtd.drawing" "xtd.environment" "xtd.forms" "xtd.properties")

for submodule in ${submodules[@]}; do
  cd $submodule
  ./scripts/git_pull_submodules.sh
  cd ..
done
