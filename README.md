bAnti - Kernel Based Root ToolKit
----
Banti is kernel based root toolkit samples for Linux. It contains keylogger and rootkit modules for Linux kernel. With this modules you are able to log keyboard info, hide processes and get root privileges for each process. It is developed for educational purposes only and authors of this project are in no way, shape or form responsible for what you may use this for whether illegal or not.

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
If those modules is no longer required for you, you can just unload from modules
```
rmmod keylog
rmmod bantikit
```

#### Usage
We are currently at development process, usage information will be available soon.
You can see development process below.

#### Development Process
- [x] Remote listener [See Here](https://github.com/nikopeikrishvili/proto-banti)
- [x] Client commander [See Here](https://github.com/nikopeikrishvili/proto-banti)
- [x] Kernel based keylogger module
- [x] Main rootkit module 'bantikit'
- [ ] Backdor module
- [ ] Many fucking things

<img align="center" src="http://off-sec.com/ftp/bow.png"></img>
