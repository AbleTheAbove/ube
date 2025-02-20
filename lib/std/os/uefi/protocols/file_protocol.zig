// SPDX-License-Identifier: MIT
// Copyright (c) 2015-2020 Zig Contributors
// This file is part of [zig](https://ziglang.org/), which is MIT licensed.
// The MIT license requires this copyright notice to be included in all copies
// and substantial portions of the software.
const uefi = @import("std").os.uefi;
const Guid = uefi.Guid;
const Time = uefi.Time;
const Status = uefi.Status;

pub const FileProtocol = extern struct {
    revision: u64,
    _open: fn (*const FileProtocol, **const FileProtocol, [*:0]const u16, u64, u64) callconv(.C) Status,
    _close: fn (*const FileProtocol) callconv(.C) Status,
    _delete: fn (*const FileProtocol) callconv(.C) Status,
    _read: fn (*const FileProtocol, *usize, [*]u8) callconv(.C) Status,
    _write: fn (*const FileProtocol, *usize, [*]const u8) callconv(.C) Status,
    _get_position: fn (*const FileProtocol, *u64) callconv(.C) Status,
    _set_position: fn (*const FileProtocol, *const u64) callconv(.C) Status,
    _get_info: fn (*const FileProtocol, *align(8) const Guid, *const usize, [*]u8) callconv(.C) Status,
    _set_info: fn (*const FileProtocol, *align(8) const Guid, usize, [*]const u8) callconv(.C) Status,
    _flush: fn (*const FileProtocol) callconv(.C) Status,

    pub fn open(self: *const FileProtocol, new_handle: **const FileProtocol, file_name: [*:0]const u16, open_mode: u64, attributes: u64) Status {
                     return self._open(self, new_handle, file_name, open_mode, attributes);
    }

    pub fn close(self: *const FileProtocol) Status {
                     return self._close(self);
    }

    pub fn delete(self: *const FileProtocol) Status {
                     return self._delete(self);
    }

    pub fn read(self: *const FileProtocol, buffer_size: *usize, buffer: [*]u8) Status {
                     return self._read(self, buffer_size, buffer);
    }

    pub fn write(self: *const FileProtocol, buffer_size: *usize, buffer: [*]const u8) Status {
                     return self._write(self, buffer_size, buffer);
    }

    pub fn get_info(self: *const FileProtocol, information_type: *align(8) Guid, buffer_size: *usize, buffer: [*]u8) Status {
                     return self._get_info(self, information_type, buffer_size, buffer);
    }

    pub fn set_info(self: *const FileProtocol, information_type: *align(8) Guid, buffer_size: usize, buffer: [*]const u8) Status {
                     return self._set_info(self, information_type, buffer_size, buffer);
    }

    pub fn flush(self: *const FileProtocol) Status {
                     return self._flush(self);
    }

    pub const guid align(8) = Guid{
                     .time_low = 0x09576e92,
                     .time_mid = 0x6d3f,
                     .time_high_and_version = 0x11d2,
                     .clock_seq_high_and_reserved = 0x8e,
                     .clock_seq_low = 0x39,
                     .node = [_]u8{ 0x00, 0xa0, 0xc9, 0x69, 0x72, 0x3b },
    };

    pub const efi_file_mode_read: u64 = 0x0000000000000001;
    pub const efi_file_mode_write: u64 = 0x0000000000000002;
    pub const efi_file_mode_create: u64 = 0x8000000000000000;

    pub const efi_file_read_only: u64 = 0x0000000000000001;
    pub const efi_file_hidden: u64 = 0x0000000000000002;
    pub const efi_file_system: u64 = 0x0000000000000004;
    pub const efi_file_reserved: u64 = 0x0000000000000008;
    pub const efi_file_directory: u64 = 0x0000000000000010;
    pub const efi_file_archive: u64 = 0x0000000000000020;
    pub const efi_file_valid_attr: u64 = 0x0000000000000037;
};

pub const FileInfo = extern struct {
    size: u64,
    file_size: u64,
    physical_size: u64,
    create_time: Time,
    last_access_time: Time,
    modification_time: Time,
    attribute: u64,

    pub fn getFileName(self: *const FileInfo) [*:0]const u16 {
                     return @ptrCast([*:0]const u16, @ptrCast([*]const u8, self) + @sizeOf(FileInfo));
    }

    pub const efi_file_read_only: u64 = 0x0000000000000001;
    pub const efi_file_hidden: u64 = 0x0000000000000002;
    pub const efi_file_system: u64 = 0x0000000000000004;
    pub const efi_file_reserved: u64 = 0x0000000000000008;
    pub const efi_file_directory: u64 = 0x0000000000000010;
    pub const efi_file_archive: u64 = 0x0000000000000020;
    pub const efi_file_valid_attr: u64 = 0x0000000000000037;
};
