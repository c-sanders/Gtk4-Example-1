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


#### > ```wodim``` command line options.

Invoking ```wodim``` from the command line as follows;

```
> wodim --help
```

results in the following output;

```
Usage: wodim [options] track1...trackn
Options:
	-version	print version information and exit
	dev=target	SCSI target to use as CD/DVD-Recorder
	gracetime=#	set the grace time before starting to write to #.
	timeout=#	set the default SCSI command timeout to #.
	debug=#,-d	Set to # or increment misc debug level
	kdebug=#,kd=#	do Kernel debugging
	-verbose,-v	increment general verbose level by one
	-Verbose,-V	increment SCSI command transport verbose level by one
	-silent,-s	do not print status of failed SCSI commands
	driver=name	user supplied driver name, use with extreme care
	driveropts=opt	a comma separated list of driver specific options
	-setdropts	set driver specific options and exit
	-checkdrive	check if a driver for the drive is present
	-prcap		print drive capabilities for MMC compliant drives
	-inq		do an inquiry for the drive and exit
	-scanbus	scan the SCSI and IDE buses and exit
	-reset		reset the SCSI bus with the cdrecorder (if possible)
	-abort		send an abort sequence to the drive (may help if hung)
	-overburn	allow to write more than the official size of a medium
	-ignsize	ignore the known size of a medium (may cause problems)
	-useinfo	use *.inf files to overwrite audio options.
	speed=#		set speed of drive
	blank=type	blank a CD-RW disc (see blank=help)
	-format		format a CD-RW/DVD-RW/DVD+RW disc
	formattype=#	select the format method for DVD+RW disc
	fs=#		Set fifo size to # (0 to disable, default is 4 MB)
	ts=#		set maximum transfer size for a single SCSI command
	-load		load the disk and exit (works only with tray loader)
	-lock		load and lock the disk and exit (works only with tray loader)
	-eject		eject the disk after doing the work
	-dummy		do everything with laser turned off
	-msinfo		retrieve multi-session info for genisoimage
	-msifile=path	run -msinfo and copy output to file
	-toc		retrieve and print TOC/PMA data
	-atip		retrieve and print ATIP data
	-multi		generate a TOC that allows multi session
			In this case default track type is CD-ROM XA mode 2 form 1 - 2048 bytes
	-fix		fixate a corrupt or unfixated disk (generate a TOC)
	-nofix		do not fixate disk after writing tracks
	-waiti		wait until input is available before opening SCSI
	-immed		Try to use the SCSI IMMED flag with certain long lasting commands
	-force		force to continue on some errors to allow blanking bad disks
	-tao		Write disk in TAO mode.
	-dao		Write disk in SAO mode.
	-sao		Write disk in SAO mode.
	-raw		Write disk in RAW mode.
	-raw96r		Write disk in RAW/RAW96R mode.
	-raw96p		Write disk in RAW/RAW96P mode.
	-raw16		Write disk in RAW/RAW16 mode.
	-clone		Write disk in clone write mode.
	tsize=#		Length of valid data in next track
	padsize=#	Amount of padding for next track
	pregap=#	Amount of pre-gap sectors before next track
	defpregap=#	Amount of pre-gap sectors for all but track #1
	mcn=text	Set the media catalog number for this CD to 'text'
	isrc=text	Set the ISRC number for the next track to 'text'
	index=list	Set the index list for the next track to 'list'
	-text		Write CD-Text from information from *.inf or *.cue files
	textfile=name	Set the file with CD-Text data to 'name'
	cuefile=name	Set the file with CDRWIN CUE data to 'name'
	-audio		Subsequent tracks are CD-DA audio tracks
	-data		Subsequent tracks are CD-ROM data mode 1 - 2048 bytes (default)
	-mode2		Subsequent tracks are CD-ROM data mode 2 - 2336 bytes
	-xa		Subsequent tracks are CD-ROM XA mode 2 form 1 - 2048 bytes
	-xa1		Subsequent tracks are CD-ROM XA mode 2 form 1 - 2056 bytes
	-xa2		Subsequent tracks are CD-ROM XA mode 2 form 2 - 2324 bytes
	-xamix		Subsequent tracks are CD-ROM XA mode 2 form 1/2 - 2332 bytes
	-cdi		Subsequent tracks are CDI tracks
	-isosize	Use iso9660 file system size for next data track
	-preemp		Audio tracks are mastered with 50/15 microseconds preemphasis
	-nopreemp	Audio tracks are mastered with no preemphasis (default)
	-copy		Audio tracks have unlimited copy permission
	-nocopy		Audio tracks may only be copied once for personal use (default)
	-scms		Audio tracks will not have any copy permission at all
	-pad		Pad data tracks with 15 zeroed sectors
			Pad audio tracks to a multiple of 2352 bytes
	-nopad		Do not pad data tracks (default)
	-shorttrack	Subsequent tracks may be non Red Book < 4 seconds if in SAO or RAW mode
	-noshorttrack	Subsequent tracks must be >= 4 seconds
	-swab		Audio data source is byte-swapped (little-endian/Intel)
The type of the first track is used for the toc type.
Currently only form 1 tracks are supported.
```

