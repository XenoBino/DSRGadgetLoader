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

#include "log.h"
#include <windows.h>
#include <stdio.h>
#include <libgen.h>
#include <stdarg.h>
#include <time.h>

char *time_buffer = NULL;

void log_init() {
	if (time_buffer) return;
	open_console();
	time_buffer = malloc(4096);
	if (!time_buffer) return;
}

void open_console(void) {
//#ifdef XENO_DSR_GADGET_LOADER_DEBUG
	if (!AllocConsole())
		return;

	FILE *f;
	freopen_s(&f, "CONOUT$", "w", stdout);
	freopen_s(&f, "CONOUT$", "w", stderr);
	freopen_s(&f, "CONIN$", "r", stdin);

	//HANDLE hConOut = CreateFile(_T("CONOUT$"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	//HANDLE hConIn = CreateFile(_T("CONIN$"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	//SetStdHandle(STD_OUTPUT_HANDLE, hConOut);
	//SetStdHandle(STD_ERROR_HANDLE, hConOut);
	//SetStdHandle(STD_INPUT_HANDLE, hConIn);
//#endif // XENO_DSR_GADGET_LOADER_DEBUG
}

char *get_timestamp(void) {
	time_t t = time(0);
	struct tm *tmp = localtime(&t);

	if (!strftime(time_buffer, 4095, "%a %d %b %Y %H:%M:%S", tmp))
		return NULL;

	return time_buffer;
}

void _log_error(const char *_file, size_t filelen, const char *func, size_t funclen, uint64_t line, const char *fmt, ...) {
	char *file = strdup(_file);
	const char *base = basename(file);
	get_timestamp();

	fprintf(stderr, "[%s]: %s (%s:%llu): ", time_buffer, base, func, line);
	va_list list;
	va_start(list, fmt);
	vfprintf(stderr, fmt, list);
	va_end(list);
	free(file);
}

void _log_info (const char *_file, size_t filelen, const char *func, size_t funclen, uint64_t line, const char *fmt, ...) {
	char *file = strdup(_file);
	const char *base = basename(file);
	get_timestamp();

	fprintf(stderr, "[%s]: %s (%s:%llu): ", time_buffer, base, func, line);
	va_list list;
	va_start(list, fmt);
	vfprintf(stderr, fmt, list);
	va_end(list);
	free(file);

}
void _log_warn (const char *_file, size_t filelen, const char *func, size_t funclen, uint64_t line, const char *fmt, ...) {
	char *file = strdup(_file);
	const char *base = basename(file);
	get_timestamp();

	fprintf(stderr, "[%s]: %s (%s:%llu): ", time_buffer, base, func, line);
	va_list list;
	va_start(list, fmt);
	vfprintf(stderr, fmt, list);
	va_end(list);
	free(file);
}
