# Install FreeBSD on Parallel Desktop

* Download [Installer aarch64](https://download.freebsd.org/releases/arm64/aarch64/ISO-IMAGES/14.2/FreeBSD-14.2-RELEASE-arm64-aarch64-disc1.iso)
* Create Empty with :
  * Other OS
  * CPU 4 core
  * 4 GB of RAM
  * 64 or 128 GB for HDD
* Launch install
* Create user and don't forget to add in `wheel` group
* Connect as root
  * update and upgrade the packets manager : `pkg install && pkg upgrade`
  * install sudo : `pkg install -y sudo`
  * run `visudo` and add the new created user as root `username All=(ALL:ALL) ALL`
  * install xorg
  * install `kde6`or higher : `pkg install kde6` see ([Desktop Environments](https://docs.freebsd.org/en/books/handbook/desktop/) for more information)
  * Add following lines in `/etc/rc.conf` :
    ```
    sysrc dbus_enable="YES"
    sysrc sddm_enable="YES"
    ```
  * Create ~/.xinitrc in the user session with command : `echo "exec dbus-launch --exit-with-x11 ck-launch-session startplasma-x11" > ./.xinitrc`
    
  * Add following lines in `/boot/loader.conf` (see [Add FreeBSD 13.1 support for Parallels 17](https://forum.parallels.com/threads/add-freebsd-13-1-support-for-parallels-17.357475/#post-904146) and [Screen resolution FreeBSD 12.0 Parallels VM](https://forums.freebsd.org/threads/screen-resolution-freebsd-12-0-parallels-vm.70726/) for more information) :
    ```
    ums_load="YES"
    exec="mode 10"
    ```
    