# LightWave Client Open Exchange Rates
This is a sample application that illustrates how to access foreign exchange rates provided by the [Open Exchange Rates REST API](https://openexchangerates.org). The sample application is a C program that retrieves current exchange rates for USD.

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

Download `oxrpak.bin` from this repository to your local system, then upload to your NonStop server using binary transfer mode.

Note: to download the PAK file, click `oxrpak.bin` in the file list to display the file details, then click the *Download* button.

Logon to TACL on your NonStop system to peform the installation and build steps.

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

LightWave Client(tm) - Open Exchange Rates API - Test Driver - 19JUL2019

Building request IPM ...
Sending 184 byte request to serverclass $NWOXR:OXRATES ...
Received 5366 byte reply ...

170 rates were returned for base currency: USD.

  AED   3.6731
  AFN   78.44691
  ALL   103.747116
  AMD   534.482804
  ANG   1.7949
  AOA   628.315
  ARS   92.387
  AUD   1.308159
  AWG   1.8
  AZN   1.700805
  BAM   1.64875
  BBD   2
  BDT   84.792165
  BGN   1.6425
  BHD   0.377051
  BIF   1947.783164
  BMD   1
  BND   1.341252
  BOB   6.904784
  BRL   5.5815
  BSD   1
  BTC   0.000017402585
  BTN   74.264193
  BWP   10.940527
  BYN   2.661328
  BZD   2.015595
  CAD   1.25943
  CDF   1981.736453
  CHF   0.925156
  CLF   0.025662
  CLP   708
  CNH   6.559088
  CNY   6.5492
  COP   3643.139735
  CRC   612.088166
  CUC   1
  CUP   25.75
  CVE   93.227322
  CZK   21.727655
  DJF   178.023146
  DKK   6.251294
  DOP   56.887674
  DZD   132.494978
  EGP   15.7105
  ERN   15.001203
  ETB   41.606237
  EUR   0.840534
  FJD   2.0666
  FKP   0.726925
  GBP   0.726925
  GEL   3.405597
  GGP   0.726925
  GHS   5.779811
  GIP   0.726925
  GMD   51.25
  GNF   10004.608189
  GTQ   7.71726
  GYD   209.500499
  HKD   7.776795
  HNL   24.04215
  HRK   6.3629
  HTG   80.76543
  HUF   301.187207
  IDR   14604.543234
  ILS   3.281827
  IMP   0.726925
  INR   74.566495
  IQD   1458.945426
  IRR   42105
  ISK   126.9
  JEP   0.726925
  JMD   146.706504
  JOD   0.709
  JPY   109.1065
  KES   108
  KGS   84.79345
  KHR   4044.718869
  KMF   418.800111
  KPW   900
  KRW   1117.031776
  KWD   0.301671
  KYD   0.833277
  KZT   434.032399
  LAK   9401.768979
  LBP   1511.907536
  LKR   200.732216
  LRD   172.999975
  LSL   14.535722
  LYD   4.521475
  MAD   8.991528
  MDL   17.865207
  MGA   3811.074035
  MKD   51.919982
  MMK   1409.916429
  MNT   2853.33601
  MOP   8.009913
  MRO   356.999828
  MRU   36.020232
  MUR   40.4
  MVR   15.460022
  MWK   784.073182
  MXN   20.116432
  MYR   4.1375
  MZN   65.115
  NAD   14.66
  NGN   381.05
  NIO   34.899051
  NOK   8.485537
  NPR   118.823902
  NZD   1.417812
  OMR   0.385016
  PAB   1
  PEN   3.608346
  PGK   3.55599
  PHP   48.550418
  PKR   152.790976
  PLN   3.818443
  PYG   6389.338311
  QAR   3.641552
  RON   4.1341
  RSD   99.140154
  RUB   76.8585
  RWF   988.188291
  SAR   3.750341
  SBD   7.987348
  SCR   18.341005
  SDG   380.5
  SEK   8.561025
  SGD   1.3399
  SHP   0.726925
  SLL   10212.499484
  SOS   578.462128
  SRD   14.154
  SSP   130.26
  STD   20721.552124
  STN   21.25
  SVC   8.74942
  SYP   1257.704474
  SZL   14.535975
  THB   31.45
  TJS   11.401644
  TMT   3.51
  TND   2.7841
  TOP   2.289479
  TRY   8.15299
  TTD   6.775047
  TWD   28.438499
  TZS   2319
  UAH   27.912581
  UGX   3646.886612
  USD   1
  UYU   44.048718
  UZS   10478.92809
  VES   90418.185
  VND   23011.928719
  VUV   109.694235
  WST   2.532033
  XAF   551.354474
  XAG   0.03918628
  XAU   0.00056983
  XCD   2.70255
  XDR   0.703547
  XOF   551.354474
  XPD   0.00037854
  XPF   100.302443
  XPT   0.00081449
  YER   250.350066
  ZAR   14.514435
  ZMW   22.134289
  ZWL   322

The request completed in 0.05952 seconds.

Navigate to this URL to compare the rates:
  https://openexchangerates.org/api/latest.json?app_id=<your-app-id>&base=USD 

```
Assistance is available through the [NuWave Technologies Support Center](http://support.nuwavetech.com).