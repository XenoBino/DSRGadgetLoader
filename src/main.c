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

#include <string.h>
#include <sys/stat.h>
#include <string.h>
#include <libgen.h>
#include "util.h"
#include <windows.h>
#include "log.h"

// From https://stackoverflow.com/questions/3828835/how-can-we-check-if-a-file-exists-or-not-using-win32-program
BOOL FileExists(LPCTSTR szPath)
{
  DWORD dwAttrib = GetFileAttributes(szPath);

  return (dwAttrib != INVALID_FILE_ATTRIBUTES &&
         !(dwAttrib & FILE_ATTRIBUTE_DIRECTORY));
}

int mod_main(void) {
	log_init();
	LOG_INFO("Initializing DSRGadgetLoader.dll%s\n", "");

	char buf[4096] = {0};
	getcwd(buf, 4096);
	strcpy(&buf[strlen(buf)], "\\DSR Gadget 1.6\\DSR-Gadget.exe");
	if (!FileExists(buf)) {
		LOG_ERROR("%s: File not found\n", buf);
		return 1;
	}
	LOG_INFO("Found %s\n", buf);

	char *_file = strdup(buf);
	char *base = basename(_file);
	if (!open_app(buf)) {
		LOG_ERROR("Failed to launch %s\n", base);
		return 1;
	}

	LOG_INFO("%s Launched!\n", base);
	return 0;
}
