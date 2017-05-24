#
#  SConstruct
#
#  Initial entry point for SCons build system
#
#  2017.05.21 Created
#

import os

env = Environment(ENV = os.environ,
     CC      = 'arm-none-eabi-gcc',
     LINK    = 'arm-none-eabi-ld',
     CXX     = 'arm-none-eabi-g++',
     AR      = 'arm-none-eabi-ar',
     AS      = 'arm-none-eabi-as',
     RANLIB  = 'arm-none-eabi-ranlib',
     OBJCOPY = 'arm-none-eabi-objcopy',

     CCCOMSTR      = '  CC     $TARGET',
     CXXCOMSTR     = '  CXX    $TARGET',
     LINKCOMSTR    = '  LINK   $TARGET',
     ARCOMSTR      = '  AR     $TARGET',
     ASCOMSTR      = '  AS     $TARGET',
     RANLIBSTR     = '  RANLIB $TARGET',

     CCFLAGS = '-mcpu=cortex-a9 -march=armv7-a -mfpu=vfpv3 -mfloat-abi=hard -mlittle-endian',
     LINKFLAGS = ' -T memmap.ld',
     ARFLAGS = '-r -c',
     CCCOMFLAGS = '$CPPFLAGS $_CPPDEFFLAGS $_CPPINCFLAGS -c $SOURCES -o$TARGET $CCPCHFLAGS',

     OBJSUFFIX = '.o',
     PROGSUFFIX = '.elf',
                  
)

def arm_generator(source, target, env, for_signature):
    return '$OBJCOPY -O binary %s %s'%(source[0], target[0])
env.Append(BUILDERS = {
    'Objcopy': Builder(
        generator=arm_generator,
        suffix='.bin',
        src_suffix='.elf'
    )
})

uart_zynq = env.StaticLibrary(
            'uart-zynq',
	    ['uart-zynq.c'])

uart_zynq_test = env.Program(
     'uart-zynq-test',
     ['uart-zynq-main.c',
      'startup.s'],
      LIBS=['uart-zynq'],
      LIBPATH='.'
)
 
env.Objcopy(uart_zynq_test)