
### RAID levels

#### RAID 0

RAID 0 splits data evenly across two or more disks, without parity information,
redundancy, or fault tolerance. 

This configuration is typically implemented having speed as the intended goal.

RAID 0 is normally used to increase performance, although it can also be used as
a way to create a large logical volume out of two or more physical disks.

Also known as a stripe set or striped volume

	-----	-----
	| A1 |	| A2 |
	| A3 |	| A4 |
	| A5 |	| A6 |
	| A7 |	| A8 |
	|    |	|    |
	|    |	|    |
	-----	-----
	Disk 0	Disk 1

#### RAID 1

Consists of an exact copy of a set of data on two or more disks; a classic RAID 1
mirrored pair contains two disks. This configuration offers no parity, striping,
or spanning of disk space across multiple disks

This layout is useful when read performance or reliability is more important than 
write performance or the resulting data storage capacity

	-----	----- 
	| A1 |	| A1 |
	| A2 |	| A2 |
	| A3 |	| A3 |
	| A4 |	| A4 |
	|    |	|    |
	|    |	|    |
	-----	----- 
	Disk 0	Disk 1

#### RAID 2

Stripes data at the bit level, and uses a Hamming code for error correction.
The disks are synchronized by the controller to spin at the same angular 
orientation (they reach index at the same time), so it generally cannot service
multiple request simultaneously. Extreme high data transfer rates are possible

	------	------	------	------	------	------	------	
	| A1 |	| A2 |	| A3 |	| A4 |	| Ap1 |	| Ap2 |	| Ap3 |	
	| B1 |	| B2 |	| B3 |	| B4 |	| Bp1 |	| Bp2 |	| Bp3 |	
	| C1 |	| C2 |	| C3 |	| C4 |	| Cp1 |	| Cp2 |	| Cp3 |	
	| D1 |	| D2 |	| D3 |	| D4 |	| Dp1 |	| Dp2 |	| Dp3 |	
	|    |	|    |	|    |	|    |	|     |	|     |	|     |	
	|    |	|    |	|    |	|    |	|     |	|     |	|     |	
	----- 	----- 	----- 	----- 	----- 	----- 	----- 	
	Disk 0	Disk 1	Disk 2	Disk 3	Disk 4	Disk 5	Disk 6	

#### RAID 3

Consists of byte level striping with a dedicated parity disk. One of the 
characteristics of RAID 3 is that it generally cannot service multiple requests
simultaneously, which happens because any single block of data will, by definition,
be spread across all members of the set and will reside in the same location.

Suitable for application the demand the highest transfer rates in long sequential
read and writes.
	------	------	------	----------
	| A1 |	| A2 |	| A3 |	| Ap(1-3) |
	| A4 |	| A5 |	| A6 |	| Ap(4-6) |
	| B1 |	| B2 |	| B3 |	| Bp(1-3) |
	| B4 |	| B5 |	| B6 |	| Bp(4-6) |
	|    |	|    |	|    |	|         |
	|    |	|    |	|    |	|         |
	----- 	----- 	----- 	-----------
	Disk 0	Disk 1	Disk 2	   Disk 3

#### RAID 4

Consists of block level striping with a dedicated parity disk.

Provides good performance of random read, while the performance of random writes
is low due to the need to write all parity data to a single disk.

	------	------	------	------
	| A1 |	| A2 |	| A3 |	| Ap |
	| B1 |	| B2 |	| B3 |	| Bp |
	| C1 |	| C2 |	| C3 |	| Cp |
	| D1 |	| D2 |	| D3 |	| Dp |
	|    |	|    |	|    |	|    |
	|    |	|    |	|    |	|    |
	----- 	----- 	----- 	----- 
	Disk 0	Disk 1	Disk 2	Disk 3

#### RAID 5

Consist of block level striping with distributed parity. Parity information is
distributed among the drives. It requires that all drives but one be present to
operate. Upon failure of a single drive, subsequent read can be calculated from 
the distributed parity such that no data list.

Requires at least three disks

In comparison to RAID 4, RAID 5's distributed parity evens out the stress of a 
dedicated parity disk among all RAID members. Additionally, write performance
is increased since all RAID members participate in the serving of write request.
Although it won't be as efficient as a striping (RAID 0) setup, because parity 
must still be written.

	------	------	------	------
	| A1 |	| A2 |	| A3 |	| Ap |
	| B1 |	| B2 |	| Bp |	| B3 |
	| C1 |	| Cp |	| C2 |	| C3 |
	| Dp |	| D1 |	| D2 |	| D3 |
	|    |	|    |	|    |	|    |
	|    |	|    |	|    |	|    |
	----- 	----- 	----- 	----- 
	Disk 0	Disk 1	Disk 2	Disk 3

#### RAID 6

Extends RAID 5 by adding another parity block; Thus, it uses block level striping
with two parity blocks distributed across all members disks.

	------	------	------	------	------
	| A1 |	| A2 |	| A3 |	| Ap |	| Aq |
	| B1 |	| B2 |	| Bp |	| Bq |	| B3 |
	| C1 |	| Cp |	| Cq |	| C2 |	| C3 |
	| Dp |	| Dq |	| D1 |	| D2 |	| D3 |
	| Ep |	| E1 |	| E2 |	| E3 |	| Eq |
	|    |	|    |	|    |	|    |	|    |
	|    |	|    |	|    |	|    |	|    |
	----- 	----- 	----- 	----- 	----- 
	Disk 0	Disk 1	Disk 2	Disk 3	Disk 4


Reference
--------

(Standard RAID levels)[https://en.wikipedia.org/wiki/Standard_RAID_levels#RAID_6]
