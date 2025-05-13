## Burning DVDs within Linux.


#### > Using inxi to to find the optical drives on your system

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
on the Internet, I discovered that ```/dev/sr0`` is a Hewlett Packard 
optical drive, while ```/dev/sr1``` is an LG optical drive.