# LightWave Client Open Exchange Rates
This is a sample application that illustrates how to access foreign exchange rates provided by the [Open Exchange Rates REST API](www.openexchangerates.org). The sample application is a C program that retrieves current exchange rates for USD.

## Prerequisites

+ NonStop C Compiler
+ [LightWave Client](https://docs.nuwavetech.com/display/LWCLIENT)
+ An Open Exchange Rates App Id. To obtain an App Id a free account may be opened by visiting [Open Exchange Rates Sign Up](https://openexchangerates.org/signup/free).

## Install & Build

The application must be built from source. The source files are present in the repository for convenient viewing. 
In addition, a PAK archive containing all of the source files is available for transfer to your NonStop system.

| Repository File | NonStop File |
| -- | -- |
| macros/build.txt | build |
| macros/loadddl.txt | loadddl |
| macros/logcfg.txt | logcfg |
| resources/oxrapi.json | oxrapi |
| src/oxrates.c | oxratesc |
| resources/oxrddl.txt | oxrddl |
| oxrpak.bin | oxrpak |
| macros/setenv.txt | setenv |
| macros/startpw.txt | startpw |
| macros/startpw.txt | stoppw |
| macros/setenv.txt | unsetenv |

#### Upload the PAK archive

Download `oxrpak.bin` from this repository to your local system, then upload to your NonStop server using binary transfer mode. Logon to TACL on your NonStop server to peform the installation and build steps.

#### Unpak the PAK archive
```
TACL > UNPAK OXRPAK ($*.*.*), VOL $your-volume.your-subvolume.*, LISTALL, MYID
```

#### Build the application
```
TACL > RUN LOADDDL
TACL > RUN BUILD
```
## Running the application
Customize the SETENV macro for your environment and run it to set the required PARAMs. Note that you must supply your App Id in the SETENV macro.
```
TACL> T/EDIT SETENV
TACL> RUN SETENV
```
Start the LightWave Client Pathway
```
TACL > RUN STARTPW
```
Run the application
```
TACL > RUN OXRATES
```
Assistance is available through the [NuWave Technologies Support Center](http://support.nuwavetech.com).