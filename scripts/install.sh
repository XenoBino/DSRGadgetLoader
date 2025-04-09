#!/usr/bin/bash

if [[ "$#" -lt 1 ]]; then
	printf -- "Usage: install.sh [Path to DARK SOULS REMASTERED]\n"
	exit 1
fi

if ! [[ -f "Build/DSRGadgetLoader.zip" ]]; then
	printf -- "Please run scripts/build.sh first\n"
	exit 1
fi

if ! [[ -e "$1" ]]; then
	printf -- "%s: No such file or directory\n" "$1"
	exit 1
fi

if ! [[ -d "$1" ]]; then
	printf -- "%s: Not a directory\n" "$1"
	exit 1
fi

if ! [[ -f "$1/DarkSoulsRemastered.exe" ]]; then
	printf -- "%s: No such file or directory\n" "$1/DarkSoulsRemastered.exe"
	exit 1
fi

ZIP="$(realpath -- "Build/DSRGadgetLoader.zip")"
cd -- "$1" && unzip -X -- "${ZIP}"
