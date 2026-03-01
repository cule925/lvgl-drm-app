# LVGL APP FOR RASPBERRY PI 4B

Clone the repository on your Raspberry Pi 4B device and enter it.

Before compiling on Raspberry Pi, install needed packages via `apt`:

```
sudo apt update
sudo apt upgrade
sudo apt install git cmake libdrm-dev
```

Run CMake to generate the needed Makefiles:

```
mkdir build && cd build
cmake ..
```

Build using Make:

```
make -j4
```

Clean with commands:

```
cd .. && rm build -rf
```
