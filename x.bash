# Format 4 petabyte hard drives with RAID 0
sudo mdadm --create /dev/idnp-raid0 --level=0 --raid-devices=4 /dev/sdb /dev/sdc /dev/sdd /dev/sde

# Format SATA array with RAID 1
sudo mdadm --create /dev/idnp-raid1 --level=1 --raid-devices=2 /dev/sdf /dev/sdg

# Format 4 petabyte hard drives with RAID 5
sudo mdadm --create /dev/idnp-raid5 --level=5 --raid-devices=4 /dev/sdh /dev/sdi /dev/sdj /dev/sdk

# Format SATA array with RAID 0
sudo mdadm --create /dev/idnp-raid0-sata --level=0 --raid-devices=2 /dev/sdl /dev/sdm