#### > Using the ```wodim``` command line utility to burn an ISO image to a DVD.

The ```wodim``` command line utility can also be used to burn data to a 
DVD.

To burn an ISO image to a blank DVD, a command similar to the following
can be used;

To check or test if an ISO image will be able to be written to a DVD
correctly, try a command similar to the following.

```
wodim -v -dummy -tao speed=2 dev=/dev/sr1 -data ./Win11_24H2_EnglishInternational_x64.iso 

```

Note the use of the ```-dummy``` switch.

This command results in output which looks as follows;

```
TOC Type: 1 = CD-ROM
wodim: Operation not permitted. Warning: Cannot raise RLIMIT_MEMLOCK limits.
scsidev: '/dev/sr1'
devname: '/dev/sr1'
scsibus: -2 target: -2 lun: -2
Linux sg driver version: 3.5.27
Wodim version: 1.1.11
SCSI buffer size: 64512
Device type    : Removable CD-ROM
Version        : 5
Response Format: 2
Capabilities   : 
Vendor_info    : 'HL-DT-ST'
Identification : 'DVDRAM GH22NS50 '
Revision       : 'TN02'
Device seems to be: Generic mmc2 DVD-R/DVD-RW.
Current: 0x002B (DVD+R/DL)
Profile: 0x0012 (DVD-RAM) 
Profile: 0x0011 (DVD-R sequential recording) 
Profile: 0x0015 (DVD-R/DL sequential recording) 
Profile: 0x0016 (DVD-R/DL layer jump recording) 
Profile: 0x0014 (DVD-RW sequential recording) 
Profile: 0x0013 (DVD-RW restricted overwrite) 
Profile: 0x001A (DVD+RW) 
Profile: 0x001B (DVD+R) 
Profile: 0x002B (DVD+R/DL) (current)
Profile: 0x0010 (DVD-ROM) 
Profile: 0x0009 (CD-R) 
Profile: 0x000A (CD-RW) 
Profile: 0x0008 (CD-ROM) 
Profile: 0x0002 (Removable disk) 
Using generic SCSI-3/mmc DVD-R(W) driver (mmc_mdvd).
Driver flags   : SWABAUDIO BURNFREE 
Supported modes: PACKET SAO
Drive buf size : 1048576 = 1024 KB
Beginning DMA speed test. Set CDR_NODMATEST environment variable if device
communication breaks or freezes immediately after that.
Drive DMA Speed: 16007 kB/s 90x CD 11x DVD
FIFO size      : 12582912 = 12288 KB
Track 01: data  5856 MB        
Total size:     6725 MB (666:20.30) = 2998523 sectors
Lout start:     6726 MB (666:22/23) = 2998523 sectors
Current Secsize: 2048
HINT: use dvd+rw-mediainfo from dvd+rw-tools for information extraction.
Blocks total: 4173824 Blocks current: 4173824 Blocks remaining: 1175301
Speed set to 3324 KB/s
Starting to write CD/DVD at speed   2.0 in dummy unknown mode for single session.
Last chance to quit, starting dummy write in    0 seconds. Operation starts.
Waiting for reader process to fill input buffer ... input buffer ready.
Starting new track at sector: 0
Track 01: 5856 of 5856 MB written (fifo 100%) [buf  97%]   2.4x.
Track 01: Total bytes read/written: 6140975104/6140975104 (2998523 sectors).
Writing  time: 1897.413s
Average write speed   2.4x.
Min drive buffer fill was 97%
Fixating...
WARNING: Some drives don't like fixation in dummy mode.
Fixating time:  804.469s
wodim: fifo had 96727 puts and 96727 gets.
wodim: fifo was 0 times empty and 90885 times full, min fill was 92%.
```

Note the second line of output, that is;

```
wodim: Operation not permitted. Warning: Cannot raise RLIMIT_MEMLOCK limits.
```

If you get this message when you try and burn an image, and you want to
avoid it, then either run the command as the root user, or better yet,
run the command as ```sudo```.