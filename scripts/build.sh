#!/usr/bin/bash

if [[ -d Build/ ]]; then
	rm -rf Build/
fi

meson setup --cross-file cross-compile.txt Build/
meson compile -C Build/
meson install -C Build/
