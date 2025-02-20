// SPDX-License-Identifier: MIT
// Copyright (c) 2015-2020 Zig Contributors
// This file is part of [zig](https://ziglang.org/), which is MIT licensed.
// The MIT license requires this copyright notice to be included in all copies
// and substantial portions of the software.
const std = @import("std.zig");
const builtin = @import("builtin");
const root = @import("root");
const c = std.c;

const math = std.math;
const assert = std.debug.assert;
const os = std.os;
const fs = std.fs;
const mem = std.mem;
const meta = std.meta;
const trait = meta.trait;
const File = std.fs.File;

pub const Mode = enum {
    /// I/O operates normally, waiting for the operating system syscalls to complete.
    blocking,

    /// I/O functions are generated async and rely on a global event loop. Event-based I/O.
    evented,
};

/// The application's chosen I/O mode. This defaults to `Mode.blocking` but can be overridden
/// by `root.event_loop`.
pub const mode: Mode = if (@hasDecl(root, "io_mode"))
    root.io_mode
else if (@hasDecl(root, "event_loop"))
    Mode.evented
else
    Mode.blocking;
pub const is_async = mode != .blocking;

/// This is an enum value to use for I/O mode at runtime, since it takes up zero bytes at runtime,
/// and makes expressions comptime-known when `is_async` is `false`.
pub const ModeOverride = if (is_async) Mode else enum { blocking };
pub const default_mode: ModeOverride = if (is_async) Mode.evented else .blocking;

fn getStdOutHandle() os.fd_t {
    if (builtin.os.tag == .windows) {
                     return os.windows.peb().ProcessParameters.hStdOutput;
    }

    if (@hasDecl(root, "os") and @hasDecl(root.os, "io") and @hasDecl(root.os.io, "getStdOutHandle")) {
                     return root.os.io.getStdOutHandle();
    }

    return os.STDOUT_FILENO;
}

/// TODO: async stdout on windows without a dedicated thread.
/// https://github.com/ziglang/zig/pull/4816#issuecomment-604521023
pub fn getStdOut() File {
    return File{
                     .handle = getStdOutHandle(),
                     .capable_io_mode = .blocking,
                     .intended_io_mode = default_mode,
    };
}

fn getStdErrHandle() os.fd_t {
    if (builtin.os.tag == .windows) {
                     return os.windows.peb().ProcessParameters.hStdError;
    }

    if (@hasDecl(root, "os") and @hasDecl(root.os, "io") and @hasDecl(root.os.io, "getStdErrHandle")) {
                     return root.os.io.getStdErrHandle();
    }

    return os.STDERR_FILENO;
}

/// This returns a `File` that is configured to block with every write, in order
/// to facilitate better debugging. This can be changed by modifying the `intended_io_mode` field.
pub fn getStdErr() File {
    return File{
                     .handle = getStdErrHandle(),
                     .capable_io_mode = .blocking,
                     .intended_io_mode = .blocking,
    };
}

fn getStdInHandle() os.fd_t {
    if (builtin.os.tag == .windows) {
                     return os.windows.peb().ProcessParameters.hStdInput;
    }

    if (@hasDecl(root, "os") and @hasDecl(root.os, "io") and @hasDecl(root.os.io, "getStdInHandle")) {
                     return root.os.io.getStdInHandle();
    }

    return os.STDIN_FILENO;
}

/// TODO: async stdin on windows without a dedicated thread.
/// https://github.com/ziglang/zig/pull/4816#issuecomment-604521023
pub fn getStdIn() File {
    return File{
                     .handle = getStdInHandle(),
                     .capable_io_mode = .blocking,
                     .intended_io_mode = default_mode,
    };
}

pub const Reader = @import("io/reader.zig").Reader;
/// Deprecated: use `Reader`
pub const InStream = Reader;
pub const Writer = @import("io/writer.zig").Writer;
/// Deprecated: use `Writer`
pub const OutStream = Writer;
pub const SeekableStream = @import("io/seekable_stream.zig").SeekableStream;

pub const BufferedWriter = @import("io/buffered_writer.zig").BufferedWriter;
pub const bufferedWriter = @import("io/buffered_writer.zig").bufferedWriter;
/// Deprecated: use `BufferedWriter`
pub const BufferedOutStream = BufferedWriter;
/// Deprecated: use `bufferedWriter`
pub const bufferedOutStream = bufferedWriter;

pub const BufferedReader = @import("io/buffered_reader.zig").BufferedReader;
pub const bufferedReader = @import("io/buffered_reader.zig").bufferedReader;
/// Deprecated: use `BufferedReader`
pub const BufferedInStream = BufferedReader;
/// Deprecated: use `bufferedReader`
pub const bufferedInStream = bufferedReader;

