/***
 * iRecovery++ C++ interface for libirecovery.
 * Copyright (C) 2010  GreySyntax
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "Device.h"

using namespace std;

namespace irecovery {
	
	Device::Device(irecv_client_t client) {

		_client = client;
		_mode = (uint32_t)client->mode;
	}
	
	Device::~Device() {
		
		if (_mode) {
			
			free((void*)_mode);
		}
		
		if (_client != NULL) {
			
			irecv_close(_client);
			free(_client);
		}
	}
	
	Device* Device::Open() {

		irecv_client_t client = NULL;
		irecv_init();
		
		for (int i = 0; i < DEVICE_CONNECTION_ATTEMPTS; i++) {
			
			if (irecv_open(&client) == IRECV_E_SUCCESS) {
				
				break;
			}
			
			sleep(1);
		}
		
		if (client == NULL) {
			
			return NULL;
		}
		
		return (Device*)(new Device(client));
	}
	
	void Device::Reset() {
		
		irecv_reset(_client);
	}
	
	
};
