#!/bin/bash

./scripts/git_pull_submodules.sh

declare -a submodules=("xtd_tunit" "xtd_properties" "xtd_delegates" "xtd_io" "xtd_strings" "xtd_diagnostics" "xtd_core" "xtd_console" "xtd_drawing" "xtd_forms")

for submodule in ${submodules[@]}; do
  cd src/$submodule
  ./scripts/git_pull_submodules.sh
  cd ../..
done
