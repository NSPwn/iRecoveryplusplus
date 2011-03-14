What is iRecovery++?
================================
iRecovery++ is a C++ interface for libirecovery.

License
================================
This program is released under the GPL v3 see the LICENCE file for more details.

Requirements
================================
* libusb-1.0
* libreadline 6.1 (With latest patches)
* libirecovery (provided via submodule)

Install
================================

	git submodule update --init
	make -C libirecovery
	make all