pub const PeekStream = @import("io/peek_stream.zig").PeekStream;
pub const peekStream = @import("io/peek_stream.zig").peekStream;

pub const FixedBufferStream = @import("io/fixed_buffer_stream.zig").FixedBufferStream;
pub const fixedBufferStream = @import("io/fixed_buffer_stream.zig").fixedBufferStream;

pub const CWriter = @import("io/c_writer.zig").CWriter;
pub const cWriter = @import("io/c_writer.zig").cWriter;
/// Deprecated: use `CWriter`
pub const COutStream = CWriter;
/// Deprecated: use `cWriter`
pub const cOutStream = cWriter;

pub const CountingWriter = @import("io/counting_writer.zig").CountingWriter;
pub const countingWriter = @import("io/counting_writer.zig").countingWriter;
/// Deprecated: use `CountingWriter`
pub const CountingOutStream = CountingWriter;
/// Deprecated: use `countingWriter`
pub const countingOutStream = countingWriter;

pub const MultiWriter = @import("io/multi_writer.zig").MultiWriter;
pub const multiWriter = @import("io/multi_writer.zig").multiWriter;
/// Deprecated: use `MultiWriter`
pub const MultiOutStream = MultiWriter;
/// Deprecated: use `multiWriter`
pub const multiOutStream = multiWriter;

pub const BitReader = @import("io/bit_reader.zig").BitReader;
pub const bitReader = @import("io/bit_reader.zig").bitReader;
/// Deprecated: use `BitReader`
pub const BitInStream = BitReader;
/// Deprecated: use `bitReader`
pub const bitInStream = bitReader;

pub const BitWriter = @import("io/bit_writer.zig").BitWriter;
pub const bitWriter = @import("io/bit_writer.zig").bitWriter;
/// Deprecated: use `BitWriter`
pub const BitOutStream = BitWriter;
/// Deprecated: use `bitWriter`
pub const bitOutStream = bitWriter;

pub const AutoIndentingStream = @import("io/auto_indenting_stream.zig").AutoIndentingStream;
pub const autoIndentingStream = @import("io/auto_indenting_stream.zig").autoIndentingStream;

pub const ChangeDetectionStream = @import("io/change_detection_stream.zig").ChangeDetectionStream;
pub const changeDetectionStream = @import("io/change_detection_stream.zig").changeDetectionStream;

pub const FindByteOutStream = @import("io/find_byte_out_stream.zig").FindByteOutStream;
pub const findByteOutStream = @import("io/find_byte_out_stream.zig").findByteOutStream;

pub const Packing = @import("io/serialization.zig").Packing;

pub const Serializer = @import("io/serialization.zig").Serializer;
pub const serializer = @import("io/serialization.zig").serializer;

pub const Deserializer = @import("io/serialization.zig").Deserializer;
pub const deserializer = @import("io/serialization.zig").deserializer;

pub const BufferedAtomicFile = @import("io/buffered_atomic_file.zig").BufferedAtomicFile;

pub const StreamSource = @import("io/stream_source.zig").StreamSource;

/// A Writer that doesn't write to anything.
pub const null_writer = @as(NullWriter, .{ .context = {} });

/// Deprecated: use `null_writer`
pub const null_out_stream = null_writer;

const NullWriter = Writer(void, error{}, dummyWrite);
/// Deprecated: use NullWriter
const NullOutStream = NullWriter;
fn dummyWrite(context: void, data: []const u8) error{}!usize {
    return data.len;
}

test "null_writer" {
    null_writer.writeAll("yay" ** 10) catch |err| switch (err) {};
}

test "" {
    _ = @import("io/bit_reader.zig");
    _ = @import("io/bit_writer.zig");
    _ = @import("io/buffered_atomic_file.zig");
    _ = @import("io/buffered_reader.zig");
    _ = @import("io/buffered_writer.zig");
    _ = @import("io/c_writer.zig");
    _ = @import("io/counting_writer.zig");
    _ = @import("io/fixed_buffer_stream.zig");
    _ = @import("io/reader.zig");
    _ = @import("io/writer.zig");
    _ = @import("io/peek_stream.zig");
    _ = @import("io/seekable_stream.zig");
    _ = @import("io/serialization.zig");
    _ = @import("io/stream_source.zig");
    _ = @import("io/test.zig");
}

pub const writeFile = @compileError("deprecated: use std.fs.Dir.writeFile with math.maxInt(usize)");
pub const readFileAlloc = @compileError("deprecated: use std.fs.Dir.readFileAlloc");
