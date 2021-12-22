# demo_avr_timer
A project based on cyancore software framework 

To run this example, follow the below commands
```
$ git clone https://github.com/VisorFolks/cyancore.git               # Clone cyancore repo
$ vi mk/tc_get.mk       # Updated toolchain
$ cd src/projects
$ git clone https://github.com/akashkollipara/demo_avr_timer.git   # Clone this repo
$ cd ../../
$ make get_avr_tc       # Use correct command for fetching toolchain, this is just for illustration purpose
$ make demo_avr_timer   # build will be located at out/demo_avr_timer
```

Flash the binary on target using respective programmer.
