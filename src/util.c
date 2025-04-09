/*
 * This file is part of DSR Gadget Loader.

 * DSR Gadget Loader is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your option)
 * any later version.

 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.

 * You should have received a copy of the GNU General Public License along with
 * this program. If not, see <https://www.gnu.org/licenses/>.
 */

#include <windows.h>
#include <processthreadsapi.h>
#include <stdio.h>
#include "util.h"

bool open_app(char *fullExePath) {
	STARTUPINFO si = {0};
	PROCESS_INFORMATION pi = {0};
	si.cb = sizeof(si);

	BOOL ret = CreateProcess(
		fullExePath,
		"",
		NULL,
		NULL,
		FALSE,
		0,
		NULL,
		NULL,
		&si,
		&pi
	);

	if (!ret) return false;

	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);

	return true;
}
