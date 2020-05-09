rm -rf ~/temp/; mkdir -p ~/temp/loop
cp ./rootfs.ext2.gz ~/temp; cd ~/temp
gunzip rootfs.ext2.gz
mount -o loop rootfs.ext2 loop/
cd loop && ls
cd ..; umount loop/
gzip rootfs.ext2
mkimage -n 'uboot ext2 ramdisk rootfs' -A ppc -O linux -T ramdisk -C gzip -d rootfs.ext2.gz rootfs.ext2.gz.uboot
cp rootfs.ext2.gz ${DanOS_DIR}/3rdParty/rootfs/; cp rootfs.ext2.gz.uboot ${DanOS_DIR}/3rdParty/rootfs/
cd ${DanOS_DIR}/3rdParty/rootfs/
cp rootfs.ext2.gz.uboot ../../../../nfsroot/


LTIB�����ļ�ϵͳ(ramdisk, jffs, jffs2, cramfs)������ӹ��ܺ���mk_fs_imageλ�ڰ�װĿ¼��bin/Ltibutils.pm, ���ļ���perl��ģ��⣬�����˺ܶຯ�����ɰ�װĿ¼�µ�perlִ�нű�ltib���е��á�
���� 
��������LTIB�Զ����ɵ��ļ�ϵͳλ�ڰ�װĿ¼�µ�rootfsĿ¼(�����ļ��࣬�Ƚϴ�)
������rootfsĿ¼�Ļ������ֽ��вü�(��ȥ�������ں˾����/bootĿ¼, /usr/lib/*.a, /usr/include/*��)�������ɱȽ��ʺ����ص��������ϵĸ��ļ�ϵͳrootfs.tmp(��Ŀ¼Ĭ������±��������z�Զ�ɾ��)��
���� �޸�Ltibutils.pm�ű�(ע��818 rm -rf $stage)������ʹ��./ltib --preconfig config/platform/mpc8349itx/defconfig-min-fs ���뵯����һ�����ò˵�ʱ����
���� --- Target Image Generation 
���� Options ---> ����ѡ��
���� [*] Keep temporary staging directory 
���� ������������ᱣ����ʱ���ļ�ϵͳrootfs.tmp
������rootfs.tmp�Ļ���������豸�ļ�������ѹ��(genext2fs, gzip)���ļ�Ϊrootfs.ext2.gz(RAMDISK�ļ�ϵͳ, ext2��ʽ�ɶ�д)
��������uboot�������ļ�ϵͳ������rootfs.ext2.gz.uboot
���� 
���� 
���� 
��������������Ҫ���ļ�ϵͳ�����ַ�ʽ:
����
����
���� 
����A: ֻ����������ļ����ļ�ϵͳ��
����rootfs.ext2.gz ��Ltibutils.pm�ű������ȵõ����ļ�ϵͳ�Ĵ�С(du -slk),Ȼ�������һ����С(���: $fs_size += $fs_size >= 20000 ? 16384 : 2400;), Ȼ���ô˴�С�����������Ĵ�С�����Կ�����rootfs.ext2.gz����������ļ�.(ֻҪ�������������Ĵ�С����)
��������rootfs.ext2.gz�޸�����ļ����ļ�ϵͳ���񷽷�:
����$ mkdir -p ~/temp/loop
����$ cp /usr/local/mpc8349/small/rootfs.ext2.gz ~/temp
����$ cd ~/temp
����$ gunzip rootfs.ext2.gz
����$ su root
����# mount -o loop rootfs.ext2 loop/
����# cd loop && ls
����# df ./ ## �鿴ʣ��ռ��С���ռ�ʹ����
����# ����Լ���Ӧ�ó����ű��ȵ�Ŀ¼�У����޸������ű�etc/rc.d/rcS(ע��Ȩ��)
����# cd /home/liuby/temp/
����# umount loop/
����# exit
����$ gzip rootfs.ext2 ����gzip -v9 rootfs.ext2
����$ mkimage -n 'uboot ext2 ramdisk rootfs' -A ppc -O linux -T ramdisk -C gzip -d rootfs.ext2.gz rootfs.ext2.gz.uboot
���� ## �ھ���ǰ���64�ֽڵ�ͷ��Ϊuboot�ṩ��Ҫ����Ϣ��
���� ## ע: mkimage λ�� /opt/freescale/ltib/usr/bin/mkimage, ���Խ��临�Ƶ�/usr/bin/Ŀ¼��
���� ## /opt/freescale/ltib/usr/bin/������ೣ�ù���
���� ## mkimage�÷��ο�http://blog.chinaunix.net/u2/80953/showart.php?id=1890789 
����$ ls rootfs.ext2.gz.uboot ## ��������ʹ��
���� 
Image Name:   uboot ext2 ramdisk rootfs
Created:      Tue Oct 25 17:49:02 2016
Image Type:   PowerPC Linux RAMDisk Image (gzip compressed)
Data Size:    4336282 Bytes = 4234.65 kB = 4.14 MB
Load Address: 0x00000000
Entry Point:  0x00000000

mkimage -n 'uboot ext2 ramdisk rootfs' -A ppc -O linux -T ramdisk -C gzip -d ./rootfs.ext2.gz ./rootfs.ext2.gz.uboot

�����м���Ҫע�⣺

1������ƫ���������⣨��ǧ��ע����һ�㣩����-e������֮��ĵ�ַ������ȡ�-a�������ĵ�ַ��0x40��ƫ������һ��û��ƫ�ƣ���ᵼ��ϵͳ��������ʧ�ܵ����⡣���ܶ಩���������Ȼ����2��ֵд��һ���ģ���д��0x30008000��Ҳ��֪����λ�������Լ�������û�г��Թ�������һ��ʼ�����˰���ŷ���������⣬��ֱ�����˷��ҵ�ʱ�䡣

2��ִ�и�����ʱ��Ҫע��һ��Ȩ�޵����⡣��һ��ʼʱ��������Ĺ���Ŀ¼��ִ�У�һֱ��ʾʧ�ܣ�

leon@Ubuntu:/mnt/share/tmp/zImages$ mkimage -n 'tekkaman' -A arm -O linux -T kernel -C none -a 0x30008000 -e 0x30008040 -d zImage zImage.imgmkimage: Can't map zImage.img: Invalid argument
������ת��~Ŀ¼��ִ�У���һ���ӳɹ��ˡ��ɹ������ʾ��Ϣ���£�

leon@Ubuntu:~$ mkimage -n 'tekkaman' -A arm -O linux -T kernel -C none -a 0x30008000 -e 0x30008040 -d zImage zImage.imgImage Name:   leon_20170201Created:      Wed Feb  1 14:50:47 2017Image Type:   ARM Linux Kernel Image (uncompressed)Data Size:    2266576 Bytes = 2213.45 kB = 2.16 MBLoad Address: 30008000Entry Point:  30008040
����
����
����B: ���ɶ��Ƹ�������С
����ͬ������rootfs.ext2.gz
����$ mkdir -p ~/temp/loop
����$ cp /usr/local/mpc8349/small/rootfs.ext2.gz ~/temp
����$ cd ~/temp
����$ gunzip rootfs.ext2.gz
����$ su root
����# mount -o loop rootfs.ext2 loop/
����# cd loop && ls
����# df ./ 
����# ����Լ���Ӧ�ó����ű��ȵ�Ŀ¼�У����޸������ű�etc/rc.d/rcS(ע��Ȩ��)
����# fs_size=`LANG=C du -slk loop/ | cut -f1` ## ͳ��loopĿ¼��С
����# fs_count=`find loop/ | wc -l` ## ͳ��loop/Ŀ¼�е��ļ��ڵ���Ŀ, ����ͬperl ��find( sub { $fs_count++}, loop/ );
����# echo $fs_count && echo $fs_size
����# inodes=`expr $fs_count + 400` ## inodesΪ�����ڵ��������洴����ext2�ļ�ϵͳ�������$inodes���ڵ�
����# blocks=`expr $fs_size + 2400` ## Ϊ����������һЩ���пռ�(2400kB��Ҳ���Ը���Щ)
����# echo $inodes && echo $blocks
����# genext2fs -U -b $blocks -i $inodes -d loop/ loop.ext2
���� ## ����loopĿ¼����ext2�ļ�ϵͳ���񣬷�����СΪ$blocks kByte. inode��ĿΪ$inodes
���� ## ע: genext2fs λ�� /opt/freescale/ltib/usr/bin/genext2fs, ���Խ��临�Ƶ�/usr/bin/Ŀ¼��
���� ## genext2fs�÷�����¼
����# gzip -v9 loop.ext2
����# mkimage -n 'uboot ext2 ramdisk rootfs' -A ppc -O linux -T ramdisk -C gzip -d loop.ext2.gz loop.ext2.gz.uboot
����# exit && ls loop.ext2.gz.uboot ## ���ļ�ϵͳloop.ext2.gz.uboot
���� 
���� 
���� 
����
����
����
����
����
����C: ���ɶ��Ƹ��ļ�ϵͳ
�������ñ���ʱ����ʱ�ļ�ϵͳĿ¼rootfs.tmp
����rootfs.tmp��ʵ�����൱�ڴ�������Ŀ¼�����һЩ�����Busybox�����������Լ���һ��
����$ cd /usr/local/mpc8349/small/ ## ltib�İ�װĿ¼, ���ñ�������rootfs.tmpĿ¼
����$ rm -f rootfs.ext2.gz rootfs.ext2.gz.uboot
����$ cd rootfs.tmp/ && ls
����$ ����Լ���Ӧ�ó������ļ���ű�����Ӧ��Ŀ¼�У����޸������ű�etc/rc.d/rcS(ע��Ȩ��)
����$ cd /usr/local/mpc8349/small/rootfs.tmp/
����$ fs_size=`LANG=C du -slk rootfs.tmp/ | cut -f1`
����$ fs_count=`find rootfs.tmp/ | wc -l`
����$ echo $fs_count && echo $fs_size
����$ inodes=`expr $fs_count + 400` 
����$ blocks=`expr $fs_size + 2400`
����$ echo $inodes && echo $blocks
����$ genext2fs -v -U -b $blocks -i $inodes -D bin/device_table.txt -d rootfs.tmp/ rootfs.ext2
���� ## -D bin/device_table.txt�Ǹ���bin/device_table.txt������/dev���豸�ڵ��
���� ## -v ��ʾ�ļ�ϵͳ�ṹ(�ɲ���)
����$ gzip -v9 rootfs.ext2
����$ mkimage -n 'uboot ext2 ramdisk rootfs' -A ppc -O linux -T ramdisk -C gzip -d rootfs.ext2.gz rootfs.ext2.gz.uboot
����
����
����
����ע: ���ext2�ļ�ϵͳ��С(blocks kB)����Ĭ�ϵ�4096kB, ����Ҫ��uboot�Ļ���������������������в�����ָ��ramdisk_size��С����Ϊ${blocks}kB. ����:
����=> setenv bootargs root=/dev/ram rw ramdisk_size=$blocks
����
����
����
������¼: genext2fs �÷�: genext2fs [options] image
��������Ŀ¼���ļ�ΪǶ��ʽϵͳ��������һ��ext2�ļ�ϵͳ����(Create an ext2 filesystem image from directories/files);
��������Ƕ��ʽ������ramdisk�ļ�ϵͳ����Ҫ����(ext2��ʽ, ��д�ɶ�)
���� -x image Use this image as a starting point
���� -d directory Add this directory as source
���� -b blocks Size in blocks(ָ����С: 1 block = 1kB)
���� -i inodes Number of inodes
���� -r reserved Number of reserved blocks
���� -g path Generate a block map file for this path
���� -e value Fill unallocated blocks with value
���� -z Make files with holes
���� -D,-f Use the named FILE as a device table file
���� -q Squash permissions and owners making all files be owned by root
���� -U Squash owners making all files be owned by root
���� -P Squash permissions on all files
���� -v Print resulting filesystem structure
���� -h Show this help
����
����
����
����
����genext2fs���õ��ļ�device_table.txt�ο���http://buildroot.uclibc.org/��վ��/trunk/buildroot/target/generic/device_table.txt
�����������õ�device_table.txt
����#
����# When building a target filesystem, it is desirable to not have to
����# become root and then run 'mknod' a thousand times. Using a device 
����# table you can create device nodes and directories "on the fly".
����#
����# This is a sample device table file for use with genext2fs. You can
����# do all sorts of interesting things with a device table file. For
����# example, if you want to adjust the permissions on a particular file
����# you can just add an entry like:
����# /sbin/foobar f 2755 0 0 - - - - -
����# and (assuming the file /sbin/foobar exists) it will be made setuid
����# root (regardless of what its permissions are on the host filesystem.
����# Furthermore, you can use a single table entry to create a many device
����# minors. For example, if I wanted to create /dev/hda and /dev/hda[0-15]
����# I could just use the following two table entries:
����# /dev/hda b 640 0 0 3 0 0 0 -
����# /dev/hda b 640 0 0 3 1 1 1 15
����# 
����# Device table entries take the form of:
����# 
����# where name is the file name, type can be one of: 
����# f A regular file
����# d Directory
����# c Character special device file
����# b Block special device file
����# p Fifo (named pipe)
����# uid is the user id for the target file, gid is the group id for the
����# target file. The rest of the entries (major, minor, etc) apply only 
����# to device special files.
����# Have fun
����# -Erik Andersen 
����#
����# 
����/dev d 755 0 0 - - - - -
����/dev/pts d 755 0 0 - - - - -
����/dev/shm d 755 0 0 - - - - -
����/dev/input d 755 0 0 - - - - -
����#/tmp d 1777 0 0 - - - - -
����#/etc d 755 0 0 - - - - -
����#/home/default d 2755 1000 1000 - - - - -
����# 
����#/bin/busybox f 4755 0 0 - - - - -
����#/etc/shadow f 600 0 0 - - - - -
����#/etc/passwd f 644 0 0 - - - - -
����#/etc/network/if-up.d d 755 0 0 - - - - -
����#/etc/network/if-pre-up.d d 755 0 0 - - - - -
����#/etc/network/if-down.d d 755 0 0 - - - - -
����#/etc/network/if-post-down.d d 755 0 0 - - - - -
����#/usr/share/udhcpc/default.script f 755 0 0 - - - - -
����# uncomment this to allow starting x as non-root
����#/usr/X11R6/bin/Xfbdev f 4755 0 0 - - - - -
����# Normal system devices
����/dev/mem c 640 0 0 1 1 0 0 -
����/dev/kmem c 640 0 0 1 2 0 0 -
����/dev/null c 666 0 0 1 3 0 0 -
����/dev/zero c 666 0 0 1 5 0 0 -
����/dev/random c 666 0 0 1 8 0 0 -
����/dev/urandom c 666 0 0 1 9 0 0 -
����/dev/ram b 640 0 0 1 1 0 0 -
����/dev/ram b 640 0 0 1 0 0 1 4
����/dev/loop b 640 0 0 7 0 0 1 2
����/dev/rtc c 640 0 0 10 135 - - -
����/dev/console c 666 0 0 5 1 - - -
����/dev/tty c 666 0 0 5 0 - - -
����/dev/tty c 666 0 0 4 0 0 1 8
����/dev/ttyp c 666 0 0 3 0 0 1 10
����/dev/ptyp c 666 0 0 2 0 0 1 10
����/dev/ptmx c 666 0 0 5 2 - - -
����/dev/ttyP c 666 0 0 57 0 0 1 4
����/dev/ttyS c 666 0 0 4 64 0 1 4
����/dev/fb c 640 0 5 29 0 0 32 4
����#/dev/ttySA c 666 0 0 204 5 0 1 3
����/dev/psaux c 666 0 0 10 1 0 0 -
����/dev/ppp c 666 0 0 108 0 - - -
����/dev/ttyAM c 666 0 0 204 16 0 1 4
����/dev/ttyCPM c 666 0 0 204 46 0 1 2
����# MTD stuff
����/dev/mtd c 640 0 0 90 0 0 2 7
����/dev/mtdblock b 640 0 0 31 0 0 1 7
����#Tun/tap driver
����/dev/net d 755 0 0 - - - - -
����/dev/net/tun c 660 0 0 10 200 - - -
����# Audio stuff
����/dev/audio c 666 0 29 14 4 - - -
����/dev/audio1 c 666 0 29 14 20 - - -
����/dev/dsp c 666 0 29 14 3 - - -
����/dev/dsp1 c 666 0 29 14 19 - - -
����/dev/sndstat c 666 0 29 14 6 - - -
����# User-mode Linux stuff
����/dev/ubda b 640 0 0 98 0 0 0 -
����/dev/ubda b 640 0 0 98 1 1 1 8
����# IDE Devices
����/dev/hda b 640 0 0 3 0 0 0 -
����/dev/hda b 640 0 0 3 1 1 1 8
����/dev/hdb b 640 0 0 3 64 0 0 -
����/dev/hdb b 640 0 0 3 65 1 1 8
����#/dev/hdc b 640 0 0 22 0 0 0 -
����#/dev/hdc b 640 0 0 22 1 1 1 8
����#/dev/hdd b 640 0 0 22 64 0 0 -
����#/dev/hdd b 640 0 0 22 65 1 1 8
����# SCSI Devices
����/dev/sda b 640 0 0 8 0 0 0 -
����/dev/sda b 640 0 0 8 1 1 1 8
����/dev/sdb b 640 0 0 8 16 0 0 -
����/dev/sdb b 640 0 0 8 17 1 1 8
����/dev/sdc b 640 0 0 8 32 0 0 -
����/dev/sdc b 640 0 0 8 33 1 1 8
����/dev/sdd b 640 0 0 8 48 0 0 -
����/dev/sdd b 640 0 0 8 49 1 1 8
����#/dev/sde b 640 0 0 8 64 0 0 -
����#/dev/sde b 640 0 0 8 65 1 1 8
����#/dev/sdf b 640 0 0 8 80 0 0 -
����# MD devices
����/dev/md b 640 0 0 9 0 0 1 4
����# SPI devices
����/dev/qspi c 666 0 0 126 0 - - -
����# Watchdog timer port
����/dev/watchdog c 644 0 0 10 130 - - -
����# Input
����/dev/input/mice c 644 0 0 13 63 - - -
����/dev/input/event c 644 0 0 13 64 0 1 3