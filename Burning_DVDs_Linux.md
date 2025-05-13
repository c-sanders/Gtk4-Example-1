## Burning DVDs within Linux.


#### > Using the ```inxi``` command line utility to find the optical drives on your system

One way to find if there are any optical drives on your Linux system, is to use the
```inxi``` command line utility.

For example;

```
> inxi -d
```

Running this command on my system yields the following information;

```
Drives:
  Local Storage: total: 1006.06 GiB used: 121.34 GiB (12.1%)
  ID-1: /dev/sda vendor: Seagate model: ST9500423AS size: 465.76 GiB
  ID-2: /dev/sdb vendor: Seagate model: ST980811AS size: 74.53 GiB
  ID-3: /dev/sdc vendor: Seagate model: ST9250421ASG size: 232.89 GiB
  ID-4: /dev/sdd vendor: Seagate model: ST3250318AS size: 232.89 GiB
  Optical-1: /dev/sr0 vendor: hp model: DVD-RAM GH80N dev-links: cdrom
  Features: speed: 94 multisession: yes audio: yes dvd: yes
    rw: cd-r,cd-rw,dvd-r,dvd-ram
  Optical-2: /dev/sr1 vendor: HL-DT-ST model: DVDRAM GH22NS50 dev-links: N/A
  Features: speed: 94 multisession: yes audio: yes dvd: yes
    rw: cd-r,cd-rw,dvd-r,dvd-ram

```

From this output, we can see that I have two optical drives available on my
system - ```/dev/sr0``` and ```/dev/sr1```. After undertaking some research
on the Internet, I discovered that ```/dev/sr0``` is a Hewlett Packard
brand optical drive, while ```/dev/sr1``` is an LG brand optical drive.

For more information on the Hewlett Packard GH80N optical drive, have a 
look [here](https://h10032.www1.hp.com/ctg/Manual/c02642918.pdf).

For more information on the LG GH22NS50 optical drive, have a look
[here](https://www.lg.com/au/support/product-support/cs-GH22NS50/).


#### > Using the ```wodim``` command line utility to find the optical drives on your system

Another way to find if there are any optical drives on your Linux system, is
to use the ```wodim``` command line utility.

For example;

```
> wodim -prcap
```

Running this command on my system yields the following information;

```
wodim: Operation not permitted. Warning: Cannot raise RLIMIT_MEMLOCK limits.
Device was not specified. Trying to find an appropriate drive...
Detected CD-R drive: /dev/sr1
Using /dev/cdrom of unknown capabilities
Device type    : Removable CD-ROM
Version        : 5
Response Format: 2
Capabilities   : 
Vendor_info    : 'hp      '
Identification : 'DVD-RAM GH80N   '
Revision       : 'RF03'
Device seems to be: Generic mmc2 DVD-R/DVD-RW.

Drive capabilities, per MMC-3 page 2A:

  Does read CD-R media
  Does write CD-R media
  Does read CD-RW media
  Does write CD-RW media
  Does read DVD-ROM media
  Does read DVD-R media
  Does write DVD-R media
  Does read DVD-RAM media
  Does write DVD-RAM media
  Does support test writing

  Does read Mode 2 Form 1 blocks
  Does read Mode 2 Form 2 blocks
  Does read digital audio blocks
  Does restart non-streamed digital audio reads accurately
  Does support Buffer-Underrun-Free recording
  Does read multi-session CDs
  Does read fixed-packet CD media using Method 2
  Does not read CD bar code
  Does not read R-W subcode information
  Does read raw P-W subcode data from lead in
  Does return CD media catalog number
  Does return CD ISRC information
  Does support C2 error pointers
  Does not deliver composite A/V data

  Does play audio CDs
  Number of volume control levels: 256
  Does support individual volume control setting for each channel
  Does support independent mute setting for each channel
  Does not support digital output on port 1
  Does not support digital output on port 2

  Loading mechanism type: tray
  Does support ejection of CD via START/STOP command
  Does not lock media on power up via prevent jumper
  Does allow media to be locked in the drive via PREVENT/ALLOW command
  Is currently in a media-locked state
  Does not support changing side of disk
  Does not have load-empty-slot-in-changer feature
  Does not support Individual Disk Present feature

  Maximum read  speed: 16620 kB/s (CD  94x, DVD 12x)
  Current read  speed: 16620 kB/s (CD  94x, DVD 12x)
  Maximum write speed: 11080 kB/s (CD  62x, DVD  8x)
  Current write speed: 11080 kB/s (CD  62x, DVD  8x)
  Rotational control selected: CLV/PCAV
  Buffer size in KB: 2048
  Copy management revision supported: 1
  Number of supported write speeds: 4
  Write speed # 0: 11080 kB/s CLV/PCAV (CD  62x, DVD  8x)
  Write speed # 1:  8310 kB/s CLV/PCAV (CD  47x, DVD  6x)
  Write speed # 2:  5540 kB/s CLV/PCAV (CD  31x, DVD  4x)
  Write speed # 3:  3324 kB/s CLV/PCAV (CD  18x, DVD  2x)

Supported CD-RW media types according to MMC-4 feature 0x37:
  Does write multi speed       CD-RW media
  Does write high  speed       CD-RW media
  Does write ultra high speed  CD-RW media
  Does write ultra high speed+ CD-RW media
```


#### > Using the ```wodim``` command line utility to burn an ISO image to a DVD.

The ```wodim``` command line utility can also be used to burn data to a 
DVD.

To burn an ISO image to a blank DVD, a command similar to the following
can be used;

```
wodim -v -tao speed=2 dev=/dev/sr1 -data ./Win11_24H2_EnglishInternational_x64.iso 

```

```-v``` : Operate in a verbose manner.

```-tao``` : Burn the data in 'Track At Once' mode.

```speed=2``` : 