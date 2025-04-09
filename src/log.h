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

#ifndef XENO_DSR_GADGET_LOADER_LOG_H_
#define XENO_DSR_GADGET_LOADER_LOG_H_

#include <stdint.h>
#include <string.h>

void open_console(void);

void log_init(void);
void _log_error(const char *file, size_t filelen, const char *func, size_t funclen, uint64_t line, const char *fmt, ...);
void _log_info (const char *file, size_t filelen, const char *func, size_t funclen, uint64_t line, const char *fmt, ...);
void _log_warn (const char *file, size_t filelen, const char *func, size_t funclen, uint64_t line, const char *fmt, ...);

#define LOG_ERROR(fmt, ...) { _log_error(__FILE__, strlen(__FILE__), __func__, strlen(__func__), __LINE__, fmt, __VA_ARGS__);}
#define LOG_INFO(fmt, ...) { _log_info (__FILE__, strlen(__FILE__), __func__, strlen(__func__), __LINE__, fmt, __VA_ARGS__);}
#define LOG_WARN(fmt, ...) { _log_warn (__FILE__, strlen(__FILE__), __func__, strlen(__func__), __LINE__, fmt, __VA_ARGS__);}

#endif // XENO_DSR_GADGET_LOADER_LOG_H_
