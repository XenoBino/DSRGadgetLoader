#!/usr/bin/bash

if [[ -z "${MESON_BUILD_ROOT}" ]]; then
	printf -- "MESON_BUILD_ROOT must be defined!\n"
	printf -- "Please run `meson install` instead\n"
	exit 1
fi

BUILD="${MESON_BUILD_ROOT}"
PKG="${BUILD}/pkg/"
ZIP="${BUILD}/DSRGadgetLoader.zip"

if [[ -f "${ZIP}" ]]; then
	rm -f -- "${ZIP}"
fi

mkdir -p -- "${PKG}/dllMods/"
cp -- "${BUILD}/libDSRGadgetLoader.so" "${PKG}/dllMods/DSRGadgetLoader.dll"
cp -- "${BUILD}/DSRGadgetLoader.dll.pdb" "${PKG}/dllMods/"
x86_64-w64-mingw32-strip -- "${PKG}/dllMods/DSRGadgetLoader.dll"
cd "${PKG}" && zip -r0 "${ZIP}" -- dllMods
