
#installing mbed command line interface
https://os.mbed.com/docs/mbed-os/v6.14/build-tools/install-and-set-up.html

#Instructions to build program
#download mbed-cli 
python3 -m pip install mbed-cli
#update mbed-cli 
python3 -m pip install -U mbed-cli
#config Program_Directory - likely unnecessary
mbed new .
mbed add mbed-os
#specify target device
mbed target LPC1768
#specify toolchain
#if you have inbed Studo installed or are using a paid toolchain
mdbed toolchain ARM
# GCC_ARM
#specifiy toolchain as GCC_ARM
mbed toolchain GCC_ARM
#configure path for compiler location (can do either of the following)
#To set path to compiler do 1 of the following:
#1- Mbed cli config (local first, then global)
#the -G sets the path globally so other projects can use that compiler too
#Linux
mbed config -G GCC_ARM_PATH /usr/bin/
#Windows
mbed config -G GCC_ARM_PATH "C:\Program Files (x86)\GNU Arm Embedded Toolchain\10 2021.10\bin"
#sometimes the path gets messege up, add something similiar to Env variables
C:\Users\Colton\AppData\Local\Packages\PythonSoftwareFoundation.Python.3.10_qbz5n2kfra8p0\LocalCache\local-packages\Python310\Scripts

#2- Environment variables
export MBED_GCC_ARM_PATH=/usr/bin/arm-none-eabi-gcc
#to compile the Mbed program
mbed compile
#copy build image to device if named drive (D:)
cp ./BUILD/LPC1768/ARM/<program name>.bin D



#Install GCC_ARM toolchain
If you get errors while compiling, make sure you have a toolchain on your system for mbed to use
#Download from
https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm/downloads
#unpack
tar -xjf gcc-arm-none-eabi-10.3-2021.07-aarch64-linux.tar.bz2
#install 
sudo mv gcc-arm-none-eabi-10.3-2021.07 /usr/bin/
export PATH=$PATH:$/usr/bin/gcc-arm-none-eabi-10-2021.07/bin





Example GPS Program
https://os.mbed.com/users/mlee350/notebook/adafruit-ultimate-gps-breakout-board/
Where the Adafruit_GPS code came from:
https://os.mbed.com/users/mlee350/code/MBed_Adafruit-GPS-Library//file/a23e3099bb0a/MBed_Adafruit_GPS.cpp/

----------------------------
Useful Links for coding help
----------------------------
UnbufferedSerial Class for Bluetooth
https://os.mbed.com/docs/mbed-os/v6.4/apis/unbufferedserial.html
Serial in Linux C
https://blog.mbedded.ninja/programming/operating-systems/linux/linux-serial-ports-using-c-cpp/#full-example
Serial I/O CPP
https://wangbaiyuan.cn/en/c-serial-communication-write-reading-2.html
Linux Bluetooth
http://www.penguintutor.com/blog/viewpost.php?id=wp6392
Serial communication
https://www.cmrr.umn.edu/~strupp/serial.html
Bluetooth Essentials
http://read.pudn.com/downloads166/ebook/757380/bluetooth_essentials_for_programmers.4272206415.pdf
Qt Tutorial
https://www.youtube.com/watch?v=txGRU7OrTZo
Static Compile for Qt
https://www.youtube.com/watch?v=chMNUzpN4pw