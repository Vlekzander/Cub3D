#!/bin/bash
podman run -it --rm -v $(pwd):/project mlx-dev "$@" 
