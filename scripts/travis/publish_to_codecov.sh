#!/usr/bin/env sh

set -ev

# publish to codecov
export CODECOV_TOKEN="8dfddc0a-d627-4211-b69b-f82557d3145a"
bash <(curl -s https://codecov.io/bash)
