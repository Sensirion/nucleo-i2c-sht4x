
# ------------------------------------------------
# Tool to download the image to the flash of th up
# ------------------------------------------------
PROGRAMMER=/mnt/c/'Program Files'/STMicroelectronics/STM32Cube/STM32CubeProgrammer/bin/STM32_Programmer_CLI.exe

# ------------------------------------------------
# installation path of GNU Arm Embedded Toolchain
# ------------------------------------------------

#GCC path when using cygwin
#GCC_PATH=/cygdrive/c/'Program Files (x86)'/'GNU Arm Embedded Toolchain'/'10 2021.10'/bin

#GCC path when using wsl
GCC_PATH=/mnt/c/'Program Files (x86)'/'GNU Arm Embedded Toolchain'/'10 2021.10'/bin

#GCC path when using dos command prompt or powershell
#GCC_PATH="C:\Program Files (x86)\GNU Arm Embedded Toolchain\10 2021.10\bin"

# -------------------------------------------------
# folder separator - use forward slash for liunx and
# backward slash for windows
# -------------------------------------------------
PATH_DELIM = /

# --------------------------------------------------
# extension for executable
# --------------------------------------------------
# setting for windows
EXE = .exe

# setting for linux
#EXE = 