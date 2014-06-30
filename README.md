# Linux kernel module programming

* hello contains a Hello World! module
* char contains a basic char device driver module
* tagfs contains a simple file system implemetation

###To check tagfs:<br/>
Create a file to mount:<br/>
**`dd bs=1M count=100 if=/dev/zero of=image`**<br/>
Creating a directory to mount the above file:<br/>
**`mkdir mount`**<br/>
To compile:<br/>
**`make`**<br/>
To insert this module: <br/>
**`sudo insmod tagfs.ko `**<br/>
To mount that file on the mount directory:<br/>
**`mount -o loop -t tagfs image /path/to/that/mount/dir `**<br/>
To unmount: <br/>
**`unmount  /path/to/that/mount/dir `**<br/>
To remove this module: <br/>
**`sudo rmmod tagfs `**<br/>

To see output of printk(kernel ring buffer):
**`dmesg `**<br/>


References:<br/>
* [simplefs by psankar](https://github.com/psankar/simplefs)<br/>
* Linux source code
