# uart-zynq

A bare-metal driver to interface with both UARTs on the Xilinx Zynq family
of devices.

This libary is built using the [SCons Build System](http://scons.org/) and the
"arm-none-eabi" compiler suite. To build, simply run "scons". This will generate
a linkable library "libuart-zynq" and a simple test application
"uart-zynq-main.elf".

To run on the target, the easiest approach is via U-Boot. The compilation will
generate a raw binary (without ELF metadata) so you can simply use the following
set of commands to execute on the target:
> tftpboot 0x10000 uart-zynq-main.bin && go 0x10000

Note: The application is currently defined to load from 0x10000, and must be
loaded there to avoid a data abort.

For more information, refer to the document
"Zynq-7000 AP SoC Technical Reference Manual UG585".