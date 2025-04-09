# DSR Gadget Loader

A simple mod for DSR that makes DSR-Gadget open automatically on game launch.

## But why??

I am on linux, proton. Making DSR-Gadget run in the same address space as the
game proved to be way more time consuming than it needs to be. You can always
close DSR Gadget if you're afraid of the Anti-Cheat.

## Dependencies

Currently the project uses
[LazyLoader](https://github.com/XenoBino/LazyLoader.git)
(A fork to support meson) to be loaded into memory.

## Usage

Unpack DSR-Gadget in the same directory as 'DarkSoulsRemastered.exe'. So the
filetree becomes:

```
|__ DarkSoulsRemastered.exe
|
|__ dllMods/
|  |_ DSRGadget.dll  # This mod
|  |_ ...            # Other mods like Painted Worlds
|
|__ DSR Gadget 1.6/
|  |_ DSR-Gadget.exe
|  |_ DSR-Gadget.pdb
|  |_ DSR-Gadget.exe.config
|  |_ readme.txt
|
|__ dinput8.dll    # lazyLoad mentioned above
|__ lazyLoad.ini   # ...
```

# Compiling

## Automated

To build run:

```shell
./scripts/build.sh
```

Which would produce `Build/DSRGadgetLoader.zip`. You can automate the
installation with:

```shell
./scripts/install.sh "<path to 'DARK SOULS REMASTERED/'>"
```

Or unpack it yourself as described above.

## Manual

You need a cross-compiler for the `x86_64-w64-mingw32` target. Installation is not
discussed here.

Configure and build the project with:

```shell
meson setup --cross-file cross-compile.txt --wipe Build/
meson compile -C Build/
```

The resulting file `Build/libDSRGadget.so` is a valid dll file that can be moved
into the `dllMods/` to be loaded by `lazyLoad`.

You can, however run: `meson install -C Build/` to produce a valid `.tar.gz` for
use.
