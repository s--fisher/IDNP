# Format 1 petabyte hard drives with RAID 0
sudo mdadm --create /dev/idnp-raid0 --level=0 --raid-devices=4 /dev/sf /dev/sg /dev/sh /dev/si

# Format SATA array with RAID 1
sudo mdadm --create /dev/idnp-raid1 --level=1 --raid-devices=2 /dev/sj /dev/sk

# Format 1 petabyte hard drives with RAID 5
sudo mdadm --create /dev/idnp-raid5 --level=5 --raid-devices=4 /dev/sl /dev/sm /dev/sn /dev/so

# Format SATA array with RAID 0
sudo mdadm --create /dev/idnp-raid0-sata --level=0 --raid-devices=2 /dev/sp /dev/lib
